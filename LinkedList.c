#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define HASH_SIZE 8

int compare_hashes(unsigned char* a, unsigned char* b) {
	// iterate through each byte of the char array
	for (int i = 0; i < HASH_SIZE; i++) {
		// check if the element in a is not equal to the element in b at the same index
		if (a[i] != b[i]) {
			return 1;
		}
	}
	return 0;
}

void compute_hash(char* command, unsigned char* prev_hash, unsigned char* output) {
	unsigned char* data = (unsigned char*)command;
	int len = strlen(command);
	unsigned long long h = 0;
	
	// Store prev_hash in h to perform operations
	for (int i = 0; i < HASH_SIZE; i++) {
		h = (h << 8) | prev_hash[i];
	}

	// Mix data
	for (int i = 0; i < len; i++) {
		h ^= data[i];
		h = (h << 5) | (h >> (64 - 5));
		h &= ~(h >> 1);
		h |= (h << 1);
	}

	h = ~h;

	// Output
	for (int i = HASH_SIZE - 1; i >= 0; i--) {
		output[i] = (unsigned char)(h & 0xFF); // extracting one byte from the right of h and inserting that at the left-most position of the output array
		h >>= 8; // shifting the right-most 8 bits to the right, essentially deleting them, putting the next byte into place
	}
}

void initialize(struct LinkedList* list) {
	list->size = 0;
	list->head = NULL;
}

void add_node(struct LinkedList* list, char* command) {
	struct node* newNode = malloc(sizeof(struct node));
	strcpy(newNode->data, command);
	newNode->next = NULL;
	unsigned char prev_hash[HASH_SIZE];
	struct node* tail = list->head;
	
	// base case - if there's no tail then set the previous hash to zero
	if (tail == NULL) {
		for (int i = 0; i < HASH_SIZE; i++) {
			prev_hash[i] = 0;
		}
	}
	
	// otherwise, go to the end of the list and copy its hash into prev_hash
	else {
		while (tail->next != NULL) {
			tail = tail->next;
		}
		for (int i = 0; i < HASH_SIZE; i++) {
			prev_hash[i] = tail->hash[i];
		}
	}
	
	// create a new hash for the latest node in the list
	compute_hash(command, prev_hash, newNode->hash);
	
	if (list->head == NULL) {
		list->head = newNode;
	}
	
	else {
		tail->next = newNode;
	}
	list->size++;
}

void print_list(struct LinkedList* list) {
	struct node* temp = list->head;
	int i = 1;
	
	if (temp == NULL) {
		printf("Command history is currently empty...\n");
		return;
	}
	
	while (temp != NULL) {
		printf("%d - %s\n", i, temp->data);
		temp = temp->next;
		i++;
	}
}

void print_hash(unsigned char* hash) {
	for (int i = 0; i < HASH_SIZE; i++) {
		printf("%02x", hash[i]);
	}
}

char* validate(struct LinkedList* list) {
	char* output = malloc(sizeof(char) * 1000);
	strcpy(output, "");
	
	// base case - if there is no head, return
	if (list->head == NULL) {
		return output;
	}
	
	unsigned char recomputed[HASH_SIZE];
	unsigned char zero_hash[HASH_SIZE];
	
	// create a zero'ed out hash
	for (int i = 0; i < HASH_SIZE; i++) {
		zero_hash[i] = 0;
	}
	
	// the prev_hash of the head is always zero
	compute_hash(list->head->data, zero_hash, recomputed);
	
	// check if there's an alteration in the head node
	if (compare_hashes(recomputed, list->head->hash) != 0) {
		char temp[400] = "A node has been deleted or altered: ";
		strcat(temp, list->head->data);
		strcat(temp, "\n");
		strcat(output, temp);
	}
	
	struct node* current = list->head;
	
	// iterate through the other nodes and check for alterations
	while (current->next != NULL) {
		compute_hash(current->next->data, current->hash, recomputed);
		
		if (compare_hashes(recomputed, current->next->hash) != 0) {
			char temp[400] = "A node has been deleted or altered: ";
			strcat(temp, current->next->data);
			strcat(temp, "\n");
			strcat(output, temp);
		}
		
		current = current->next;
	}

	return output;
}

void modify_node(struct LinkedList* list, int index, char* new_data) {
	struct node* current = list->head;
	
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	
	strcpy(current->data, new_data);
}

void delete_node(struct LinkedList* list, int index) {
	struct node* temp = list->head;
	struct node* prev = NULL;
	
	for (int i = 0; i < index; i++) {
		prev = temp;
		temp = temp->next;
	}
	
	if (prev == NULL) {
		list->head = temp->next;
	}
	
	else {
		prev->next = temp->next;
	}
	
	free(temp);
	list->size--;
}

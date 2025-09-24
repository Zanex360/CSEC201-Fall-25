#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void initialize(struct LinkedList* list) {
	list->size = 0;
	list->head = NULL;
}

void addNode(struct LinkedList* list, char* command) {
	struct node* newNode = malloc(sizeof(struct node));

	strcpy(newNode->data, command);

	newNode->next = list->head;
	list->head = newNode;
	list->size++;
}

void printList(struct LinkedList* list) {
	struct node* temp = list->head;
	if (temp == NULL) {
		printf("Command history is currently empty...\n");
		return;
	}
	while (temp != NULL) {
		printf("%s\n", temp->data);
		temp = temp->next;
	}
}


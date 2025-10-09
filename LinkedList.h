#pragma once
#define HASH_SIZE 8

struct node {
	char data[100];
	unsigned char hash[HASH_SIZE];
	struct node* next;
};

struct LinkedList {
	int size;
	struct node* head;
};

void initialize(struct LinkedList* list);
void add_node(struct LinkedList* list, char* data);
void print_list(struct LinkedList* list);
char *validate(struct LinkedList* list);
void print_hash(const unsigned char* hash);
void modify_node(struct LinkedList* list, int index, char* new_data);
void delete_node(struct LinkedList* list, int index);
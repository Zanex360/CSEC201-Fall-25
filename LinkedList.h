#pragma once

struct node {
	char data[100];
	struct node* next;
};

struct LinkedList {
	int size;
	struct node* head;
};

void initialize(struct LinkedList* list);

void addNode(struct LinkedList* list, char* data);

void printList(struct LinkedList* list);
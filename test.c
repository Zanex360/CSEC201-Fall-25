#include <stdio.h>
#include "LinkedList.h"

int main() {
	struct LinkedList list;
	
	initialize(&list);
	
	add_node(&list, "command1");
	add_node(&list, "command2");
	add_node(&list, "command3");
	validate(&list); // No output expected

	struct node* temp = list.head;
	int i = 1;

	while (temp != NULL) {
		printf("Command %d: data(%s)", i, temp->data);
		printf(" hash(");
		print_hash(temp->hash);
		printf(")\n");
		temp = temp->next;
		i++;
	}
	
	printf("\n");

	modify_node(&list, 1, "altered");
	validate(&list); // Should output "altered"
	
	printf("\n");

	temp = list.head;
	i = 1;
	while (temp != NULL) {
		printf("Command %d: data(%s)", i, temp->data);
		printf(" hash(");
		print_hash(temp->hash);
		printf(")\n");
		temp = temp->next;
		i++;
	}
	
	printf("\n");
	
	delete_node(&list, 1);
	validate(&list); // Should output "command1" or "altered" depending on break in chain
	
	printf("\n");
	
	temp = list.head;
	i = 1;
	while (temp != NULL) {
		printf("Command %d: data(%s)", i, temp->data);
		printf(" hash(");
		print_hash(temp->hash);
		printf(")\n");
		temp = temp->next;
		i++;
	}
	
	return 0;
}
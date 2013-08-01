#ifndef LIST_H
#define LIST_H

typedef struct Item{
	char *string;
	struct Item *next;
} Item;
void *pushItem(Item *head, char *instr);
void printList(Item *head);
int noOfItems(Item *head);
void deleteLast(Item *head);
#endif


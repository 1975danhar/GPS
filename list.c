#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"list.h"

void *pushItem(Item *head, char *instr)
{
	Item *tmp;
	if(noOfItems(head)>100)
		deleteLast(head);
	if(head==NULL){
		head = malloc(sizeof(Item));
		head->string = malloc(strlen(instr)+1);
		strcpy(head->string, instr);
		head->next = NULL;
		return head;
	}

	tmp = malloc(sizeof(Item));
	tmp->string = malloc(strlen(instr)+1);
	strcpy(tmp->string, instr);
	tmp->next = head;
	
	return tmp;
}

void printList(Item *head)
{
	int i=0;
	while(head != NULL){
		printf("%d: %s", i++, head->string);
		head = head->next;
	}
}

int noOfItems(Item *head)
{
	int i=0;
	if(head!=NULL)
	while(head->next != NULL){
		i++;
		head = head->next;
	}
	return i;
}

void deleteLast(Item *head)
{
	while((head->next)->next!=NULL)
		head=head->next;
	free(head->next);
	head->next=NULL;
}


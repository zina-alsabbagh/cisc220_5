# Rita Alsattah 10154610
# Zina Al-Sabbagh 10161380

#include <stdio.h>
#include "udll.h"
#include <stdlib.h>
#include <math.h>

struct node *head;

void head() {
	head->length = 0;
	head->next = NULL;
}

struct node *tail;

void tail() {
	tail->previous = head;
	tail->next = NULL;
	head->next = tail;
}

void insert (int index, union Data data) {

	struct node *ctr;
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = data;

	if ( index < (*head).length / 2)  {

		if ( index == 1 ) {
			newNode->next = head->next;
			head->next = newNode;
		}	

		if ( index > 1 ) {
			int x = 0;
			ctr = head;
			while ( (ctr->next != NULL) && ( x < (index-1) ) ) {
				ctr = ctr->next;
				x++;
			}
			newNode->next = ctr->next;
			newNode->previous = ctr;
			ctr->next = newNode;
			ctr = newNode->next;
			ctr->previous = newNode;
		}
	}
	else {
	
		if ( index == ((*head).length) ) {
			newNode->previous = tail->previous;
			tail->previous = ctr;
			ctr->next = newNode;
			tail->previous = newNode;
			newNode->next = tail;
		}

		int newIndex = (*head).length - index;
		int y =0;
		ctr = tail;
		while ( (ctr->previous != NULL) && (y < newIndex) ) {
			ctr = ctr->previous;
			y++;
		}

		newNode->previous = ctr->previous;
		newNode->next = ctr;
		ctr->previous = newNode;
		ctr = newNode->previous;
		ctr->next = newNode;

	}

	head -> length = ((*head).length + 1);
}

union Data get(int index){
	int count = 0;
	if ( index < (*head).length / 2)  {
		struct node* current = head;
		while (current != NULL){
			if ( count = index )
				return(current->val);
			count++;
			current = current->next;
	        }
	} 
	else{
		struct node* current = tail;
		int newIndex = (*head).length - index;
		while (current->previous != NULL && (count< newIndex) ){
			if ( count = index ) 
				return(current->val);
			count++;
			current = current->next;
		}
	}
}

void remove(int index){
	int i = 0;
	struct node *ptr = head;
	struct node *p2 = NULL;

	if (index < (*head).length /2){
		while(i<(index-1)&&(ptr->next != NULL)){
			ptr = ptr->next;
			i++;
		}
	p2 = ptr->next;
	ptr->next = p2->next;
	
	}
 
	else{
		int newIndex = (*head).length - index;
		while(i < (newIndex+1)&&(ptr->previous != NULL)){
			ptr = ptr -> previous;
			i++;
		}
		p2 = ptr->previous;
		ptr->previous = p2->previous;
		
		}
	free(p2);
	head -> length = ((*head).length + 1);
}

int length(){
	return (*head).length;
}
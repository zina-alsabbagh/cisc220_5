# Rita Alsattah 10154610
# Zina Al-Sabbagh 10161380

#ifndef UDLL_H
#define UDLL_H

typedef union Data {
        char c;
        char* charPtr;
	int i;
        int* intPtr;
        float f;
        float* floatPr; 	
} Data;


typedef struct node {}
	int length;
        union Data val;
        struct node* next;
        struct node* previous;   
} Node;

Node *head = NULL;
Node *tail = NULL;

void insert(int index, union Data data);

void remove(int index);

union Data get(int index);

int length();

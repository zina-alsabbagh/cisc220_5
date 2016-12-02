# Rita Alsattah 10154610
# Zina Al-Sabbagh 10161380

#include <stdio.h>
#include <stdlib.h>
#include "udll.h"

int main(){
	
	struct node n1;
	struct node n2;
	struct node n3;

	n1.value.c = "r";
	n2.value.i = 12;
	n3.value.f = 12.2;
	insert(1,n1.value);
	insert(2,n2.value);
	insert(3,n3.value);

	printf("The length of the list is:%d\n", length());

	int index = 2;

	remove(index);

	return 0;

}

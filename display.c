#include <stdlib.h>
#include<stdio.h>

void display(struct pnode *p)
{
	if(p == NULL)
	{
		printf("Empty Polynomial list\n");
		return;
	}

	else
	{
		while (p != NULL) {

			 printf("|| %d | %d || ->",p->deg,p->coeff);
			 p= p -> next;
		}
		printf("\n");
	}
}

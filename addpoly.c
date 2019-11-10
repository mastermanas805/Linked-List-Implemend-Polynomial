#include <stdlib.h>
#include<stdio.h>

#include "checknull.c"
struct pnode *addpoly(struct pnode *p1, struct pnode *p2)
{
	int x;
	struct pnode *temp,*p3;
	sum = p3;

	//Check if any passed list is empty
	if(p1 == NULL && p2 == NULL)
	{
		printf("Empty lists passed\n");
		return temp;
	}

	if(p1 == NULL)
	{
		while(p2 != NULL)
		{
			p3 = (struct pnode *)malloc(sizeof(struct pnode));
			p3->next = NULL;

			p3->deg = p2->deg;
			p3->coeff = p2->coeff;

			p3 = p3->next;
		}
	}

	else if(p2 == NULL)
	{
		while(p2 != NULL)
		{
			p3 = (struct pnode *)malloc(sizeof(struct pnode));
			p3->next = NULL;

			p3->deg = p1->deg;
			p3->coeff = p1->coeff;

			p3 = p3->next;
		}
	}

	else
	{
		while(p1 != NULL && p2 != NULL)
		{
			p3 = (struct pnode *)malloc(sizeof(struct pnode));
			p3->next = NULL;

			if(p1->deg == p2->deg)
			{
				p3->deg = p1->deg;
				p3->coeff = p1->coeff + p2->coeff;

				p1 = p1->next;
				p2 = p2->next;
			}

			else if( p1->deg > p2->deg)
			{
				p3->deg = p2->deg;
				p3->coeff = p2->coeff;

				p2 = p2->next;
			}

			else if( p1->deg < p2->deg)
			{
				p3->deg = p1->deg;
				p3->coeff = p1->coeff;

				p1 = p1->next;
			}


			p3 = p3->next;
		}
//Check if any list is left
	 x = checknull(p1,p2);

	 if(x == 1)
	   temp = p1;
	 else
	   temp = p2;


	 if( x == 0 )
	 {
		 return;
	 }

	 else
	 {
		 while(temp != NULL)
		 {
			 p3 = (struct pnode *)malloc(sizeof(struct pnode));
 			 p3->next = NULL;

			 p3->deg = temp->deg;
			 p3->coeff = temp->coeff;

			 p3 = p3->next;

		 }
	 }

	}
	return p3;
}

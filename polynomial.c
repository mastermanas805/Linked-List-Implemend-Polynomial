#include <stdlib.h>
#include<stdio.h>
struct pnode
{
	int deg;
	float coeff;

	struct pnode *next;
};

struct pnode *p1,*p2,*sum;

struct pnode *insert_poly(struct pnode *ptr)
 {
  int deg,coeff;
  struct pnode *sptr,*fptr,*temp,*p;

  printf("Enter the Degree: \n");
  scanf("%d",&deg);
  printf("Enter the Coeff:\n");
  scanf("%d",&coeff );

	p = ptr;

//Check if the given list is empty
  if(ptr == NULL)
  {
    p = (struct pnode *)malloc(sizeof(struct pnode));
		ptr = p;
    p->deg = deg;
    p->coeff = coeff;
    p->next = NULL;
  }

  else
  {
    sptr = p;
    fptr = sptr->next;

    while(fptr!= NULL)
    {
			//If the given degree alredy exists
      if(fptr->deg == deg)
      {
        fptr->coeff +=coeff;
				return ptr;
      }
      //If the degree greater than given degree exists
			else if(fptr->deg > deg)
			{
           temp = (struct pnode *)malloc(sizeof(struct pnode));

					 temp->deg = deg;
					 temp->coeff = coeff;

					 temp->next = fptr;
					 sptr->next = temp;

					 return ptr;
			}

			else
			{
				temp = (struct pnode *)malloc(sizeof(struct pnode));

				temp->deg = deg;
				temp->coeff = coeff;
			  fptr->next = temp;
				return ptr;
			}

      sptr = sptr->next;
      fptr = fptr->next;
    }
  }
 return ptr;
}


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

			 printf("|| %d | %d || ->\n",p->deg,p->coeff);
			 p= p -> next;
		}
	}
}

void addpoly(struct pnode *p1, struct pnode *p2)
{
	int x;
	struct pnode *temp,*p3;
	sum = p3;

	//Check if any passed list is empty
	if(p1 == NULL && p2 == NULL)
	{
		printf("Empty lists passed\n");
		return;
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
}

int checknull(struct pnode *p1, struct pnode *p2)
{
	if(p1 == NULL && p2==NULL)
	{
		return 0;
	}

	if(p1 == NULL)
	{
		return 2;
	}

	if(p2 == NULL)
	{
		return 1;
	}
}

void main()
{
	 int choice=-1,x,temp,choice1=-1,pow,coeff;

 while(choice !=0)
 {
	 system("cls");
	 printf("\n 0. Exit\n");
	 printf("1. Display\n\n");
	 printf("2. Insert polynomial\n");
	 printf("3. Add Polynomials\n");
	 scanf("%d",&choice);
	 switch(choice)
	 {
		 case 0:
					{
					 break;
					}
		 case 1:
			 {
				 printf("First Polynomial List is :");
			   display(p1);

				 printf("Second Polynomial List is :");
			   display(p2);

				 printf("Sum Polynomial List P1 & P2 is :");
			   display(sum);
			 break;
			 }
		 case 2: {
			 while(choice1 !=0)
   {
	    system("cls");
	    printf("\n 0. Exit\n");
	    printf("1. Display\n\n");
	    printf("2. Insert into poly 1\n");
	    printf("3. Insert into poly 2\n");
	    scanf("%d",&choice);
	   switch(choice)
	   {
		   case 0:
					{
					 break;
					}
		 case 1:
			 {
				 printf("First polynomial list is:");
				 display(p1);
			 printf("\n");
					p1= insert_poly(p1);
			 display(p1);
						 break;
			 }
		 case 2: {
			 printf("First polynomial list is:");
			 display(p2);
		 printf("\n");
				p2 =  insert_poly(p2);
		 display(p2);			 break;
					}

		 default:
			 {
				 printf("Enter Valid Choice");
			 }
		 }

			 getch();
 }
		break;
					}
		 case 3:
			 {
				 printf("First polynomial list is:");
				 display(p1);
				 printf("Second polynomial list is:");
				 display(p2);
				 printf("Sum polynomial list is:");
				 display(sum);
				 break;
			 }

		 default:
			 {
				 printf("Enter Valid Choice");
			 }
		 }

			 getch();
 }
}

#include <stdlib.h>
#include<stdio.h>

struct pnode *insert_poly(struct pnode *p)
 {
  int deg,coeff;
  struct pnode *sptr,*fptr,*temp;

  printf("Enter the Degree: \n");
  scanf("%d",&deg);
  printf("Enter the Coeff:\n");
  scanf("%d",&coeff );


//Check if the given list is empty
  if(p == NULL)
  {
    p = (struct pnode *)malloc(sizeof(struct pnode));
    p->deg = deg;
    p->coeff = coeff;
    p->next = NULL;
  }
// If only one node exists in the polynomial
  else if( p->next == NULL)
  {
    // Comparing the current node with the new one
    if( p->deg == deg)
    {
      p->coeff += coeff;
    }
    else
    {
      temp = (struct pnode *)malloc(sizeof(struct pnode));
      temp->deg = deg;
      temp->coeff = coeff;

      if( p->deg < deg)
      {
        p->next = temp;
        temp->next = NULL;
      }

      if( p->deg > deg)
      {
        temp->next = p;
        p = temp;
      }
    }
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
				return p;
      }
      //If the degree greater than given degree exists
			else if(fptr->deg > deg)
			{
           temp = (struct pnode *)malloc(sizeof(struct pnode));

					 temp->deg = deg;
					 temp->coeff = coeff;

					 temp->next = fptr;
					 sptr->next = temp;

					 return p;
			}

			else
			{
				temp = (struct pnode *)malloc(sizeof(struct pnode));

				temp->deg = deg;
				temp->coeff = coeff;
			  fptr->next = temp;
				return p;
			}

      sptr = sptr->next;
      fptr = fptr->next;
    }
  }
 return p ;
}

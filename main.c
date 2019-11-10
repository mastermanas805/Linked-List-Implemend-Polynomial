#include <stdlib.h>
#include <stdio.h>
#include "structure.c"
#include "insert_poly.c"
#include "display.c"
#include "addpoly.c"

void main()
{
	 int choice = -1,x,temp,choice1=-1,pow,coeff;

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
	    printf("1. Insert into poly 1\n");
	    printf("2. Insert into poly 2\n");
	    scanf("%d",&choice1);
	   switch(choice1)
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
				p1 =	insert_poly(p1);
			 display(p1);
						 break;
			 }
		 case 2: {
			 printf("First polynomial list is:");
			 display(p2);
		 printf("\n");
			p2 =	insert_poly(p2);
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
				 sum = addpoly(p1,p2);
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

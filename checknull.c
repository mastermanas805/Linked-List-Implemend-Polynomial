#include <stdlib.h>
#include<stdio.h>

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

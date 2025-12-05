/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	if(*head1==NULL && *tail1==NULL)
	{
		return FAILURE;
	} 
	Dlist *temp1= *tail1;
    Dlist *temp2= *tail2;
	Dlist *tempR=*headR;

	int carry=0,res=0;
	while(temp1!=NULL ||temp2!=NULL)
	{
		if(temp1==NULL && temp2!=NULL)
		{
			res=0+temp2->data+carry;
		}
		else if(temp1!=NULL && temp2==NULL)
		{
			res=temp1->data+0+carry;
		}
		else
		{
			res=temp1->data+temp2->data+carry;
		}
	
	  carry=0;
	if(res>9)
	{
		carry=res/10;
		res=res%10;
		insert_at_first(headR,tailR,res);
	}
	else
	{
		insert_at_first(headR,tailR,res);
	}
	if(temp1!=NULL)
	{
		temp1=temp1->prev;
	}
	if(temp2!=NULL)
	{
		temp2=temp2->prev;
	}
	
 }
 if(carry)
	{
		insert_at_first(headR,tailR,carry);
	}
 return SUCCESS;
}
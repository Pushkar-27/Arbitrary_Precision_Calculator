/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
int sign=1;
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)

{
    if(*head1==NULL && *tail1==NULL)
	{
		return FAILURE;
	} 
	  
	  int len1=0,len2=0;
	  Dlist *temp= *head1;
	  while(temp)
	  {
		len1++;
		temp=temp->next;
	  }
	  temp=*head2;
	  while(temp)
	  {
		len2++;
		temp=temp->next;
	  }
	 
      
	  if(len1 < len2)
	  {
		Dlist *h=*head1;
		*head1=*head2;
		*head2=h;

		Dlist *t=*tail1;
		*tail1=*tail2;
		*tail2=t;
		sign=-1;

	  }
	  else if(len1==len2)
	  {
		Dlist *t1=*head1;
		Dlist *t2=*head2;
		while(t1 && t2)
		 {
			if(t1->data > t2->data)
			{
				break;
			}
			else if(t1->data < t2->data)
			{
				Dlist *h=*head1;
				*head1=*head2;
				*head2=h;

				Dlist *t=*tail1;
				*tail1=*tail2;
				*tail2=t;

				sign=-1;
				break;
			}
			  t1=t1->next;
			  t2=t2->next;
		 }
	  }

	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	int borrow=0;
	while(temp1!=NULL)
	{
		int digit1=temp1->data;
		int digit2;
		if(temp2!=NULL)
		{
			digit2=temp2->data;
		}
		else
		{
			digit2=0;
		}
		digit1=digit1-borrow;
		if(digit1<digit2)
		{
			digit1=digit1+10;
			borrow=1;
		}
		else
		{
			borrow=0;
		}
		int res=digit1-digit2;
		insert_at_first(headR,tailR,res);
		temp1=temp1->prev;
		if(temp2!=NULL)
		{
	 		temp2=temp2->prev;
		}
	}	
		while (*headR && (*headR)->data == 0 && (*headR)->next != NULL)
   	   {
    		delete_first(headR, tailR);
   	   } 
 		

   		

        return SUCCESS;
}
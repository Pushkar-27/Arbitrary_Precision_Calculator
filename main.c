/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int main( int argc, char *argv[])
{
    Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL, *tailR=NULL;
    char option, operator;
    int sign1 = 1, sign2 = 1; 
    extern int sign; 
    do
    {
        if (argc < 4)
        {
            printf("error: give correct input \n");
            return FAILURE;
        }

        if (head1) { delete_list(head1); head1 = NULL; tail1 = NULL; }
        if (head2) { delete_list(head2); head2 = NULL; tail2 = NULL; }
        if (headR) { delete_list(headR); headR = NULL; tailR = NULL; }

        insert_element(&head1, &tail1, argv[1], &sign1);
        insert_element(&head2, &tail2, argv[3], &sign2); 
        operator = argv[2][0];
        if (operation_validation(operator) == FAILURE)
        {
            printf("error : Invalid operator\n");
            return FAILURE;
        }
        sign = 1;
        switch (operator)
        {
            case '+':
                if (sign1 == sign2)
                {
                    addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    sign = sign1;
                }
                else
                {
                    if (compare(head1, head2) >= 0)
                    {
                        subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                        sign = sign1;
                    }
                    else
                    {
                        subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                        sign = sign2;
                    }
                }
                break;

            case '-':
                if (sign1 != sign2)
                {
                    addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    sign = sign1; 
                }
                else
                {
                    if (compare(head1, head2) >= 0)
                    {
                        subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                        sign = sign1;
                    }
                    else
                    {
                        subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
                        sign = (sign1 == 1) ? -1 : 1; 
                    }
                }
                break;

            case 'x':
            case '*': 
                multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                sign = (sign1 * sign2);
                break;

            case '/':
        
                division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                sign = (sign1 * sign2);
                break;

            default:
                printf("Invalid Input:-( Try again...\n");
                return FAILURE;
        }
            printf("result :");
            if (sign == -1)
            printf("-");
            print_list(headR);


        delete_list(headR);
        headR = NULL;
        tailR = NULL;

        printf("Want to continue? Press [yY | nN]: ");
        if (scanf("\n%c", &option) != 1) option = 'n';
    } while (option == 'y' || option == 'Y');

    return 0;
}

int operation_validation(char operator)
{
    if (operator!='+' && operator!='-' && operator!='x' &&
        operator!='X' && operator!='*' && operator!='/' )
    {
        printf(" error : Invalid operator");
        return FAILURE;
    }
    return SUCCESS;
}

data_t insert_element(Dlist **head, Dlist **tail, char *argv, int *sign)
{
    int i = 0;

    if (argv == NULL || argv[0] == '\0')
        return FAILURE;
    if (argv[0] == '-')
    {
        *sign = -1;
        i = 1;
    }
    else if (argv[0] == '+')
    {
        *sign = 1;
        i = 1;
    }
    else
    {
        *sign = 1;
        i = 0;
    }
    for (; argv[i] != '\0'; i++)
    {
        if (argv[i] >= '0' && argv[i] <= '9')
        {
            if (insert_at_last(head, tail, argv[i] - '0') == FAILURE)
                return FAILURE;
        }
    }
    if (*head == NULL)
    {
        insert_at_last(head, tail, 0);
    }

    return SUCCESS;
}

data_t insert_at_last(Dlist **head, Dlist **tail, int data)
{
      Dlist *new=malloc(sizeof(Dlist));
	  if(new==NULL)
	  {
		printf("memory allocation is failed");
		return FAILURE;
	  }
	  new->data=data;
	  new->prev=NULL;
	  new->next=NULL;
	  if(*head==NULL && *tail==NULL)
	  {
		*head=new;
		*tail=new;
	  }
	  else
	  {
         new->prev=*tail;
		 (*tail)->next=new;
		 *tail=new;
	  }
	  return SUCCESS;
}
data_t insert_at_first(Dlist **head, Dlist **tail, int data)
{
  Dlist *new=malloc(sizeof(Dlist));
	  if(new==NULL)
	  {
		printf("memory allocation is failed");
		return FAILURE;
	  }
	  new->data=data;
	  new->prev=NULL;
	  new->next=NULL;
	  if(*head==NULL && *tail==NULL)
	  {
		*head=new;
		*tail=new;
	  }
	  else
	  {
		(*head)->prev=new;
		new->next=*head;
		*head=new;
	  }
	  return SUCCESS;

}
int delete_first(Dlist **head, Dlist **tail)
{
   
    if (*head == NULL)
        return FAILURE;

    Dlist *temp = *head;

    
    if (*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
        free(temp);
        return SUCCESS;
    }

   
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(temp);

    return SUCCESS;
}

void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Dlist *temp = head;
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
	
}
void delete_list( Dlist *head )
{
	
     Dlist *temp=head;
   while(temp!=NULL )
   {
     temp=head->next;
     free(head);
     head=temp;
   }
}
int compare(Dlist *head1, Dlist *head2)
{
    if (head1 == NULL && head2 == NULL)
        return 0;

    int len1 = 0, len2 = 0;
    Dlist *temp;

    temp = head1;
    while (temp)
    {
        len1++;
        temp = temp->next;
    }

    temp = head2;
    while (temp)
    {
        len2++;
        temp = temp->next;
    }

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    Dlist *t1 = head1;
    Dlist *t2 = head2;

    while (t1 && t2)
    {
        if (t1->data > t2->data) return 1;
        if (t1->data < t2->data) return -1;

        t1 = t1->next;
        t2 = t2->next;
    }

 	return 0;
}
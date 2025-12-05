/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    delete_list(*headR);
    *headR = NULL;
    *tailR = NULL;
    if (*head2 == NULL)
        return FAILURE;   
    if (compare(*head1, *head2) == -1)
    {
        insert_at_first(headR, tailR, 0);
        return SUCCESS;
    }

    Dlist *h = NULL, *t = NULL;

    Dlist *cur = *head1;

    while (cur)
    {
        insert_at_last(&h, &t, cur->data);
        while (h && h->data == 0 && h->next)
            delete_first(&h, &t);

        int q = 0;
        while (compare(h, *head2) >= 0)
        {
            Dlist *h3 = NULL, *t3 = NULL;

            subtraction(&h, &t, head2, tail2, &h3, &t3);

            delete_list(h);
            h = h3;
            t = t3;
            q++;
        }
        insert_at_last(headR, tailR, q);
        cur = cur->next;
    }
    while (*headR && (*headR)->data == 0 && (*headR)->next)
        delete_first(headR, tailR);

    return SUCCESS;
}
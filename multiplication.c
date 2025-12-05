/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    if (*head1 == NULL || *head2 == NULL)
        return FAILURE;

    delete_list(*headR);
    *headR = NULL;
    *tailR = NULL;

    Dlist *t1 = *tail1;
    int pos_shift = 0;

    while (t1 != NULL)
    {
        Dlist *t2 = *tail2;
        int carry = 0;

        Dlist *h = NULL, *t = NULL;

        for (int i = 0; i < pos_shift; i++)
            insert_at_last(&h, &t, 0);

        while (t2 != NULL)
        {
            int p = t1->data * t2->data + carry;
            insert_at_first(&h, &t, p % 10);
            carry = p / 10;
            t2 = t2->prev;
        }

        if (carry)
            insert_at_first(&h, &t, carry);

        Dlist *h3 = NULL, *t3 = NULL;

        addition(&h, &t, headR, tailR, &h3, &t3);

        delete_list(*headR);
        *headR = h3;
        *tailR = t3;

        t1 = t1->prev;
        pos_shift++;
    }

    while (*headR && (*headR)->data == 0 && (*headR)->next)
        delete_first(headR, tailR);

    return SUCCESS;
}
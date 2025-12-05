#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;


data_t insert_element(Dlist **head, Dlist **tail, char *argv, int *sign);
data_t insert_at_last(Dlist **head, Dlist **tail, int data);
data_t insert_at_first(Dlist **head, Dlist **tail, int data);
int delete_first(Dlist **head, Dlist **tail);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR ,Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
int operation_validation(char operator);
int compare(Dlist *head1, Dlist *head2);
void print_list(Dlist *head);
void delete_list( Dlist *head );
#endif
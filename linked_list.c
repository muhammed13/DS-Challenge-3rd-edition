/*
 ============================================================================
 Name        : linked_list.c
 Author      : Muhammed Gamal
 Description : this file hasn't completed yet and it going to be enhanced
 in the coming versions of this challenge
 ============================================================================
 */

#include "linked_list.h"



#define NULL ((void*)0)



St_node* create_list(int number_of_nodes)
{
	St_node *head=NULL;
	St_node *temp=NULL;
	St_node *position=NULL;
	int i;
	for(i=0;i<number_of_nodes;i++)
	{
		temp=(St_node*)malloc(sizeof(St_node));
		printf("enter the data for node number %d: \n",i);
		scanf("%d",&(temp->data));
		temp->next=NULL;

		if(head == NULL)
		{
			head=temp;
		}
		else
		{
			position=head;
			while(position->next != NULL)
			{
				position=position->next;
			}
			position->next=temp;
		}
	}
	return head;
}


void add_node_from_end(St_node *head,int data)
{
	St_node *list_ptr=head;
	while(list_ptr->next != NULL)
	{
		list_ptr=list_ptr->next;
	}
	list_ptr->next=(St_node*)malloc(sizeof(St_node));
	list_ptr->next->data=data;
	list_ptr->next->next=NULL;
}


void add_node_from_begin(St_node ** head, int data)
{
	St_node * new_node=NULL;
    new_node = (St_node *) malloc(sizeof(St_node));
    new_node->data = data;
    new_node->next = *head;
    *head=new_node;
}

void print_list(St_node * head)
{
	St_node * list_ptr = head;

    while (list_ptr->next != NULL)
    {
        printf("%d\t",list_ptr->data);
        list_ptr = list_ptr->next;
    }
    printf("%d\t",list_ptr->data);
}


void delete_from_begin(St_node * head)
{
	head=head->next;
	print_list(head);
}


void delete_from_end(St_node * head)
{
	St_node * temp=head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	while(head->next !=temp)
	{
		head=head->next;
	}
	head->next=NULL;

}

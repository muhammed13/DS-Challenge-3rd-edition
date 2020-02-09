/*
 ============================================================================
 Name        : DS_Challenge.c
 Author      : muhammed gamal
 Description : this is the main file of the data structure challenge
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "queue.h"
#include "brackets_check.h"
#include "string_evaluation.h"
#include "linked_list.h"



int main(void) {

	/*this line for printf and scanf issues with eclipse*/
	setvbuf(stdout, NULL, _IONBF, 0);

/************test stack*********************/
/*
	St_stack *stack1 = creat_stack(4);
	push(stack1,10);
	push(stack1,20);
	push(stack1,30);
	push(stack1,40);
	printf("%d poped from stack \n",pop(stack1));
	printf("%d poped from stack\n",pop(stack1));
	printf("%d poped from stack\n",pop(stack1));
	printf("%d poped from stack\n",pop(stack1));
*/


	/****check the brackets*/

	/*
	char str[100];
	printf("enter the string\n");
	scanf("%s",&str);
	unsigned char status = check_brackes(str,100);
	if(status==BALANCED)
	{
		printf("balnced string\n");
	}
	else
	{
		printf("unbalnced string\n");
	}

	*/

	/*****test queue********/
	/*
	St_queue* queue = create_queue(4);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    enqueue(queue, 50);
    enqueue(queue, 60);
    printf("Front item is %d\n", get_front(queue));
    printf("Rear item is %d\n", get_rear(queue));

    */


	/****evaluate the string*/

	char str[100];
	printf("enter the string\n");
	scanf("%s",&str);
	//int result = evaluate_string_without_bracket_priority(str);
	int result = evaluate_string_with_bracket_priority(str);
	if(result==WRONG_STRING)
	{
		printf("unbalnced string\n");
	}
	else
	{
		printf("the result = %d\n",result);
	}



	/****linked list******/
	/*
	int number_of_nodes=0;
	St_node* head=NULL;
	printf("enter the number of nodes ");
	scanf("%d",&number_of_nodes);
	head=create_list(number_of_nodes);
	add_node_from_end(head,77);
	add_node_from_end(head,88);
	delete_from_end(head);
	print_list(head);
	*/
}

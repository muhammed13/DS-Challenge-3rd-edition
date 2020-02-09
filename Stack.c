/*
 ============================================================================
 Name        : Stack.c
 Author      : Muhammed Gamal
 Description : this file includes the implementation of all stack functions
 ============================================================================
 */
#include "Stack.h"


St_stack *creat_stack(unsigned char stack_size)
{
	St_stack* stack = (St_stack*)malloc(sizeof(St_stack));
	stack->stack_size =stack_size;
	stack->stack_counter=-1;
	stack->stack_array=(int*)malloc(stack->stack_size *sizeof(int));
	return stack;
}

int stack_is_empty(St_stack *stack)
{
	if(stack->stack_counter<=-1)
	{
		return 1;   /*one means that the stack is empty*/
	}
	else
	{
		return 0;
	}
}

int stack_is_full(St_stack *stack)
{
	if(stack->stack_counter>stack->stack_size-1)
	{
		return 1;  /*one means that the stack is full*/
	}
	else
	{
		return 0;
	}
}

void push(St_stack *stack,char value)
{
	stack->stack_counter++;
	if(stack_is_full(stack))
	{
		printf("the stack is full\n");
		stack->stack_counter=stack->stack_size-1;
	}
	else
	{
		stack->stack_array[stack->stack_counter]=value;
		printf("%d pushed to stack\n", value);
	}
}

int pop(St_stack *stack)
{
	int element=0;
	if(stack_is_empty(stack))
	{
		printf("the stack is empty\n");
	}
	else
	{
		element = stack->stack_array[stack->stack_counter];
		stack->stack_counter--;
	}
	return element;
}

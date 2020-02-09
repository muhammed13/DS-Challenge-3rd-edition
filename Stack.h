/*
 ============================================================================
 Name        : Stack.h
 Author      : Muhammed Gamal
 Description : this is the header file of the stack
 ============================================================================
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct St_stack{
	unsigned int stack_size;
	int stack_counter;
	int *stack_array;
}St_stack;


St_stack *creat_stack(unsigned char stack_size);
int stack_is_empty(St_stack *stack);
int stack_is_full(St_stack *stack);
void push(St_stack *stack,char value);
int pop(St_stack *stack);


#endif /* STACK_H_ */

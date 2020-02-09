/*
 ============================================================================
 Name        : brackets_check.c
 Author      : Muhammed Gamal
 Description : this file contains the implementation of balanced brackets challenge
 ============================================================================
 */

/********************************includs***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "brackets_check.h"
/**************************************************************************/

/*****************************local definitions****************************/
#define FLAG_HIGH 1
#define FLAG_DOWN 0
#define START 0
#define EMPTY_STACK -1
/**************************************************************************/

unsigned char check_brackes(char str[],unsigned char string_size)
{
	St_stack *stack_for_brackets = creat_stack(string_size);
	char bracket;
	//char str[STRING_SIZE];
	unsigned int i=START;
	unsigned matching_flag=FLAG_HIGH;
	//printf("enter the string\n");
	//scanf("%s",&str);

	while(str[i]!='\0')
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		{
			push(stack_for_brackets,str[i]);
		}

		else if(str[i]==')' || str[i]=='}' || str[i]==']')
		{
			bracket=pop(stack_for_brackets);
			if( (bracket== '(' && str[i]==')') || (bracket== '{' && str[i]=='}')
					|| (bracket== '[' && str[i]==']') )
			{
				/*no action needed*/
			}

			else
			{
				matching_flag=FLAG_DOWN;
			}
		}
		i++;
	}

	if(stack_for_brackets->stack_counter > EMPTY_STACK || matching_flag == FLAG_DOWN)
	{
		return UNBALANCED;
	}
	else
	{
		return BALANCED;
	}

}

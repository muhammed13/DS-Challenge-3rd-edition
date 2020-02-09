/*
 ============================================================================
 Name        : string_evaluation.c
 Author      : Muhammed Gamal
 Description : this file include the implementation of evaluate_string function
 ============================================================================
 */
#include "string_evaluation.h"


/*************************************************************************
* Function Name: evaluate_string_without_bracket_priority
* Parameters (in): char str[] - array of chars that represent the input string
*
* Return value: result - int that represent the result of calculation
* Description: this function an input equation from the caller in a string form
* and return the output of the equation as an integer  without tacking into
* consideration the priority of the brackets
*
* NOTE THAT: Each number in the string has to be one digit
* ex: 10/5  WORNG INPUT , since 10 is two digits
*     9/3   RIGHT INPUT
* ***********************************************************************/
int evaluate_string_without_bracket_priority(char str[])
{
	St_queue* queue = create_queue(10);
	unsigned char i=0;
	unsigned char j=0;
	unsigned char counter;
	char result=0;
	char operation_out=0;
	unsigned char status = check_brackes(str,100);
	if(status==UNBALANCED)
	{
		printf("unbalnced string\n");
		return WRONG_STRING;
	}
	else
	{
		while(str[i]!='\0')
		{
			if(str[i] != '(' && str[i] != ')' && str[i] != '{' && str[i] != '}'
					&& str[i] != '[' &&  str[i] != ']' )
			{
				enqueue(queue,str[i]);
			}
			i++;
		}

	   counter =queue->queue_counter;
		while(counter!=0)
		{
			if(queue->queue_array[j]=='+')
			{
				//-48 because the string is array of chars not integers
				if(result==0)
				{
					operation_out=(queue->queue_array[j-1]-48) + (queue->queue_array[j+1]-48);
				}
				else
				{
					operation_out=(result + queue->queue_array[j+1]-48);
				}
				result=operation_out;
			}

			else if(queue->queue_array[j]=='-')
			{
				//-48 because the string is array of chars not integers
				if(result==0)
				{
					operation_out=(queue->queue_array[j-1]-48) - (queue->queue_array[j+1]-48);
				}
				else
				{
					operation_out=result - (queue->queue_array[j+1]-48);
				}
				result=operation_out;
			}

			else if(queue->queue_array[j]=='*')
			{
				//-48 because the string is array of chars not integers
				if(result==0)
				{
					operation_out=(queue->queue_array[j-1]-48) * (queue->queue_array[j+1]-48);
				}
				else
				{
					operation_out=result * (queue->queue_array[j+1]-48);
				}
				result=operation_out;
			}

			else if(queue->queue_array[j]=='/')
			{
				//-48 because the string is array of chars not integers
				if(result==0)
				{
					operation_out=(queue->queue_array[j-1]-48) / (queue->queue_array[j+1]-48);
				}
				else
				{
					operation_out=result / (queue->queue_array[j+1]-48);
				}
				result=operation_out;
			}

			j++;
			counter--;
		}

	}
	return result;

}



/*************************************************************************
* Function Name: evaluate_string_with_bracket_priority
* Parameters (in): char str[] - array of chars that represent the input string
*
* Return value: result - int that represent the result of calculation
* Description: this function an input equation from the caller in a string form
* and return the output of the equation as an integer taking into consideration
* the priority of the brackets
*
** NOTE THAT: Each number in the string has to be one digit
* ex: 10/5  WORNG INPUT , since 10 is two digits
*     9/3   RIGHT INPUT
*
* NOTE THAT: this function still can't handle two cases
* first case: (any bracket inside bracket)
* ex: 2+((5+3)+4) here there is a bracket inside a bracket and this case
* still not handled in this version of the file
*
* second case:single number inside bracket without any operation
* ex : (2)+5
* this case actually has no meaning since there is no operation inside the bracket
* but this case will be handled in the coming versions of this file
* ***********************************************************************/
int evaluate_string_with_bracket_priority(char str[])
{
	St_queue* queue = create_queue(15);
	unsigned int i=0;
	unsigned int j=0;
	unsigned int counter;
	int result=0;
	int operation_out=0;
	int brackets_count_flag=0;
	char operation_before_bracket;
	int brackets_result=0;
	int bracket_operation_out=0;
	int result_before_bracket=0;
	unsigned char status = check_brackes(str,100);

	/*check if the brackets are balanced or not*/
	if(status==UNBALANCED)
	{
		printf("unbalnced string\n");
		return WRONG_STRING;
	}

	/*saving the string elements into a queue*/
	else
	{
		while(str[i]!='\0')
		{
			enqueue(queue,str[i]);
			i++;
		}

		/*loop on all elements in the queue*/
	   counter =queue->queue_counter;
		while(counter!=0)
		{
			if(queue->queue_array[j] == '(' && queue->queue_array[j] != '{'
					&& queue->queue_array[j] != '[')
			{
				/*
				 * -count the number of opened brackets
				 * -save the last operation before the bracket into a variable
				 * */
				brackets_count_flag++;
				operation_before_bracket=queue->queue_array[j-brackets_count_flag];
			}

			else if(queue->queue_array[j] == ')' && queue->queue_array[j] != '}'
					&& queue->queue_array[j] != ']')
			{
				/*
				 * -decrease the number of opened brackets by one
				 * -switch for the last equation before the bracket
				 * -calculate the new result
				 * -reset the bracket result
				 * */
				brackets_count_flag--;
				switch(operation_before_bracket)
				{
					case('+'):
						result=result_before_bracket+brackets_result;
						brackets_result=0;
					break;

					case('-'):
						result=result_before_bracket-brackets_result;
						brackets_result=0;
					break;

					case('*'):
						result=result_before_bracket*brackets_result;
						brackets_result=0;
					break;

					case('/'):
						result=result_before_bracket/brackets_result;
						brackets_result=0;
					break;

				}


			}

			/*check if the next element is a bracket*/
			else if(queue->queue_array[j+1]=='(' || queue->queue_array[j+1]=='{'
					|| queue->queue_array[j+1]=='[')
			{
				/*
				 * if there is no old operation before the bracket
				 * for example "1+(2+3)"
				 * */
				if(result==0)
				{
					result_before_bracket= (queue->queue_array[j-1]-48);
				}
				else
				{
					result_before_bracket=result;
				}
				j++;
				continue;
			}

			/*
			 *-check the operation
			 *-check if this operation is inside a bracket or outside a bracket
			 * */
			else if(queue->queue_array[j]=='+')
			{
				if(brackets_count_flag>0)
				{
					/*-48 because the string is array of chars not integers*/
					if(brackets_result==0) /*this means that this operation is the first one inside the bracket*/
					{
						bracket_operation_out=(queue->queue_array[j-1]-48) + (queue->queue_array[j+1]-48);
					}
					else
					{
						bracket_operation_out=brackets_result + (queue->queue_array[j+1]-48);
					}
					brackets_result=bracket_operation_out;
				}
				else
				{
					/*-48 because the string is array of chars not integers*/
					if(result==0) /*this means that this operation is the first one*/
					{
						operation_out=(queue->queue_array[j-1]-48) + (queue->queue_array[j+1]-48);
					}
					else
					{
						operation_out=result + (queue->queue_array[j+1]-48);
					}
					result=operation_out;
				}
			}

			else if(queue->queue_array[j]=='-')
			{
				if(brackets_count_flag>0)
				{
					/*-48 because the string is array of chars not integers*/
					if(brackets_result==0)/*this means that this operation is the first one inside the bracket*/
					{
						bracket_operation_out=(queue->queue_array[j-1]-48) - (queue->queue_array[j+1]-48);
					}
					else
					{
						bracket_operation_out=brackets_result - (queue->queue_array[j+1]-48);
					}
					brackets_result=bracket_operation_out;
				}
				else
				{
					/*-48 because the string is array of chars not integers*/
					if(result==0)/*this means that this operation is the first one*/
					{
						operation_out=(queue->queue_array[j-1]-48) - (queue->queue_array[j+1]-48);
					}
					else
					{
						operation_out=result - (queue->queue_array[j+1]-48);
					}
					result=operation_out;
				}
			}

			else if(queue->queue_array[j]=='*')
			{
				if(brackets_count_flag>0)
				{
					/*-48 because the string is array of chars not integers*/
					if(brackets_result==0)/*this means that this operation is the first one inside the bracket*/
					{
						bracket_operation_out=(queue->queue_array[j-1]-48) * (queue->queue_array[j+1]-48);
					}
					else
					{
						bracket_operation_out=brackets_result * (queue->queue_array[j+1]-48);
					}
					brackets_result=bracket_operation_out;
				}
				else
				{
					/*-48 because the string is array of chars not integers*/
					if(result==0)/*this means that this operation is the first one*/
					{
						operation_out=(queue->queue_array[j-1]-48) * (queue->queue_array[j+1]-48);
					}
					else
					{
						operation_out=result * (queue->queue_array[j+1]-48);
					}
					result=operation_out;
				}
			}

			else if(queue->queue_array[j]=='/')
			{
				if(brackets_count_flag>0)
				{
					/*-48 because the string is array of chars not integers*/
					if(brackets_result==0)/*this means that this operation is the first one inside the bracket*/
					{
						bracket_operation_out=(queue->queue_array[j-1]-48) / (queue->queue_array[j+1]-48);
					}
					else
					{
						bracket_operation_out=brackets_result / (queue->queue_array[j+1]-48);
					}
					brackets_result=bracket_operation_out;
				}
				else
				{
					/*-48 because the string is array of chars not integers*/
					if(result==0)/*this means that this operation is the first one*/
					{
						operation_out=(queue->queue_array[j-1]-48) / (queue->queue_array[j+1]-48);
					}
					else
					{
						operation_out=result / (queue->queue_array[j+1]-48);
					}
					result=operation_out;
				}
			}

			j++;
			counter--;
		}

	}
	return result;
}


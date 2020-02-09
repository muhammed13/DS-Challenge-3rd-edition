/*
 ============================================================================
 Name        : string_evaluation.h
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */

#ifndef STRING_EVALUATION_H_
#define STRING_EVALUATION_H_

#include "Stack.h"
#include "brackets_check.h"
#include "queue.h"


#define WRONG_STRING -99

int evaluate_string_without_bracket_priority(char str[]);
int evaluate_string_with_bracket_priority(char str[]);

#endif /* STRING_EVALUATION_H_ */

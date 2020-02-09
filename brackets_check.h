/*
 ============================================================================
 Name        : brackets_check.h
 Author      : Muhammed Gamal
 Description : this is the header file of balanced brackets challenge
 ============================================================================
 */

#ifndef BRACKETS_CHECK_H_
#define BRACKETS_CHECK_H_

/***************************includes**************************/
#include "Stack.h"
/*************************************************************/


/**************************definitions************************/
#define BALANCED 1
#define UNBALANCED 0
/*************************************************************/


/***********************functions****************************/
unsigned char check_brackes(char str[],unsigned char string_size);
/************************************************************/


#endif /* BRACKETS_CHECK_H_ */

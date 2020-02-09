/*
 ============================================================================
 Name        : linked_list.h
 Author      : Muhammed Gamal
 Description : this is the header file of linked list
 ============================================================================
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct St_node {
    int data;
    struct St_node* next;
}St_node;


St_node* create_list(int number_of_nodes);
void add_node_from_end(St_node *head,int data);
void add_node_from_begin(St_node ** head, int data);
void print_list(St_node * head);
void delete_from_begin(St_node * head);
void delete_from_end(St_node * head);
#endif /* LINKED_LIST_H_ */

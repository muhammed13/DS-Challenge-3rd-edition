/*
 ============================================================================
 Name        : queue.h
 Author      : Muhammed Gamal
 Description : this is the header file of the queue
 ============================================================================
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct St_queue{
    int front;
    int rear;
    int queue_counter;
    unsigned queue_size;
    int* queue_array;
}St_queue;


St_queue* create_queue(unsigned char size);
int is_full(St_queue* queue);
int is_empty(St_queue* queue);
void enqueue(St_queue* queue, int item);
int dequeue(St_queue* queue);
int get_front(St_queue* queue);
int get_rear(St_queue* queue);

#endif /* QUEUE_H_ */

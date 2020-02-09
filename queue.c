/*
 ============================================================================
 Name        : queue.c
 Author      : Muhammed Gamal
 Description : this file includes the implementation of all queue functions
 ============================================================================
 */
#include "queue.h"



St_queue* create_queue(unsigned char size)
{
	St_queue* queue = (St_queue*) malloc(sizeof(St_queue));
    queue->queue_size = size;
    queue->front = 0;
    queue->rear = 0;
	queue->queue_counter = 0;
    queue->queue_array = (int*) malloc(queue->queue_size* sizeof(int));
    return queue;
}


int is_full(St_queue* queue)
{
	if(queue->queue_counter >= queue->queue_size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int is_empty(St_queue* queue)
{
	if(queue->queue_counter == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void enqueue(St_queue* queue, int item)
{
    if (is_full(queue))
    {
        printf("the queue is full\n");
        return;
    }
    queue->queue_array[queue->rear]=item;
    queue->rear++;
    queue->queue_counter++;
    printf("%d enqueued to queue\n",item);
}


int dequeue(St_queue* queue)
{
    if (is_empty(queue))
    {
    	printf("the queue is empty\n");
        return -1;
    }
    int item = queue->queue_array[queue->front];
    queue->front++;
    queue->queue_counter--;
    return item;
}



int get_front(St_queue* queue)
{
    if (is_empty(queue))
    {
    	printf("the queue is empty\n");
        return -1;
    }
    else
    {
    	return queue->queue_array[queue->front];
    }
}


int get_rear(St_queue* queue)
{
    if (is_empty(queue))
    {
    	printf("the queue is empty\n");
        return -1;
    }
    else
    {
    	return queue->queue_array[queue->rear-1];
    }
}

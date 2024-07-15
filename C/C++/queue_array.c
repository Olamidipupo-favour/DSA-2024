#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
int* data;
int capacity;
int size;
} Queue;

Queue* init_queue(int capacity){
Queue* queue=malloc(sizeof(Queue));
queue->data=malloc(sizeof(int)*capacity);
queue->capacity=capacity;
queue->size=0;
return queue;
}

int enqueue(Queue* queue, int key){
if(queue->capacity==queue->size){
return -1;
}
else{
    queue->data[queue->size]=key;
    queue->size++;
    return 0;
}
}

int dequeue(Queue* queue){
int popped=queue->data[0];
int* data=queue->data;
queue->data=queue->data+1;
queue->size--;
return popped;
}

bool full(Queue* queue){
    return queue->capacity==queue->size;
}

bool empty(Queue* queue){
    return queue->size==0;
}
void print_queue(Queue* queue){
    for(int i=0;i<queue->size;i++){
        printf("index %i : %i \n",i,queue->data[i]);
    }
}

int main(void){
    Queue* queue=init_queue(5);
    enqueue(queue,1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    printf("%i \n",full(queue));
    //dequeue(queue);
    print_queue(queue);
    return 0;
}
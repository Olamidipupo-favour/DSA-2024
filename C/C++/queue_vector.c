#include "array.c"

typedef struct {
vector*  queue;
} Queue;
Queue* init_queue(){
    Queue* queue=malloc(sizeof(queue));
    queue->queue=init_vector(2);
    return queue;
}

void Enqueue(Queue* queue,int key){
    push_back(queue->queue,key);
}

int Dequeue(Queue* queue){
    //return the first element in the queue and remove the aray
    int popped=at(queue->queue,0);
    delete(queue->queue,0);
    return popped;
}

void print_queue(Queue* queue){
    print_vector(queue->queue);
}

bool Empty(Queue* queue){
    return is_empty(queue->queue);
}

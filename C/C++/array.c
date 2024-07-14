/*****************************************************************************************************************

Implementataion of a resizable, dynamic array; vector in C.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
int* data;
size_t size;
size_t capacity;
} vector;

vector* init_vector(int capacity){
    vector* v=malloc(sizeof(vector));
    v->data=malloc(capacity*sizeof(int));
    v->capacity=capacity;
    v->size=0;
    return v;
}

void print_vector(vector* v){
    for(int i=0;i<v->size;i++){
printf("index %i : %i \n",i,v->data[i]);
        
    }
}

vector* push_back(vector* v,int value){
    if(v->capacity<=v->size){
        int* new_data=realloc(v->data,v->capacity*2*sizeof(int));
        v->data=new_data;
        v->capacity=2*v->capacity;
        }

    v->data[v->size]=value;
    v->size++;
    return v;
}

int at(vector* v, int index){
    return v->data[index];
}

int insert(vector* v, int index, int value) {
    if (index > v->size || index < 0) {
        return -1;
    }

    if (v->size+1 >= v->capacity) {
        int new_capacity = v->capacity * 2;
        int* new_data = realloc(v->data, sizeof(int) * new_capacity);
        if (!new_data) {
            return -1;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    for (int i = v->size; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[index] = value;
    v->size++;

    return 0;
}
void prepend(vector* v,int value){
    if(v->size+1>=v->capacity){
        int* new_data=realloc(v->data,2*v->capacity*sizeof(int));
        v->data=new_data;
        v->capacity=2*v->capacity;
    }
    
    for (int i = v->size; i > 0; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[0]=value;
    v->size++;
}

int pop(vector* v){
    int popped=(int)v->data[v->size-1];
    v->data[v->size-1]=0;
    v->size--;
    return popped;
} 

int delete(vector* v,int index){
    if(index>=v->size){
return -1;
    }
    //shift left
    for(int i=index;i<=v->size;i++){
        v->data[i]=v->data[i+1];
    }
    v->size--;
    return 0;
}

vector* find(vector* v,int value){
vector* data=init_vector(1);
for(int i=0;i<v->size;i++){
    if(v->data[i]==value){
        push_back(data,i);
    }
}
return data;
} 

void remove_(vector* v, int value){
vector* indices = find(v,value);
for(int i=0;i<indices->size;i++){
    if(delete(v,indices->data[i])==-1){
        printf("An error occured!");
        return;
    };
}
}



int size(vector* v){
    return v->size;
}
int capacity(vector* v){
    return v->capacity;
}

bool is_empty(vector* v){
    return v->size==0;
}
int main(void){
    vector* v=init_vector(1);
    push_back(v,4);
    push_back(v,4);
    push_back(v,1);
    push_back(v,2);
    push_back(v,3);
    printf("%i",capacity(v));
    //print_vector(v);
    //printf("%i",at(v,4));
    return 0;
}
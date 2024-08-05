#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
int** map;
int capacity;

} HashMap;

int hash(int key){
    // implementation of the trivial hashing function
    return key;
}

HashMap* init_hashmap(int capacity){
    HashMap* map = malloc(sizeof(HashMap));
    map->capacity=capacity;
    map->map=(int**)malloc(sizeof(int)*(map->capacity));
    for(int i=0;i<map->capacity+1;i++){
        map->map[i]=(int*)malloc(sizeof(int));
        map->map[i][0]=0;
    }
    return map;
}
int push_hash(HashMap* map, int key, int value){
    if(key < 0){
        map->map[key][1] = 1;
    }
    else{
        // Check if the first column of the map is null
        map->map[key][0] = 1;
    }

    // Return success
    return 0;
}

bool search(HashMap* map, int key) {
    return (map->map[key][0] == 1 || map->map[key][1] == 1);
}

int main(){
    //initialize an hashmap
     printf("=== res1 i    === res2 \a \n");
    HashMap* map= init_hashmap(10);
    push_hash(map,1,10);
    push_hash(map,4,100);

    printf("=== res1 %i    === res2 %i \n",search(map,4), search(map,5));
    return 0;
}
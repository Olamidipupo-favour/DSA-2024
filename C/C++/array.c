/*****************************************************************************************************************

Implementataion of a resizable, dynamic array; vector in C.
Author: Agboola Olamidipupo Favour
Github: https://www.github.com/Olamidipupo-favour
Linkedin: https://www.linkedin.com/in/olamidipupo-agboola-6b3917237/
Portfolio: https://Olamidipupo-favour.github.io/

******************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
int* data;
size_t size;
size_t capacity;
} vector;

/**
 * Initialize a new vector with a given capacity.
 *
 * This function allocates memory for a new vector struct and initializes its
 * fields. It takes an integer `capacity` as its argument and returns a pointer
 * to the newly created vector.
 *
 * The `malloc` function is used to allocate memory for the vector struct
 * and its `data` field. The size of the allocated memory is equal to the
 * capacity times the size of an integer.
 *
 * The `capacity` field is set to the provided capacity, the `size` field is
 * initialized to 0, and the function returns a pointer to the newly created
 * vector.
 *
 * @param capacity The maximum number of elements that the vector can hold
 * @return A pointer to the newly created vector
 */
vector* init_vector(int capacity){
    // Allocate memory for a new vector struct
    vector* v = malloc(sizeof(vector));
    // Allocate memory for the vector's data field
    v->data = malloc(capacity * sizeof(int));
    // Set the capacity field to the provided capacity
    v->capacity = capacity;
    // Initialize the size field to 0
    v->size = 0;
    // Return a pointer to the newly created vector
    return v;
}

/**
 * This function prints the contents of a vector to the console.
 *
 * It takes a pointer to a vector as its argument, and iterates over each
 * element of the vector using a loop. For each element, it prints the index
 * and the corresponding value to the console using the `printf` function.
 *
 * @param v A pointer to the vector to be printed
 */
void print_vector(vector* v){

    // Initialize a counter variable to keep track of the current index
    int i;

    // Begin the loop that iterates over each element of the vector
    for(i=0;i<v->size;i++){
        // Print the index and the value at the current index
        printf("index %i : %i \n",i,v->data[i]);
        
    }

    // Print a newline character to separate the output from other console output
    printf("\n");

}

/**
 * This function adds a new value to the end of a vector.
 *
 * It takes a pointer to a vector as its first argument, and an integer value as
 * its second argument. It checks if the capacity of the vector is greater than
 * or equal to its size. If it is, it allocates twice the memory for the vector's
 * data field and assigns the new memory address to the vector's data field. It
 * then updates the capacity of the vector to be twice its previous value. If
 * the capacity is not greater than or equal to the size, it simply adds the new
 * value to the end of the vector's data field and increments the size of the
 * vector. Finally, it returns a pointer to the updated vector.
 *
 * @param v A pointer to the vector to which the new value should be added
 * @param value The integer value to be added to the end of the vector
 * @return A pointer to the updated vector
 */
vector* push_back(vector* v, int value) {
    // Check if the capacity of the vector is greater than or equal to its size
    if (v->capacity <= v->size) {
        // If the capacity is not sufficient, allocate twice the memory for the vector's data field
        int* new_data = realloc(v->data, v->capacity * 2 * sizeof(int));
        // Assign the new memory address to the vector's data field
        v->data = new_data;
        // Update the capacity of the vector to be twice its previous value
        v->capacity = 2 * v->capacity;
    }

    // Add the new value to the end of the vector's data field
    v->data[v->size] = value;
    // Increment the size of the vector
    v->size++;
    // Return a pointer to the updated vector
    return v;
}

/**
 * This function returns the value stored at a given index in a vector.
 *
 * It takes a pointer to a vector as its first argument, and an integer index as
 * its second argument. It checks that the index is within the bounds of the 
 * vector's size. If the index is valid, it returns the value stored at the 
 * given index in the vector's data field. If the index is not valid, it returns
 * -1.
 *
 * @param v A pointer to the vector from which the value should be retrieved
 * @param index The index of the value to be retrieved
 * @return The value stored at the given index in the vector's data field, or -1 if
 *         the index is out of bounds
 */
int at(vector* v, int index){
    // Check that the index is within the bounds of the vector's size
    if (index < 0 || index >= v->size) {
        // If the index is not valid, return -1
        return -1;
    }

    // Return the value stored at the given index in the vector's data field
    return v->data[index];
}

/**
 * This function inserts a new value into a vector at a given index.
 *
 * It takes a pointer to a vector as its first argument, and an integer index as
 * its second argument. It also takes an integer value as its third argument,
 * which is the value to be inserted into the vector.
 *
 * This function first checks that the index is within the bounds of the vector's
 * size. If the index is not valid, it returns -1.
 *
 * Next, the function checks if the vector is currently full. If it is, the
 * function doubles the capacity of the vector by allocating new memory and
 * copying the existing data into the new memory.
 *
 * Once the vector has enough capacity, the function shifts all the elements
 * in the vector to the right of the insertion index one position to the right,
 * making room for the new value.
 *
 * Finally, the function inserts the new value at the specified index and
 * increments the size of the vector.
 *
 * @param v A pointer to the vector into which the value should be inserted
 * @param index The index at which the new value should be inserted
 * @param value The value to be inserted into the vector
 * @return 0 if the value was successfully inserted, or -1 if an error occurred
 */
int insert(vector* v, int index, int value) {
    // Check that the index is within the bounds of the vector's size
    if (index > v->size || index < 0) {
        // If the index is not valid, return -1
        return -1;
    }

    // Check if the vector is currently full
    if (v->size+1 >= v->capacity) {
        // If the vector is full, double the capacity of the vector
        int new_capacity = v->capacity * 2;
        int* new_data = realloc(v->data, sizeof(int) * new_capacity);
        if (!new_data) {
            // If the reallocation failed, return -1
            return -1;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

    // Shift all the elements in the vector to the right of the insertion index one position to the right
    for (int i = v->size; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }

    // Insert the new value at the specified index
    v->data[index] = value;

    // Increment the size of the vector
    v->size++;

    // Return 0 to indicate that the value was successfully inserted
    return 0;
}
/**
 * This function prepends a new value to the front of a vector.
 *
 * It first checks if the vector is full by comparing the size of the vector
 * plus one to the capacity. If the vector is full, it reallocates more memory
 * to double the capacity of the vector.
 *
 * Next, it shifts all the elements in the vector to the right to make room for
 * the new value at the front of the vector. It does this by iterating over
 * the vector in reverse and copying each element to the position one to the
 * right.
 *
 * After shifting the elements, it inserts the new value at the front of the
 * vector. This is done by simply assigning the new value to the first element
 * of the vector's data field.
 *
 * Finally, it increments the size of the vector.
 *
 * @param v A pointer to the vector to which the value should be prepended
 * @param value The value to be prepended to the vector
 */
void prepend(vector* v,int value){
    // Check if the vector is full
    if(v->size+1>=v->capacity){
        // If the vector is full, double the capacity of the vector
        int* new_data=realloc(v->data,2*v->capacity*sizeof(int));
        v->data=new_data;
        v->capacity=2*v->capacity;
    }
    
    // Shift all the elements in the vector to the right
    for (int i = v->size; i > 0; i--) {
        v->data[i] = v->data[i - 1];
    }
    // Insert the new value at the front of the vector
    v->data[0]=value;
    // Increment the size of the vector
    v->size++;
}

int pop(vector* v){
    // Store the element to be popped
    int popped = (int)v->data[v->size - 1];
    // Reset the value at the popped index to 0
    v->data[v->size - 1] = 0;
    // Decrease the size of the vector
    v->size--;
    // Return the popped element
    return popped;
}

/**
 * This function deletes an element at a given index from a vector.
 *
 * It first checks if the index is valid (i.e. if it is within the bounds of
 * the vector's size). If the index is not valid, the function returns -1.
 *
 * If the index is valid, the function then shifts all the elements in the vector
 * to the left, starting from the given index. This is done by iterating over
 * the vector, starting from the index, and assigning each element the value of
 * the element to its right. This effectively removes the element at the given
 * index.
 *
 * Finally, the function decrements the size of the vector.
 *
 * @param v A pointer to the vector from which the element should be deleted
 * @param index The index of the element to be deleted
 * @return 0 if the element was successfully deleted, or -1 if an error occurred
 */
int delete(vector* v,int index){
    // Check if the index is valid
    if(index>=v->size){
        // If the index is not valid, return -1
        return -1;
    }

    // Shift all the elements in the vector to the left, starting from the given index
    for(int i=index;i<=v->size;i++){
        // Assign each element the value of the element to its right
        v->data[i]=v->data[i+1];
    }

    // Decrement the size of the vector
    v->size--;

    // Return 0 if the element was successfully deleted
    return 0;
}

/**
 * This function finds all the indices of a given value in a vector.
 *
 * It takes a pointer to a vector as its first argument, and an integer value as
 * its second argument.
 *
 * It first initializes a new vector with a size of 1 and assigns it to a local
 * variable `data`. This vector is used to store the indices of the given value
 * in the original vector.
 *
 * It then iterates over the original vector, starting from the first element and
 * ending at the last element. For each element, it checks if the value of the
 * element is equal to the given value. If it is, it adds the index of the
 * element to the `data` vector by calling the `push_back` function on the
 * `data` vector and passing the index as its argument.
 *
 * Once the iteration is complete, it returns the `data` vector.
 *
 * @param v A pointer to the vector in which the value is to be searched
 * @param value The value to be searched in the vector
 * @return A pointer to a vector containing the indices of the given value in the
 *         original vector
 */
vector* find(vector* v,int value){
    // Initialize a new vector with a size of 1 and assign it to a local variable
    vector* data=init_vector(1);
    
    // Iterate over the original vector, starting from the first element and
    // ending at the last element
    for(int i=0;i<v->size;i++){
        // Check if the value of the element is equal to the given value
        if(v->data[i]==value){
            // If it is, add the index of the element to the `data` vector by calling
            // the `push_back` function on the `data` vector and passing the index
            // as its argument
            push_back(data,i);
        }
    }
    
    // Return the `data` vector
    return data;
} 

/**
 * This function removes all occurrences of a specified value from a vector.
 *
 * It first calls the `find` function to search for the specified value in the
 * original vector and stores the result in the `indices` vector.
 *
 * It then iterates over the `indices` vector, starting from the first element
 * and ending at the last element. For each index, it calls the `delete` function
 * on the original vector and passes the index as its argument. If the `delete`
 * function returns -1 (which indicates an error), it prints an error message
 * and returns from the function.
 *
 * @param v A pointer to the vector from which the value should be removed
 * @param value The value to be removed from the vector
 */
void remove_(vector* v, int value){
    // Search for the specified value in the original vector and store the result
    // in the `indices` vector
    vector* indices = find(v,value);
    
    // Iterate over the `indices` vector, starting from the first element and
    // ending at the last element
    for(int i=0;i<indices->size;i++){
        // For each index, call the `delete` function on the original vector and
        // pass the index as its argument
        if(delete(v,indices->data[i])==-1){
            // If the `delete` function returns -1 (which indicates an error),
            // print an error message and return from the function
            printf("An error occurred!\n");
            return;
        };
    }

}



/**
 * This function returns the size of a given vector.
 *
 * The size of a vector is the number of elements that it contains. It is
 * different from the capacity of a vector, which is the maximum number of
 * elements that it can contain.
 *
 * @param v A pointer to the vector whose size is to be returned
 * @return The size of the vector
 */
int size(vector* v){
    // Simply return the size of the vector
    return v->size;
}

/**
 * This function returns the capacity of a given vector.
 *
 * The capacity of a vector is the maximum number of elements that it can
 * contain. It is different from the size of a vector, which is the number of
 * elements that it currently contains.
 *
 * @param v A pointer to the vector whose capacity is to be returned
 * @return The capacity of the vector
 */
int capacity(vector* v){
    // Return the capacity of the vector
    // This is the maximum number of elements that the vector can contain
    return v->capacity;
}

/**
 * This function checks if a given vector is empty.
 *
 * It takes a pointer to a vector as its argument, and returns true if the
 * vector is empty (i.e. if its size is 0), and false otherwise.
 *
 * @param v A pointer to the vector to be checked
 * @return true if the vector is empty, false otherwise
 */
bool is_empty(vector* v){
    // Simply return whether the size of the vector is 0 or not
    // If the size is 0, then the vector is empty
    return v->size==0;
}
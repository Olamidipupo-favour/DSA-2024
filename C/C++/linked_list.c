/*****************************************************************************************************************

Implementataion of a singly linked list in C. 
Author: Agboola Olamidipupo Favour
Github: https://www.github.com/Olamidipupo-favour
Linkedin: https://www.linkedin.com/in/olamidipupo-agboola-6b3917237/
Portfolio: https://Olamidipupo-favour.github.io/

******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

/**
 * Initialize a linked list.
 *
 * This function allocates memory for a node and sets its `next` pointer to
 * `NULL`. It then returns a pointer to the newly allocated node. This node
 * will serve as the head of the linked list.
 *
 * @return A pointer to the head of the linked list.
 */
node *init_linked_list()
{
    // Allocate memory for a node
    node *list = malloc(sizeof(node));

    // Set the `next` pointer of the node to `NULL`
    list->next = NULL;

    // Return a pointer to the newly allocated node
    return list;
}

/**
 * Add a new node to the front of the linked list.
 *
 * This function allocates memory for a new node and sets its `value` to the
 * provided `value`. It then sets the `next` pointer of the new node to the
 * current head of the linked list (which is `list->next`). Finally, it updates
 * the `next` pointer of the original head node to point to the new node, and
 * returns a pointer to the original head node.
 *
 * @param list A pointer to the head of the linked list.
 * @param value The value to be stored in the new node.
 * @return A pointer to the updated head of the linked list.
 */
node *push_front(node *list, int value)
{
    // Allocate memory for a new node
    node *new_node = init_linked_list();

    // Set the `value` of the new node to the provided `value`
    new_node->value = value;

    // Set the `next` pointer of the new node to the current head of the linked list
    new_node->next = list->next;

    // Update the `next` pointer of the original head node to point to the new node
    list->next = new_node;

    // Return a pointer to the updated head of the linked list
    return list;
}

/*
 * This function prints out the values stored in each node of a linked list,
 * starting from the second node (since the first node is typically used as a
 * sentinel or head node). The function takes a pointer to the head node of the
 * linked list as its argument.
 *
 * Inside the function, a loop is used to iterate over each node of the linked
 * list. For each node, the function prints out the value stored in the node and
 * the index of the node relative to the head node. The index is incremented for
 * each node visited.
 *
 * The function does not return anything.
 */
void print_linked_list(node *list)
{
    // Initialize a counter variable to keep track of the index of each node
    int j = 0;

    // Begin the loop that iterates over each node of the linked list
    for (node *i = list->next; i != NULL; i = i->next)
    {
        // Print out the value stored in the current node and its index
        printf("index %i : %i \n", j, i->value);

        // Increment the index counter for the next iteration
        j++;
    }
}

/*
 * This function calculates the size of a linked list by iterating over each
 * node and incrementing a counter variable. The function takes a pointer to the
 * head node of the linked list as its argument.
 *
 * Inside the function, a loop is used to iterate over each node of the linked
 * list. For each node, the function increments a counter variable named `size`.
 * The loop continues until the `next` pointer of the current node is `NULL`,
 * indicating the end of the linked list.
 *
 * After the loop finishes, the function returns the value of the `size` counter
 * variable, which represents the number of nodes in the linked list.
 *
 * @param list A pointer to the head of the linked list.
 * @return The size of the linked list.
 */
int size(node *list)
{
    // Initialize a counter variable to keep track of the number of nodes in the linked list
    int size = 0;

    // Begin the loop that iterates over each node of the linked list
    for (node *i = list->next; i != NULL; i = i->next)
    {
        // Increment the counter variable for the next iteration
        size++;
    }

    // Return the value of the counter variable, which represents the size of the linked list
    return size;
}

/**
 * Check if a linked list is empty.
 *
 * This function takes a pointer to the head of a linked list as its argument.
 * It checks if the `next` pointer of the head node is `NULL` (indicating that
 * there are no other nodes in the list), and returns `true` if it is, and
 * `false` otherwise.
 *
 * @param list A pointer to the head of the linked list.
 * @return `true` if the linked list is empty, `false` otherwise.
 */
bool is_empty(node *list)
{
    // Check if the `next` pointer of the head node is `NULL`
    return list->next == NULL;
}

/**
 * Find the value at a given index in a linked list.
 *
 * This function takes a pointer to the head of a linked list and an index as
 * its arguments. It iterates over each node of the linked list, keeping track
 * of the current position using a separate counter variable. When the
 * counter variable matches the provided index, the function returns the value
 * stored in that node. If the index is out of bounds (i.e., larger than the
 * number of nodes in the linked list), the function returns 0.
 *
 * @param list A pointer to the head of the linked list.
 * @param index The index of the node whose value should be returned.
 * @return The value stored at the node at the given index, or 0 if the index is out of bounds.
 */
int value_at(node *list, int index)
{
    // Initialize a counter variable to keep track of the current position in the linked list
    int curr_position = 0;

    // Begin the loop that iterates over each node of the linked list
    for (node *i = list->next; i != NULL; i = i->next)
    {
        // Check if the current position matches the provided index
        if (index == curr_position)
        {
            // If they match, return the value stored in the node
            return i->value;
        }

        // Increment the counter variable for the next iteration
        curr_position++;
    }

    // If the loop completes without finding a matching index, return 0
    return 0;
}

/**
 * Remove the node at the front of the linked list and return its value.
 *
 * This function takes a pointer to the head of the linked list as its argument.
 * It first stores the value of the node at the front of the list in a local
 * variable, then updates the `next` pointer of the head node to point to the
 * node after the current front node (i.e., the node that is currently second in
 * the list). Finally, it returns the stored value.
 *
 * @param list A pointer to the head of the linked list.
 * @return The value of the node that was at the front of the list.
 */
int pop_front(node *list)
{
    // Store the value of the node at the front of the list
    int return_value = list->next->value;

    // Update the `next` pointer of the head node to point to the node after
    // the current front node
    list->next = list->next->next;

    // Return the stored value
    return return_value;
}


/**
 * Returns the value of the node at the front of the linked list.
 *
 * This function takes a pointer to the head of the linked list as its argument.
 * It accesses the `value` field of the node that is second in the list (i.e., the
 * node that is currently at the front of the list) and returns its value.
 *
 * @param list A pointer to the head of the linked list.
 * @return The value of the node that is currently at the front of the list.
 */
int front(node *list)
{
    // Access the `value` field of the node that is second in the list
    // (i.e., the node that is currently at the front of the list)
    return list->next->value;
}

/**
 * This function removes the last node from a linked list and returns its value.
 * It takes a pointer to the head of the linked list as its argument.
 * It iterates through the linked list until it reaches the last node, stores the
 * value of that node in a local variable, and then sets the `next` pointer of the
 * second-to-last node to `NULL` to effectively remove the last node from the list.
 * Finally, it returns the stored value of the last node.
 *
 * @param list A pointer to the head of the linked list.
 * @return The value of the last node in the linked list.
 */
int pop_back(node *list)
{
    // Initialize a temporary pointer to the head of the linked list
    node *temp = list;

    // Iterate through the linked list until we reach the last node
    while (temp->next->next != NULL)
    {
        // Move the temporary pointer to the next node in the list
        temp = temp->next;
    }

    // Store the value of the last node in a local variable
    int val = temp->next->value;

    // Set the `next` pointer of the second-to-last node to `NULL` to remove
    // the last node from the list
    temp->next = NULL;

    // Return the stored value of the last node
    return val;
}

/**
 * This function adds a new node with the given value to the end of a linked list.
 * It takes a pointer to the head of the linked list as its first argument, and the
 * value to be stored in the new node as its second argument.
 * It creates a new node with the given value and sets its `next` pointer to `NULL`.
 * It then iterates through the linked list, moving along the `next` pointers until
 * it reaches the last node. At that point, it sets the `next` pointer of the last
 * node to point to the new node, effectively adding the new node to the end of the
 * list. Finally, it returns the pointer to the head of the linked list.
 *
 * @param list A pointer to the head of the linked list.
 * @param value The value to be stored in the new node.
 * @return A pointer to the head of the linked list.
 */
node *push_back(node *list, int value)
{
    // Create a new node with the given value and set its `next` pointer to `NULL`
    node *new_node = init_linked_list();
    new_node->value = value;
    new_node->next = NULL;

    // Iterate through the linked list, moving along the `next` pointers until
    // we reach the last node
    for (node *i = list->next; i != NULL; i = i->next)
    {
        // Check if we have reached the last node
        if (i->next == NULL)
        {
            // If we have, set the `next` pointer of the last node to point to the
            // new node, effectively adding the new node to the end of the list
            i->next = new_node;
            break;
        }
    }

    // Return the pointer to the head of the linked list
    return list;
}

/**
 * This function inserts a new node with the given value at a given index in the linked list.
 * It takes a pointer to the head of the linked list as its first argument, an index as its second argument,
 * and the value to be stored in the new node as its third argument.
 * It creates a new node with the given value and sets its `next` pointer to `NULL`.
 * It then iterates through the linked list, moving along the `next` pointers until it reaches the node at the given index.
 * If the index is 0, it inserts the new node at the front of the list by updating the `next` pointer of the head node to point to the new node.
 * If the index is 1, it inserts the new node after the first node in the list by updating the `next` pointer of the first node to point to the new node and the `next` pointer of the new node to point to the second node.
 * If the index is greater than 1, it inserts the new node between the current node and the next node by updating the `next` pointer of the current node to point to the new node and the `next` pointer of the new node to point to the next node.
 * Finally, it returns without any return value.
 *
 * @param list A pointer to the head of the linked list.
 * @param index The index at which the new node should be inserted.
 * @param value The value to be stored in the new node.
 */
void insert(node *list, int index, int value)
{
    // Create a new node with the given value and set its `next` pointer to `NULL`
    node *new_list = init_linked_list();
    new_list->value = value;
    new_list->next = NULL;

    // Initialize a counter variable to keep track of the current position in the linked list
    int curr_position = 0;

    // Begin the loop that iterates over each node of the linked list
    for (node *i = list->next; i != NULL; i = i->next)
    {
        // Check if the current position matches the provided index
        if(index==0){
            // If the index is 0, insert the new node at the front of the list by updating the `next` pointer of the head node to point to the new node
            new_list->next = i;
            list->next = new_list;
            break;
        }
        else if (index == curr_position+1)
        {
            // If the index is 1, insert the new node after the first node in the list by updating the `next` pointer of the first node to point to the new node and the `next` pointer of the new node to point to the second node
            new_list->next = i->next;
            i->next = new_list;
            break;
        }
        // Increment the counter variable for the next iteration
        curr_position++;
    }
}

/**
 * Erase the node at a given index in the linked list.
 *
 * This function takes a pointer to the head of a linked list and an index as
 * its arguments. It first checks if the linked list is empty or if the index
 * is negative. If either of these conditions is true, the function returns
 * without doing anything.
 *
 * The function then initializes a counter variable to keep track of the current
 * position in the linked list, and a pointer to the previous node (this
 * will be used to remove the node at the given index).
 *
 * The function then iterates over each node of the linked list, keeping track
 * of the current position using the counter variable and the previous node
 * using the `prev` pointer. When the counter variable matches the provided
 * index, the function removes the node by updating the `next` pointer of the
 * previous node to point to the node after the current node, and frees the
 * memory occupied by the current node. Finally, the function breaks out of the
 * loop.
 *
 * @param list A pointer to the head of the linked list.
 * @param index The index of the node to be erased.
 */
void erase(node *list, int index)
{
    // Check if the linked list is empty or if the index is negative
    if (list == NULL || index < 0) {
        return;
    }
    // Initialize counter and previous pointers
    int curr_position = 0;
    node *prev = NULL;
    // Iterate over each node of the linked list
    for (node *i = list->next; i != NULL; i = i->next) {
        // Check if the current position matches the provided index
        if (index == curr_position) {
            // If they match, remove the node
            if (prev == NULL) {
                // If the node to be removed is the first node
                list->next = i->next;
            } else {
                // If the node to be removed is not the first node
                prev->next = i->next;
            }
            // Free the memory occupied by the current node
            free(i);
            break;
        }
        // Move to the next node
        prev = i;
        curr_position++;
    }
}

int value_n_from_end(node *list, int index)
{
    return value_at(list, size(list) - index);
}

/**
 * Reverse the linked list.
 *
 * This function creates a new linked list, copies the values from the original
 * linked list to an array, reverses the array, and then constructs the reversed
 * linked list from the array. Finally, it frees the original linked list and
 * returns the reversed linked list.
 *
 * @param list The linked list to be reversed.
 * @return The reversed linked list.
 */
node *reverse(node *list)
{
    // Create a new linked list to store the reversed linked list.
    node *reversed = init_linked_list();

    // Create an array to store the values from the original linked list.
    int arr[size(list) - 1];

    // Iterate through the original linked list and store the values in the array.
    int j = 0;
    for (node *i = list->next; i != NULL; i = i->next)
    {
        arr[j] = i->value;
        j++;
    }

    // Reverse the array.
    for (int i = size(list) - 1; i >= 0; i--)
    {
        // Push the reversed array values onto the front of the new linked list.
        push_front(reversed, arr[i]);
    }

    // Free the original linked list.

    // Update the pointer to the original linked list to point to the new linked list.
    list = reversed;

    // Return the new reversed linked list.
    return list;
}

/**
 * This function removes all occurrences of a specified value from a linked list.
 *
 * @param list A pointer to the head of the linked list.
 * @param value The value to be removed from the linked list.
 */
void remove_value(node *list, int value)
{
    // Iterate through the linked list
    for (int i = 0; i < size(list); i++)
    {
        // Check if the value at the current index is equal to the specified value
        if (value_at(list, i) == value)
        {
            // If the values match, erase the node at the current index
            erase(list, i);
        }
    }
}
int main(void)
{
    return 0;
}
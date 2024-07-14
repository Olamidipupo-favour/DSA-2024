#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *init_linked_list()
{
    node *list = malloc(sizeof(node));
    list->next = NULL;
    return list;
}

node *push_front(node *list, int value)
{
    node *new_node = init_linked_list();
    new_node->value = value;
    new_node->next = list->next;
    list->next = new_node;
    return list;
}

void print_linked_list(node *list)
{
    int j = 0;
    for (node *i = list->next; i != NULL; i = i->next)
    {
        printf("index %i : %i \n", j, i->value);
        j++;
    }
}

int size(node *list)
{
    int size = 0;
    for (node *i = list->next; i != NULL; i = i->next)
    {
        size++;
    }
    return size;
}

bool is_empty(node *list)
{
    return list->next == NULL;
}

int value_at(node *list, int index)
{
    int curr_position = 0;
    for (node *i = list->next; i != NULL; i = i->next)
    {
        if (index == curr_position)
        {
            return i->value;
        }
        curr_position++;
    }
}

int pop_front(node *list)
{
    int return_value = list->next->value;
    list->next = list->next->next;
    return return_value;
}

int front(node *list)
{
    return list->next->value;
}

int pop_back(node *list)
{
    for (node *i = list->next; i != NULL; i = i->next)
    {
        if (i->next == NULL)
        {
            int val = i->value;
            i = NULL;
            return val;
        }
    }
}

node *push_back(node *list, int value)
{
    node *new_node = init_linked_list();
    new_node->value = value;
    for (node *i = list->next; i != NULL; i = i->next)
    {
        if (i->next == NULL)
        {
            i->next = new_node;
            break;
        }
    }
    return list;
}

void insert(node *list, int index, int value)
{
    node *new_list = init_linked_list();
    new_list->value = value;
    new_list->next = NULL;
    int curr_position = 0;
    for (node *i = list->next; i != NULL; i = i->next)
    {
        if(index==0){
            new_list->next = i;
            list->next = new_list;
            break;
        }
        else if (index == curr_position+1)
        {
            new_list->next = i->next;
            i->next = new_list;
            break;
        }
        curr_position++;
    }
}

void erase(node *list, int index)
{
    if (list == NULL || index < 0) {
        return;
    }
    int curr_position = 0;
    node *prev = NULL;
    for (node *i = list->next; i != NULL; i = i->next) {
        if (index == curr_position) {
            if (prev == NULL) {
                list->next = i->next;
            } else {
                prev->next = i->next;
            }
            free(i);
            break;
        }
        prev = i;
        curr_position++;
    }
}

int value_n_from_end(node *list, int index)
{
    return value_at(list, size(list) - index);
}

node *reverse(node *list)
{
    node *reversed = init_linked_list();
    int arr[size(list)];
    int j = 0;
    for (node *i = list->next; i != NULL; i = i->next)
    {
        arr[j] = i->value;
        j++;
    }
    for (int i = size(list) - 1; i >= 0; i++)
    {
        push_front(reversed, arr[i]);
    }
    free(list);
    list = reversed;
    return list;
}

void remove_value(node *list, int value)
{
    for (int i = 0; i < size(list); i++)
    {
        if (value_at(list, i) == value)
        {
            erase(list, i);
        }
    }
}
int main(void)
{
    node *list = init_linked_list();
    push_front(list, 13);
    push_front(list, 14);
    push_front(list, 15);
    push_front(list, 16);
    push_front(list, 17);
    push_front(list, 18);
    push_front(list, 19);
    push_front(list, 20);
    insert(list,1,21);
    // print_linked_list(list);
    printf("%i", pop_back(list));
    //print_linked_list(list);
    return 0;
}
#ifndef CTEST_LINKEDLIST_H
#define CTEST_LINKEDLIST_H

#include "stdio.h"
#include "stdlib.h"

struct Node{
    void* value;
    struct Node* next;
    struct Node* prev;
};

struct LinkedList{
    __uint32_t curr_length;
    struct Node** nodes;
};

struct LinkedList* NewList();
void AddToList(struct LinkedList* list, void* value);
void* GetValueFromAt(struct LinkedList* list, __uint32_t index);
void RemoveValueFromListAt(struct LinkedList* list, __uint32_t index);

#endif //CTEST_LINKEDLIST_H

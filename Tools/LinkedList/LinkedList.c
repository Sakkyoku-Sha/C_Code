#include "LinkedList.h"

struct LinkedList* NewList(){
    struct LinkedList* list = malloc(sizeof(struct LinkedList));

    list->curr_length = 0;
    list->nodes = malloc(sizeof(struct Node*));

    return list;
}

void AddToList(struct LinkedList* list, void* value){

    //This is naive, should probably realloc a larger amount each time and each curr_length;
    list->nodes = realloc(list->nodes, sizeof(struct Node*)*(list->curr_length+1));

    //Create the next node in the list and set it's value
    struct Node* nextNode = malloc(sizeof(struct Node));
    nextNode->value = value;

    //Add values to the end of the list
    if(list->curr_length > 0) {
        struct Node *lastNode = list->nodes[list->curr_length - 1];
        lastNode->next = nextNode;

        //Append the new node to the end of the list
        nextNode->prev = lastNode;
    }

    //Modify the list to include the new node
    list->nodes[list->curr_length] = nextNode;
    list->curr_length+=1;

}

void* GetValueFromAt(struct LinkedList* list, __uint32_t index){
    return list->nodes[index]->value;
}

void RemoveValueFromListAt(struct LinkedList* list, __uint32_t index){

    if(index == list->curr_length-1){
        free(list->nodes[index]);
        list->curr_length--;
    }
    else if(index != 0){
        list->nodes[index-1]->next = list->nodes[index]->next;
        list->nodes[index+1]->prev = list->nodes[index]->prev;
    }

    free(list->nodes[index]);

    for(int i = 1; i < list->curr_length; i++){
        list[i-1] = list[i];
    }

    list->curr_length--;

    //Aggressive resizing.
    list->nodes = realloc(list->nodes, sizeof(struct Node*)*(list->curr_length));
}

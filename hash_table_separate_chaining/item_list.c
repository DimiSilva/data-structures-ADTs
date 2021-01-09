#include <stdio.h>
#include <stdlib.h>
#include "item_list.h"
#include "data_structs.h"

ItemList* itemListCreate() {
    ItemList* list = (ItemList*) malloc(sizeof(ItemList));

    list->length = 0;
    list->head = NULL;
    list->end = NULL;

    return list;
}

void itemListPrint(ItemList* list){
    ItemListNode *nodePointer = list->head;

    if(nodePointer == NULL){
        printf("[]");
        return;
    }

    printf("[ ");
    while(nodePointer != NULL) {
        printf("id %d, nome %s", nodePointer->value->id, nodePointer->value->name);
        nodePointer = nodePointer->next;
        if(nodePointer != NULL) printf(", ");
        printf("\n");
    }
    printf(" ]");
}

void itemListUnshift(ItemList* list, Item *value) {
    ItemListNode* node = (ItemListNode*) malloc(sizeof(ItemListNode));
    node->value = value;
    node->next = NULL;
    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->end = node;
        return;
    }

    ItemListNode *firstNode =  list->head;
    node->next = firstNode;
    list->head = node;
}

void itemListPush(ItemList* list, Item *value) {
    ItemListNode* node = (ItemListNode*) malloc(sizeof(ItemListNode));
    node->value = value;
    node->next = NULL;
    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->end = node;
        return;
    }

    ItemListNode *lastNode =  list->end;
    lastNode->next = node;
    list->end = node;
}

Item* itemListFindByIndex (ItemList* list,  int index) {
    int currentPosition = 0;
    ItemListNode* itemListCurrentNode = NULL;
    while(currentPosition <= index)
    {
        if(itemListCurrentNode  == NULL) itemListCurrentNode  = list->head;
        else itemListCurrentNode  = itemListCurrentNode ->next;

        ++currentPosition;
        continue;
    }

    return itemListCurrentNode ->value;
}

ItemListNode* itemListFindNodeByIndex (ItemList* list,  int index) {
    int currentPosition = 0;
    ItemListNode* itemListNode = NULL;
    while(currentPosition <= index)
    {
        if(itemListNode == NULL) itemListNode = list->head;
        else itemListNode = itemListNode->next;

        ++currentPosition;
        continue;
    }

    return itemListNode;
}


void itemListRemoveElement(ItemList* list, int index) {
    int currentPosition = 0;

    ItemListNode* itemListBehindNode = NULL;
    ItemListNode* itemListCurrentNode = NULL;
    while(currentPosition <= index)
    {
        if(itemListCurrentNode  == NULL) itemListCurrentNode  = list->head;
        else {
            itemListBehindNode = itemListCurrentNode;
            itemListCurrentNode  = itemListCurrentNode ->next;
        }

        ++currentPosition;
        continue;
    }

    if(itemListBehindNode != NULL) itemListBehindNode->next = itemListCurrentNode->next;
    else list->head = NULL;
}

ItemList* itemListConcat(ItemList* list1, ItemList* list2) {
    list1->end->next = list2->head;
    list1->end = list2->end;
    return list1;
}

ItemList* itemListCopy(ItemList* list1, ItemList* list2) {
    list1->head = NULL;
    list1->end = NULL;
    list1->length = 0;

    ItemListNode *nodePointer = list2->head;

    while(nodePointer != NULL) {
        itemListPush(list1, nodePointer->value);
        nodePointer = nodePointer->next;
    }

    return list1;
}


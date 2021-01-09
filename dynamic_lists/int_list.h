#include <stdio.h>
#include <stdlib.h>

typedef struct IntListNodeStruct {
    int value;
    struct IntListNodeStruct* next;
} IntListNode;

typedef struct IntListStruct{
    int length;
    IntListNode *head;
    IntListNode *end;
} IntList;

IntList* intListCreate() {
    IntList* list = (IntList*) malloc(sizeof(IntList));

    list->length = 0;
    list->head = NULL;
    list->end = NULL;

    return list;
}

void intListPrint(IntList* list){
    IntListNode *nodePointer = list->head;

    if(nodePointer == NULL){
        printf("[]");
        return;
    }

    printf("[ ");
    while(nodePointer != NULL) {
        printf("%d", nodePointer->value);
        nodePointer = nodePointer->next;
        if(nodePointer != NULL) printf(", ");
    }
    printf(" ]");
}

void intListUnshift(IntList* list, int value) {
    IntListNode* node = (IntListNode*) malloc(sizeof(IntListNode));
    node->value = value;
    node->next = NULL;
    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->end = node;
        return;
    }

    IntListNode *firstNode =  list->head;
    node->next = firstNode;
    list->head = node;
}

void intListPush(IntList* list, int value) {
    IntListNode* node = (IntListNode*) malloc(sizeof(IntListNode));
    node->value = value;
    node->next = NULL;
    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->end = node;
        return;
    }

    IntListNode *lastNode =  list->end;
    lastNode->next = node;
    list->end = node;
}

int intListFindByIndex (IntList* list,  int index) {
    int currentPosition = 0;
    IntListNode* intListCurrentNode = NULL;
    while(currentPosition <= index)
    {
        if(intListCurrentNode  == NULL) intListCurrentNode  = list->head;
        else intListCurrentNode  = intListCurrentNode ->next;

        ++currentPosition;
        continue;
    }

    return intListCurrentNode ->value;
}

void intListRemoveElement(IntList* list, int index) {
    int currentPosition = 0;

    IntListNode* intListBehindNode = NULL;
    IntListNode* intListCurrentNode = NULL;
    while(currentPosition <= index)
    {
        if(intListCurrentNode  == NULL) intListCurrentNode  = list->head;
        else {
            intListBehindNode = intListCurrentNode;
            intListCurrentNode  = intListCurrentNode ->next;
        }

        ++currentPosition;
        continue;
    }

    if(intListBehindNode != NULL) intListBehindNode->next = intListCurrentNode->next;
    else list->head = NULL;
}

IntList* intListConcat(IntList* list1, IntList* list2) {
    list1->end->next = list2->head;
    list1->end = list2->end;
    return list1;
}

IntList* intListCopy(IntList* list1, IntList* list2) {
    list1->head = NULL;
    list1->end = NULL;
    list1->length = 0;

    IntListNode *nodePointer = list2->head;

    while(nodePointer != NULL) {
        intListPush(list1, nodePointer->value);
        nodePointer = nodePointer->next;
    }

    return list1;
}

void intListSort(IntList* list) {
    int changedTimes = 0;

    if(list->head == NULL) return;

    IntListNode* currentNode = list->head;

    do {
        changedTimes = 0;
        currentNode = list->head;
        while(currentNode != NULL) {
            if( currentNode->next != NULL && currentNode->value > currentNode->next->value){
                int tempValue = currentNode->value;
                currentNode->value = currentNode->next->value;
                currentNode->next->value = tempValue;
                changedTimes++;
            }
            currentNode = currentNode->next;
        }
    } while (changedTimes > 0);
}

IntListNode* intListFindNodeByIndex (IntList* list,  int index) {
    int currentPosition = 0;
    IntListNode* intListNode = NULL;
    while(currentPosition <= index)
    {
        if(intListNode == NULL) intListNode = list->head;
        else intListNode = intListNode->next;

        ++currentPosition;
        continue;
    }

    return intListNode;
}

void intListInsertOrdered (IntList* list,  int value) {
    IntListNode* node = (IntListNode*) malloc(sizeof(IntListNode));
    node->value = value;
    node->next = NULL;
    list->length++;

    if(list->head == NULL) {
        list->head = node;
        list->end = node;
        return;
    }

    if(value < list->head->value) {
        node->next = list->head;
        list->head = node;
        return;
    }

    if(value> list->end->value) {
        list->end->next = node;
        list->end = node;
        return;;
    }

    IntListNode* currentNode = list->head;

    while(currentNode != NULL)
    {
        if(currentNode->next->value > value) {
            node->next = currentNode->next;
            currentNode->next = node;
            break;
        }
        currentNode = currentNode->next;
    }
}


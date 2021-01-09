#include <stdio.h>
#include <stdlib.h>

typedef struct IntListListNodeStruct {
    IntList* value;
    struct IntListListNodeStruct* next;
    struct intListListNodeStruct* previous;
} IntListListNode;

typedef struct structIntListList {
    int length;
    IntListListNode *head;
    IntListListNode *end;
} IntListList;

IntListList* intListListCreate() {
    IntListList* list = (IntListList*) malloc(sizeof(IntListList));

    list->length = 0;
    list->head = NULL;
    list->end = NULL;

    return list;
}

void intListListPrint(IntListList* list){
    IntListListNode *nodePointer = list->head;
    if(nodePointer == NULL){
        printf("[]");
        return;
    }

    printf("[\n");
    while(nodePointer != NULL) {
        printf("\t");

        intListPrint(nodePointer->value);
        nodePointer = nodePointer->next;

        if(nodePointer != NULL) printf("\n");
    }
    printf("\n]");
}

void intListListUnshift(IntListList* list, IntList* value) {
    IntListListNode* node = (IntListListNode*) malloc(sizeof(IntListListNode));
    node->value = value;
    node->next = NULL;
    node->previous=NULL;
    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->end = node;
        return;
    }

    IntListListNode *firstNode =  list->head;
    firstNode->previous = node;
    node->next = firstNode;
    list->head = node;
}

void intListListPush(IntListList* list, IntList* value) {
    IntListListNode* node = (IntListListNode*) malloc(sizeof(IntListListNode));
    node->value = value;
    node->next = NULL;
    node->previous=NULL;
    list->length++;

    if (list->head == NULL) {
        list->head = node;
        list->end = node;
        return;
    }

    IntListListNode* lastNode =  list->end;
    lastNode->next = node;
    node->previous = lastNode;
    list->end = node;
}

IntList* intListListFindByIndex (IntListList* list,  int index) {
    int currentPosition = 0;
    IntListListNode* intListListNode = NULL;
    while(currentPosition <= index)
    {
        if(intListListNode == NULL) intListListNode = list->head;
        else intListListNode = intListListNode->next;

        ++currentPosition;
        continue;
    }

    return intListListNode->value;
}

void intListListRemoveElement(IntListList* list, int index) {
    int currentPosition = 0;

    IntListListNode* intListListBehindNode = NULL;
    IntListListNode* intListListCurrentNode = NULL;
    while(currentPosition <= index)
    {
        if(intListListCurrentNode  == NULL) intListListCurrentNode  = list->head;
        else {
            intListListBehindNode = intListListCurrentNode;
            intListListCurrentNode  = intListListCurrentNode ->next;
        }

        ++currentPosition;
        continue;
    }

    if(intListListBehindNode != NULL) {
        if(intListListCurrentNode->next != NULL){
            intListListBehindNode->next = intListListCurrentNode->next;
            intListListBehindNode->next->previous = intListListBehindNode;
        }
        else{
            intListListBehindNode->next = NULL;
            list->end = intListListBehindNode;
        }
    }
    else list->head = NULL;
    list->length--;
}

void intListListConcatIntLists (IntListList* intListList, int index1, int index2) {
    IntList* intList1 = intListListFindByIndex(intListList, index1);
    IntList* intList2 = intListListFindByIndex(intListList, index2);
    intListConcat(intList1, intList2);
    intListListRemoveElement(intListList, index2);
}

void intListListCopyLists (IntListList* intListList, int index1, int index2) {
    IntList* intList1 = intListListFindByIndex(intListList, index1);
    IntList* intList2 = intListListFindByIndex(intListList, index2);
    intListCopy(intList1, intList2);
}

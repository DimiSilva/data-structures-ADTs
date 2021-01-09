#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///////////////////////////////////////STRUCTS
typedef struct QueueNodeStruct{
    int value;
    struct QueueNodeStruct* next;
} QueueNode;

typedef struct QueueStruct{
    int length;
    struct QueueNode* begin;
    struct QueueNode* end;
} Queue;

typedef struct StackNodeStruct{
    int value;
    struct StackNodeStruct* next;
} StackNode;

typedef struct StackStruct{
    int length;
    struct StackNode* top;
} Stack;

///////////////////////////////////////STATEMENTS
QueueNode* createQueueNode(int value);
Queue* createQueue();
void printQueue(Queue* queue);
void inQueue(Queue* queue, int value);
int outQueue(Queue* queue);
bool isEmptyQueue(Queue* queue);

StackNode* createStackNode(int value);
Stack* createStack();
void printStack(Stack* stack);
void pushStack(Stack* stack, int value);
int popStack(Stack* stack);
bool isEmptyStack(Stack* stack);

///////////////////////////////////////MAIN
int main() {
    Queue* queue = createQueue();
    isEmptyQueue(queue);
    printQueue(queue);
    inQueue(queue, 1);
    printQueue(queue);
    inQueue(queue, 12);
    printQueue(queue);
    inQueue(queue, 4);
    printQueue(queue);
    inQueue(queue, 5);
    printQueue(queue);
    inQueue(queue, 8);
    printQueue(queue);
    outQueue(queue);
    printQueue(queue);
    isEmptyQueue(queue);

    printf("\n");

    Stack* stack = createStack();
    isEmptyStack(stack);
    printStack(stack);
    pushStack(stack, 1);
    printStack(stack);
    pushStack(stack, 12);
    printStack(stack);
    pushStack(stack, 4);
    printStack(stack);
    pushStack(stack, 5);
    printStack(stack);
    pushStack(stack, 8);
    printStack(stack);
    popStack(stack);
    printStack(stack);
    isEmptyQueue(stack);

}

///////////////////////////////////////FUNCTIONS

QueueNode* createQueueNode(int value) {
    QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
    node->next = NULL;
    node->value = value;
    return node;
}

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));

    queue->length = 0;
    queue->begin = NULL;
    queue->end = NULL;

    return queue;
}

void printQueue(Queue* queue){
    QueueNode* nodePointer = queue->begin;

    if(nodePointer == NULL){
        printf("[]\n");
        return;
    }

    printf("[ ");
    while(nodePointer != NULL) {
        printf("%d", nodePointer->value);
        nodePointer = nodePointer->next;
        if(nodePointer != NULL) printf(", ");
    }
    printf(" ]\n");
}

void inQueue(Queue* queue, int value ){
    QueueNode* node = createQueueNode(value);
    queue->length++;

    if(queue->begin == NULL) {
        queue->begin = node;
        queue->end = node;
        return;
    }
    QueueNode*lastNode =  queue->end;
    lastNode->next = node;
    queue->end = node;
}

int outQueue(Queue* queue) {
    QueueNode* beginNode = queue->begin;
    if(beginNode != NULL){
        queue->begin = beginNode->next;
        queue->length--;
        return beginNode->value;
    }
    return NULL;
}

bool isEmptyQueue(Queue* queue) {
    return queue->length == 0;
}

StackNode* createStackNode(int value){
    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    node->next = NULL;
    node->value = value;
    return node;
}

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    stack->length = 0;
    stack->top = NULL;

    return stack;
}

void printStack(Stack* stack) {
    StackNode* nodePointer = stack->top;

    if(nodePointer == NULL){
        printf("[]\n");
        return;
    }

    printf("[ ");
    while(nodePointer != NULL) {
        printf("%d", nodePointer->value);
        nodePointer = nodePointer->next;
        if(nodePointer != NULL) printf(", ");
    }
    printf(" ]\n");
}

void pushStack(Stack* stack, int value) {
    StackNode* node = createStackNode(value);
    stack->length++;

    if(stack->top == NULL) {
        stack->top = node;
        return;
    }
    StackNode*topNode =  stack->top;
    node->next = topNode;
    stack->top = node;
}

int popStack(Stack* stack) {
    StackNode* topNode = stack->top;
    if(topNode != NULL){
        stack->top= topNode->next;
        stack->length--;
        return topNode->value;
    }
    return NULL;
}

bool isEmptyStack(Stack* stack) {
    return stack->length == 0;
}

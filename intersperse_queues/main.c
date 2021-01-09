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

///////////////////////////////////////STATEMENTS
QueueNode* createQueueNode(int value);
Queue* createQueue();
void printQueue(Queue* queue);
void inQueue(Queue* queue, int value);
int outQueue(Queue* queue);
bool isEmptyQueue(Queue* queue);
Queue* interperseQueues(Queue* queue1, Queue* queue2);

///////////////////////////////////////MAIN
int main() {
    Queue* queue1 = createQueue();
    Queue* queue2 = createQueue();
    inQueue(queue1, 1);
    inQueue(queue1, 12);
    inQueue(queue1, 4);
    inQueue(queue1, 5);
    inQueue(queue1, 8);
    inQueue(queue2, 7);
    inQueue(queue2, 52);
    inQueue(queue2, 3);
    inQueue(queue2, 8);
    inQueue(queue2, 10);
    printQueue(queue1);
    printQueue(queue2);
    Queue* interspersedQueue = interperseQueues(queue1, queue2);
    printQueue(interspersedQueue);
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

Queue* interperseQueues(Queue* queue1, Queue* queue2) {
    Queue* interspersedQueue = createQueue();

    QueueNode* currentNodeQueue1 = queue1->begin;
    QueueNode* currentNodeQueue2 = queue2->begin;

    while(currentNodeQueue1 != NULL || currentNodeQueue2 != NULL) {
        if(currentNodeQueue1 != NULL) {
            inQueue(interspersedQueue, currentNodeQueue1->value);
            currentNodeQueue1 = currentNodeQueue1->next;
        }
        if(currentNodeQueue2 != NULL) {
            inQueue(interspersedQueue, currentNodeQueue2->value);
            currentNodeQueue2 = currentNodeQueue2->next;
        }
    }

    return interspersedQueue;
}

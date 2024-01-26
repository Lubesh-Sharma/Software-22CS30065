#ifndef QUEUE_H
#define QUEUE_H

#include "defs.h"

typedef struct {
    nodep front; // Pointer to the beginning of the linked list
    nodep back;  // Pointer to the end of the linked list
} queue;

extern queue initqueue();
extern int emptyqueue(queue);
extern int front(queue);
extern queue enqueue(queue, int);
extern queue dequeue(queue);
extern void printqueue(queue);
extern queue destroyqueue(queue);

#endif // QUEUE_H

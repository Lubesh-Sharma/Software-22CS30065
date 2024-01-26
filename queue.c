#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "queue.h"

queue initqueue() {
    queue Q;
    Q.front = Q.back = NULL; // Initialize an empty queue
    return Q;
}

int emptyqueue(queue Q) {
    return Q.front == NULL; // Queue is empty if front is NULL
}

int front(queue Q) {
    if (emptyqueue(Q)) {
        fprintf(stderr, "Error: Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    return Q.front->data; // Return the data at the front of the queue
}

queue enqueue(queue Q, int value) {
    nodep newNode = (nodep)malloc(sizeof(node));
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (emptyqueue(Q)) {
        Q.front = Q.back = newNode;
    } else {
        Q.back->next = newNode;
        Q.back = newNode;
    }

    return Q; // Return the updated queue
}

queue dequeue(queue Q) {
    if (emptyqueue(Q)) {
        fprintf(stderr, "Error: Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    nodep temp = Q.front;
    Q.front = Q.front->next;
    free(temp);
    if (Q.front == NULL) {
        Q.back = NULL; // If the queue becomes empty, update back as well
    }
    return Q; // Return the updated queue
}

void printqueue(queue Q) {
    printf("Queue: ");
    nodep current = Q.front;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

queue destroyqueue(queue Q) {
    while (Q.front) {
        nodep temp = Q.front;
        Q.front = Q.front->next;
        free(temp);
    }
    Q.back = NULL; // Update back to NULL to indicate the queue is destroyed
    return Q;
}

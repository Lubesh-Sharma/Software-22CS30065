#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "stack.h"

stack initstack() {
    return NULL; // Initialize an empty stack as NULL
}

int emptystack(stack S) {
    return S == NULL; // Stack is empty if it is NULL
}

int top(stack S) {
    if (emptystack(S)) {
        fprintf(stderr, "Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return S->data; // Return the data at the top of the stack
}

stack push(stack S, int value) {
    nodep newNode = (nodep)malloc(sizeof(node));
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = S;
    return newNode; // Return the updated stack
}

stack pop(stack S) {
    if (emptystack(S)) {
        fprintf(stderr, "Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    nodep temp = S;
    S = S->next;
    free(temp);
    return S; // Return the updated stack
}

void printstack(stack S) {
    printf("Stack: ");
    while (S) {
        printf("%d ", S->data);
        S = S->next;
    }
    printf("\n");
}

stack destroystack(stack S) {
    while (S) {
        nodep temp = S;
        S = S->next;
        free(temp);
    }
    return NULL; // Return NULL to indicate the stack is destroyed
}

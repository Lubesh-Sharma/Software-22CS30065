#ifndef STACK_H
#define STACK_H

#include "defs.h"

typedef nodep stack; // Pointer to the beginning of the linked list

extern stack initstack();
extern int emptystack(stack);
extern int top(stack);
extern stack push(stack, int);
extern stack pop(stack);
extern void printstack(stack);
extern stack destroystack(stack);

#endif // STACK_H

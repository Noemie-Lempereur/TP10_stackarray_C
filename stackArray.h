#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef TP10_2_STACKARRAY_H
#define TP10_2_STACKARRAY_H

#define MAX_SIZE 30

struct Stack{
    int size;
    int elems[MAX_SIZE];
};


struct Stack* createEmptyStack();

void push(struct Stack* s, int item, bool* valid);

int top(struct Stack* s, bool* valid);

int pop(struct Stack *s, bool* valid);

int stackSize(struct Stack* s);

bool isStackEmpty(struct Stack* s);

void printStack(struct Stack* s);

void deleteStack(struct Stack* q);


#endif //TP10_2_STACKARRAY_H

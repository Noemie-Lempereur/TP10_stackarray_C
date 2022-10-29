#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackArray.h"

struct Stack* createEmptyStack(){
    struct Stack* stack =malloc(sizeof(struct Stack));
    if (stack!=NULL){
        stack->size=0;
    }
    return stack;
}

void push(struct Stack* s, int item, bool* valid){
    int size=s->size;
    if((s!=NULL)&&(size<MAX_SIZE)) {
        s->elems[size]=item;
        s->size=s->size+1;
        *valid=true;
        return;
    }
    *valid=false;
}

int top(struct Stack* s, bool* valid){
    if((s!=NULL)&&(isStackEmpty(s)==false)) {
        *valid=true;
        return s->elems[s->size - 1];
    }
    *valid=false;
    return -1;
}

int pop(struct Stack *s, bool* valid){
    if(s!=NULL) {
        int a;
        bool b;
        bool *vali = &b;
        a=top(s,vali);
        if(*vali==true) {
            s->size = s->size - 1;
            *valid = true;
            return a;
        }
    }
    *valid=false;
    return -1;
}

int stackSize(struct Stack* s) {
    if (s != NULL) {
        return s->size;
    }
    return -1;
}

bool isStackEmpty(struct Stack* s){
    if((stackSize(s)==0)&&(s!=NULL)){
        return true;
    }
    return false;
}

void printStack(struct Stack* s){
    if (s != NULL) {
        if (isStackEmpty(s)==true){
            printf("NULL <- top\n");
        }
        for(int k=stackSize(s)-1;k>=0;k--){
            printf("%d",s->elems[k]);
            if(k==stackSize(s)-1){
                printf(" <- top\n");
            }
            else{
                printf("\n");
            }
        }
    }
}

void deleteStack(struct Stack* q){
    if(q!=NULL){
        q->size=0;
        free(q);
    }
}
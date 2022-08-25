#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    StackElement *next;
} StackElement;

typedef struct {
    StackElement *top;
} Stack;

Stack *initializeStack() {
    Stack *S = malloc(sizeof(Stack));
    S->top = NULL;
    return S;
}

void push(Stack *S, int val) {
    StackElement *a = malloc(sizeof(StackElement));
    a->val = val;
    a->next = S->top;
    S->top = a;
}

int pop(Stack *S) {
    StackElement *tmp = S->top;
    int val = S->top->val;
    S->top = S->top->next;
    free(tmp);
    return val;
}

void deleteStack(Stack *S) {
    while(S->top != NULL) {
        pop(S);
    }
    free(S);
}

void printStack(Stack *S) {
    StackElement *tmp = S->top;
    printf("Stack: \n");
    while(tmp != NULL) {
        printf("%d\n", tmp->val);
        tmp = tmp->next;
    }
    printf("________\n");
}

int top(Stack *S) {
    int erg = 0;
    if(S->top == NULL) {
        erg = -1;
    } else {
        erg = S->top->val;
    }
    return erg;
}

int main() {
    Stack *S = initializeStack();
    
    push(S, 4);
    push(S, 11);
    push(S, 3);
    printStack(S);
    top(S);

    pop(S);
    pop(S);
    printStack(S);
    top(S);

    push(S, 4);
    printStack(S);
    top(S);

    deleteStack(S);

    return 0;
}
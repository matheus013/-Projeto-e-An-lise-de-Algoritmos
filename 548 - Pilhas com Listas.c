#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY_SIZE 256

typedef struct node Node;
struct node {
    char item[MAX_ARAY_SIZE];
    Node *next;
};

typedef struct stack Stack;
struct stack {
    Node *top;
};

Stack* create() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void isEmpty(Stack *stack) {
    if (stack->top == NULL)
        printf("EMPTY STACK\n");
}

void push (Stack *stack, char item[]) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->item, item);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop (Stack *stack) {
    if (stack->top != NULL) {
        printf("%s", stack->top->item);
        printf("\n");
        Node *p = stack->top;
        stack->top = stack->top->next;
        free(p);
    }
    else
        printf("EMPTY STACK\n");
}

int peek(Stack *stack) {
    return (stack->top != NULL) ? (int) stack->top->item : -1;
}

void goPush(){
    char arr[MAX_ARRAY_SIZE];
    gets(arr);
    push(stack,arr);
}
int main() {
    int i;
    Stack *stack = create();

    char str[MAX_ARRAY_SIZE];

    while(scanf("%s", str) != EOF){
        getchar();
        (strcmp(str,"PUSH") == 0) ? goPush() : pop(stack);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct stack Stack;
int isEmpty(Stack *stack);
Stack* create();
void push (Stack *stack, int item);
int pop (Stack *stack);
int peek(Stack *stack) ;
void freeStack(Stack *stack);

int isValid(Stack *stk , char *str, char *oper){
    for (int i = 0; i < strlen(str); ++i) {
        if(str[i] == oper[0])
            push(stk,str[i]);
        if(str[i] == oper[1]){
            if(isEmpty(stk)) return 0;
            pop(stk);
        }
    }
    return isEmpty(stk);
}
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for (int var = 0; var < n; ++var) {
        char str[1000];
        gets(str);
        if(isValid(create() , str, "()") && isValid(create() , str, "[]"))
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

struct node {
    int item;
    Node *next;
};

struct stack {
    Node *top;
};

Stack* create() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack *stack) {
    if (stack->top == NULL)
        return 1;
    else
        return 0;
}

void push (Stack *stack, int item) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop (Stack *stack) {
    if (!isEmpty(stack)) {
        int x = stack->top->item;
        Node *p = stack->top;
        stack->top = stack->top->next;
        free(p);
        return x;
    }
    else
        return -1;
}

int peek(Stack *stack) {
    if (!isEmpty(stack))
        return stack->top->item;
    else
        return -1;
}

void freeStack(Stack *stack) {
    while(peek(stack) != -1)
        pop(stack);
}
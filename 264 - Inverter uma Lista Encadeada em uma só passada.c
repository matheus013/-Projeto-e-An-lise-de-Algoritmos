#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int item;
    Node *next;
};

Node* insert(Node *first, int item){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = first;
    return newNode;
}
Node* build(){
    return NULL;
}
void print(Node *first) {
    if (first != NULL) {
        printf("%d ", first->item);
        print(first->next);
    }
}
int main()
{
    int c;
    Node* list = build();

    while(scanf("%d",&c) != EOF)
        list = insert(list, c);
    print(list);
    printf("\n");
}

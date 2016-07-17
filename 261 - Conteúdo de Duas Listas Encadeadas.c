#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int item;
    Node *nextNode;
};

Node* insertNode(Node *first, int item){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = first;
    return newNode;
}

int conteins(Node *first, int n) {
    Node* curr;
    for (curr = first; curr != NULL; curr = curr->nextNode)
        if(curr->item == n) return 1;
    return 0;
}

int subConj(Node *a, Node *b){
    Node* curr;
    for (curr = b; curr != NULL; curr = curr->nextNode)
        if(!conteins(a,curr->item)) return 0;
    return 1;
}

int main() {
    Node *a = NULL;
    Node *b = NULL;
    int n;
    scanf("%d", &n);
    while(n--) {
        int aux;
        scanf("%d",&aux);
        a =insertNode(a,aux);
    }
    scanf("%d", &n);
    while(n--) {
        int aux;
        scanf("%d",&aux);
        b =insertNode(b,aux);
    }
    subConj(a,b) ? printf("1\n") : printf("0\n");
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int item;
    Node *nextNode;
};

void swap(int *i, int *j) {
   int t = *i;
   *i = *j;
   *j = t;
}

Node* insertNode(Node *first, int item){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item = item;
    newNode->nextNode = first;
    return newNode;
}

void printLinkedList(Node *first){
    if(first != NULL){
        printf("%d ", first->item);
        printLinkedList(first-> nextNode);
    }
}
void trade(Node *a, Node *b){
    swap(a->item, b->item);
}

void sort(Node *first, int size) {
    Node *curr = NULL;
    while(--size){
        curr = first;
        while(curr != NULL) {
            Node *next = curr->nextNode;
            if(next == NULL) break;
            if(curr->item > next->item)
                trade(&curr, &next);
            curr = next;
        }
    }
}
int main() {
    Node *a = NULL;
    int aux, size = 0;
    while(scanf("%d",&aux) != EOF) {
        a = insertNode(a,aux);
        size++;
    }
    sort(a, size);
    printLinkedList(a);
}
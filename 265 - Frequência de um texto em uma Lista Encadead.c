#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
    int count;
    char character;
    Node *next;
};

Node* insert(Node *first, int count, char character){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->character = character;
    newNode->count = count;
    newNode->next = first;
    return newNode;
}
Node* build(){
    return NULL;
}
void print(Node *first) {
    if (first != NULL) {
        printf("%c %d\n", first->character, first->count);
        print(first->next);
    }
}

int main(int argc, char const *argv[]) {
    int count[256] ={0};
    int i;
    // for (i = 0; i < 256; ++i) count[i] = 0;

    char str[200];
    gets(str);
    for (i = 0; i < strlen(str); ++i) count[str[i]]++;
    Node *first = build();
    for (i = 0; i < 256; ++i)
        if(count[i] != 0) first = insert(first, count[i], i);
    print(first);

    return 0;
}
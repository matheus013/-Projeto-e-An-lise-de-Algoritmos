#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int item;
    Node *next;
};

Node* insert(Node *first, int item){
    Node *new = (Node*) malloc(sizeof(Node));
    new->item = item;
    new->next = first;
    return new;
}

void print(Node *first){
    if(first != NULL){
        printf("%d ", first->item);
        print(first->next);
    }
}
Node* build() {
    return NULL;
}
int get_max(Node *list){
    int max = 0;
    Node *curr;
    for (curr = list;curr != NULL; curr = curr->next)
        if(curr->item > max) max = curr->item;
    return max;
}
Node* sort(Node *list) {
    //buscando maior valor na lista
    int max = get_max(list);
    Node *curr;
    int array[max + 1] ;

    //zerando array
    for (int i = 0; i <= max; ++i) array[i] = 0;

    //contando frequencia de cada valor
    for (curr = list; curr != NULL; curr = curr->next)
        array[curr->item]++;

    //gerando lista ordenada
    Node *final = build();
    for (int i = max; i >= 0; --i)
        while(array[i] != 0) {
            final = insert(final,i);
            array[i]--;
        }

    return final;
}

int main() {
    int c, i;
    Node* list = build();
    //while(scanf("%d", &c)!=EOF)
    for (i = 0; i < 4; i++) {
        scanf("%d", &c);
        list = insert(list, c);
    }
    list = sort(list);
    print(list);
    return 0;
}

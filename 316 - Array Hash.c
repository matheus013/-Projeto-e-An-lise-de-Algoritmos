#include <stdio.h>
#include <string.h>

int hashFunction(char str[50], int elemento){
    int i, hashResult = 0;
    for(i = 0; i < strlen(str); i++)
        hashResult += (str[i] - 'A') + i + elemento;
    return hashResult;
}
'0' + 9

void main(){
    int n, l, hash, i, j;
    char str[50];
    scanf("%d\n", &n);
    for(i = 0; i < n; i++){
        scanf("%d\n", &l);
        hash = 0;
        for(j=0; j < l; j++){
            gets(str);
            hash += hashFunction(str, j);
        }
        printf("%d\n", hash);
    }
}
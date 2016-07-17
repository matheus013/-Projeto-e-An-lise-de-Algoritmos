#include <bits/stdc++.h>

typedef unsigned long long int ulli;

using namespace std;

bool loop = false;

bool isSolution(int a[], int k, int n) {
    return (k == n);
}

void build(int a[], int k, int n, int c[], int *candidate) {
    c[0] = true;
    c[1] = false;
    *candidate = 2;
}

void process(int a[], int k) {
    int aux = 0;
    cout << '{' ;
    for (int i=1; i<=k; i++)
        if (a[i]) cout << ' ' << i ;
    cout << " }" << endl;
}

void backtrack(int a[], int k, int n) {
    int c[n];
    int candidate, i;
    if (isSolution(a, k, n)) process(a, k );
    else {
        k++;
        build(a, k, n, c, &candidate);
        for (i = 0; i < candidate; i++) {
            a[k] = c[i];
            backtrack(a, k, n);
            if (loop) return;
        }
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; ++i)
        arr[i] = i;
    backtrack(arr,0,n);
}

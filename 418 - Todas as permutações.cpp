#include <bits/stdc++.h>

typedef unsigned long long int ulli;

using namespace std;

void process(std::vector<int> a, int k) {
    for (int i=0; i<k; i++)
        cout << a[i] ;
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    vector<int> v;
for (int i = 1; i <= n; ++i)
        v.push_back(i);
do {
process(v,n);
}while(next_permutation(v.begin(),v.end()));
}

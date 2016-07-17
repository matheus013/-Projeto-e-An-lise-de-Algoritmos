#include <bits/stdc++.h>

typedef unsigned long long int ulli;

using namespace std;

void process(std::vector<int> a, int k) {
    for (int i=0; i<k; i++)
        cout << a[i] ;
    cout << endl;
}

int main(){
    int x;
    cin >> x;
    for (int i = 0; i < x; ++i)
    {
    int n,m;
    cin >> n >> m;
    int arr[n];
    vector<int> v;
for (int i = 0; i < n; ++i)
    (i < n - m) ? v.push_back(0) : v.push_back(1);
do {
process(v,n);
}while(next_permutation(v.begin(),v.end()));
cout << endl;
}
}

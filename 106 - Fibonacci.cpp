#include "bits/stdc++.h"

typedef long long int lli;

using namespace std;

lli my_hash[100] = {0};

lli fibonacci (lli n){
	if(my_hash[n] || n == 0) return my_hash[n];

	my_hash[n - 1] = fibonacci(n - 1);
	my_hash[n - 2] = fibonacci(n - 2);

	return my_hash[n - 1] + my_hash[n - 2];
}

int main(int argc, char const *argv[]){
	my_hash[1] = 1;
	int n;
	while(1){
		cin >> n;
		if(!n) break;
		for (int i = 0; i < n; ++i) {
			cout << fibonacci(i);
			if(i != n-1) cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
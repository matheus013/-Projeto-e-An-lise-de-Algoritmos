#include "bits/stdc++.h"

typedef long long int lli;

using namespace std;

lli fatorial(lli n, lli result = 1){
	if(n == 0) return 1;
	if(n == 1) return result;
	return fatorial(n-1,result*n);
}

int main(int argc, char const *argv[]){
	lli n;
	while(1){
		cin >> n;
		if(n == -1) break;
		cout << fatorial(n) << endl;
	}

	return 0;
}
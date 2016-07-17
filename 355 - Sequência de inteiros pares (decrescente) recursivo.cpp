#include "bits/stdc++.h"

typedef long long int lli;

using namespace std;

lli atN(lli n){
	if(n == -1) return 0; 
	if(n%2 == 0) cout << n<< endl;
	atN(n-1);
}

int main(int argc, char const *argv[]){
	lli n;
	cin >> n;
	atN(n);

	return 0;
}
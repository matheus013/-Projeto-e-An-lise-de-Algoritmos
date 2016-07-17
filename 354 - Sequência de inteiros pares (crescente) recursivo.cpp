#include "bits/stdc++.h"

typedef long long int lli;

using namespace std;
lli fim;

lli atN(lli n = 0){
	if(n == fim+1) return 0; 
	if(n%2 == 0) cout << n<< endl;
	atN(n+1);
}

int main(int argc, char const *argv[]){
	cin >> fim;
	atN();

	return 0;
}
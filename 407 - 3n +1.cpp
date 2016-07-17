#include <bits/stdc++.h>
#define lint long long int

using namespace std;

lint myFunc(lint n, lint count = 1){
	if(n == 1) return count;
	if (n%2 == 0) return myFunc(n/2, count+1);
	else return myFunc(n*3 + 1, count+1);
}

lint topValue(lint a,lint b){
	if(a > b) swap(a,b);
	lint top = 0;
		for(lint i = a; i <= b; i++){
			lint aux = myFunc(i);
			if(aux > top) top = aux;
			//if(top == 525) return top;
		}
	return top;
}


int main(){
	lint i,j;
	while(cin >> i >> j) cout << i << ' ' << j << ' ' <<  topValue(i,j) << endl;
}
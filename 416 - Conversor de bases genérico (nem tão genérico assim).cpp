#include <bits/stdc++.h>
using namespace std;
string convert(int n,int base){
	string rep = "ABCDEF", result = "";
	int resto;
	while(n >= 1){
		resto = n%base;
		n /= base;
		if(resto < 10)
			result += '0' + resto;
		else
			result += rep[resto-10];
	}
	reverse(result.begin(),result.end());
	return result;
}


int main(int argc, char const *argv[]){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		int num, base;
		cin >> num >> base;
		cout << convert(num,base) << endl;
	}
	return 0;
}
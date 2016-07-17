#include <bits/stdc++.h>
using namespace std;
string convert(int n,string result = ""){
	if(n <= 1) return result + char('0' + n);
	return result + char('0'+ n%2) + convert(n/2);
}


int main(int argc, char const *argv[]){
	int n;
	cin >> n;
	string str = convert(n);
	for(int i = str.size() -1;i >= 0;--i)
		cout << str[i] << endl;
	return 0;
}
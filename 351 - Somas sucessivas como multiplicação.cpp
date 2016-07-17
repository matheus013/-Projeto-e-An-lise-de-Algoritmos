#include <bits/stdc++.h>

using namespace std;

int mult(int a,int b,int result = 0){
	if(b == 0) return result;
	return mult(a,b-1,result + a);
}

int main(int argc, char const *argv[]) {
	int a,b;
	cin >> a >> b;
	if(a < b) swap(a,b);
	cout << mult(a,b) << endl;
	return 0;
}
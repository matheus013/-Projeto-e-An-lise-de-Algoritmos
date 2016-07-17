#include <bits/stdc++.h>

using namespace std;

int inv(string &str,int b,int e){
	if(b - e == 1 || b - e == 0) return 0;
	swap(str[b], str[e]);
	inv(str,b+1,e-1);
}


int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	inv(str,0,str.size() - 1);
	cout << str << endl;
	return 0;
}
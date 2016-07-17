#include <bits/stdc++.h>

using namespace std;

bool inv(string str,int begin,int end){
	if(toupper(str[begin]) - toupper(str[end])) return false;
	if(begin - end == 1 || begin - end == 0) return true;
	return inv(str, begin+1, end-1);
}


int main(int argc, char const *argv[]) {
	int n;
	string str;
	cin >> n;
	getchar();
	for (int i = 0; i < n; ++i) {
		getline(cin,str);
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
		if(inv(str,0,str.size() - 1)) cout << "SIM" << endl;
		else cout << "NAO" << endl;
	}
	return 0;
}
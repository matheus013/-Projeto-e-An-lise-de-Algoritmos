#include <bits/stdc++.h>

using namespace std;


typedef std::vector<string> vs;
typedef long long int lli;
typedef pair<int, bool> ib;
vs vec;

int comps = 0;

int lessThan(string a, string b) {
	// cout << a << ' ' << b << endl;
	for (int i = 0; i < a.size(); ++i)	{
		++comps;
		if(a[i] < b[i]) return -1; 
		else if(a[i] > b[i]) return 1;
		if(b.size() == i + 1 && a.size() != b.size()) return 1;
	}
	if(a.size() < b.size()) return -1;
	// else if(a.size() > b.size()) return 1;
	return 0;
}

pair<int, bool> binary_search(lli start, lli end, string str) {
	int result = 0;
	while(start <= end){

		lli mid = (start + end)/2;
		int aux = lessThan(str, vec[mid]);
		// cout << comps << endl;
		// cout << aux << endl;
		if(aux == 0) return {comps,true};
		else if(aux == -1){
			end = mid;
		} else {
			start = mid;
		}
		if(abs(start - end) == 1){	
		break;
		}
	}
	return {comps, false};
}

int main(int argc, char const *argv[]) {
	lli n,m;
	cin >> n >> m;
	for (lli i = 0; i < n; ++i)	{
		string s;
		cin >> s;
		vec.push_back(s);
	}
	for (lli i = 0; i < m; ++i)	{
		string s;
		cin >> s;
		ib result = binary_search(0, n, s);
		string say = (result.second) ? "SIM" : "NAO";
		cout << say << " " << result.first << endl;
		comps = 0;
		if(i == 6) break;
	}

	// cout << lessThan("alg","a") << endl;
	// cout << comps << endl;
	return 0;
}
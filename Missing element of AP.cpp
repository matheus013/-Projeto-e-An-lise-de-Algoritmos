#include <bits/stdc++.h>

using namespace std;

typedef std::vector<int> vi;

vi vec;

int getN(int a, int n, int r){
	return a + r * n;
}
int getR(){
	return (vec.back() - vec.front())/(vec.size());
}
int binary_search(int start, int end) {
	while(start <= end){
		if(abs(start - end) == 1) return vec[start] + getR();
		int mid = (start + end)/2;
		if(vec[mid] == getN(vec.front(), mid, getR())){
			start = mid;
		} else {
			end = mid;
		}
	}
}
int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	while(n--){
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			int aux;
			cin >> aux;
			vec.push_back(aux);
		}
		cout << binary_search(0, vec.size() - 1) << endl;
		vec.clear();
	}

	return 0;
}
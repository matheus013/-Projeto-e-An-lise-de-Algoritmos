#include <bits/stdc++.h>

using namespace std;


typedef std::vector<int> vi;

vi vec;
int a=0;
int cut(int n);

int binary_search(int start, int end, int n) {
	int result = 0;
	while(start <= end){
		if(abs(start - end) == 1) break;
		int mid = (start + end)/2;
		cout << mid << endl;
		int aux = cut(mid);
		if(aux >= n) result = mid;
		if(aux < n){
			end = mid;
		} else {
			start = mid;
		}
	}
	return result;
}

int cut(int n)	{
	// cout << n << endl;
	int chip = 0;
	for (int i = 0; i < vec.size(); ++i)
		chip += (vec[i]/n);
	return chip;
}

int main(int argc, char const *argv[]) {
	int n,k, sum = 0;
	cin >> n >> k;
	for (int i = 0; i < k; ++i)	{
		int aux;
		cin >> aux;
		sum += aux;
		vec.push_back(aux);
	}
	cout << binary_search(0 ,sum , n) << endl;
	return 0;
}
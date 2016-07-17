#include <bits/stdc++.h>

using namespace std;

int sum(deque<int> &v,int soma = 0){
	if(v.size() == 1) return soma + v[0];
	soma += v.front();
	v.pop_front();
	return sum(v, soma);
}


int main(){
	int size;
	deque<int> result;
	cin >> size;
	while(result.size() != size){
		int aux;
		cin >> aux;
		result.push_back(aux);
	}
	cout << sum(result) << endl;
	return 0;
}
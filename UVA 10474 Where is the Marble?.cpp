#include <bits/stdc++.h>

using namespace std;

typedef std::vector<int> vi;

void print(vi vec){
	for (int i = 0; i < vec.size(); ++i) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}

vi sort( const vi &op , int max) {
   vi count( max + 1, 0 );
   for (int i = 0; i < op.size(); ++i)
   		++count[op[i]];
   vi sorted;
   for (int i = 0; i < count.size(); ++i) 
	   	if(count[i]){
	   		while(count[i]--)
	   			sorted.push_back(i);
	   	}
   return sorted;
}

int binary_search(vi &vec, int n, int start, int end){
	if(n == vec.front()) return -1;
	int result = INT_MAX;
	while(start < end) {
		int mid = (start + end)/2;
		if(vec[mid] == n && mid < result) result = mid;
		if(vec[mid] >= n){
			end = mid;
		} else {
			start = mid;
		}
		if(abs(start - end) == 1) 
			return (result == (INT_MAX)) ? result : min(start, end);
	}
	return result;
}


int main(int argc, char const *argv[]){ 
	int test = 1;
	while(1){
		vi vec;
		int n,q;
		cin >> n >> q;
		if(!n && !q) break;
		int max_value = 0;
		for (int i = 0; i < n; ++i) {
			int aux;
			cin >> aux;
			if(aux > max_value) max_value = aux;
			vec.push_back(aux);
		}
		vec = sort(vec, max_value);
		printf("CASE# %d:\n", test++);
		for (int i = 0; i < q; ++i) {
			int aux;
			cin >> aux;
			int result = binary_search(vec, aux, 0, vec.size());
			if(result == INT_MAX)
				printf("%d not found\n", aux);
			else
				printf("%d found at %d\n", aux, result + 2);
		}
	}
	return 0;
}
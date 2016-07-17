#include <bits/stdc++.h>

using namespace std;


#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)
#define parray(type,content) feach(type,content,i) printf("%d ", *i);

#define WHITE 0
#define BLACK 3
#define RED 2
#define KILL 5
#define INF INT_MAX

#define DEBUG if(0)

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> grid;
typedef vector<string> vs;

vi dp;


int test(int a,int b){
    // printf("%d %d \n",a,b );
    // printf("%d %d \n",dp[a],dp[b] );
    return abs(dp[a - 1] - dp[b]);
}
void sum(vector<long long int> arr,string use , int x){
    dp.push_back(0);
    for (int i = 0; i < use.size(); ++i) {
        int aux = (use[i] == '1' && arr[i] < x) ? dp.back() + 1 : dp.back();
        dp.push_back(aux);
    }
}

void run(int c){
    vector<long long int> arr;
    int n,m;
    long long int x;
    string use;
    cin >> n >> x >> m;
    while (n--) {
        long long int aux;
        cin >> aux;
        arr.push_back(aux);
    }
    cin >> use;
    printf("Caso #%d:\n", c);
    sum(arr,use,x);
    while(m--){
        int a, b;
        cin >> a >> b;
        printf("%d\n", test(a ,b) );
    }
    dp.clear();
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        run(i);
    }
}
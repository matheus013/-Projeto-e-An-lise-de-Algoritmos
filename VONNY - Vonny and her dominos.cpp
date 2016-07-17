#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli dp[100] = {0};

struct Stone {
    int m_top, m_down;
    Stone(int top,int down){
        m_top = top;
        m_down = down;
    }
    string toString(){
        return "[" + to_string(m_top) + "," + to_string(m_down) + "]";
    }
};
std::vector<Stone> stones;

void init(){
    for (int i = 0; i < 7; ++i) {
      for (int k = i ; k < 7; ++k) {
          stones.push_back(Stone(i,k));
      }
    }
}

void showStones() {
    for (vector<Stone>::iterator i = stones.begin(); i != stones.end(); ++i) {
        cout << (*i).toString() << ' ';
    }
}

lli fatorial(lli n, lli result = 1){
    if(n == 0) return 1;
    if(n == 1) return result;
    return fatorial(n-1,result*n);
}

lli fat(lli n){
    if(dp[n] != 0) return dp[n];
    dp[n] = fatorial(n);
    return dp[n];
}

lli comb(lli n, lli s) {
    if(n <= s) return -1;
    lli fn = fat(n);
    lli fs = fat(s);
    cout << fn << endl << fs << endl;
    return fn/(fs*(n - s));
}

bool compare(int arr[56]) {

}

int main(int argc, char const *argv[]) {
    init();
    showStones();
    cout << stones.size() << endl;
    cout << comb(4,2) << endl;
    return 0;
}
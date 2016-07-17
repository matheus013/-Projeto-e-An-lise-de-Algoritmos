#include<bits/stdc++.h>

#define pb(i) push_back(i);

using namespace std;


typedef vector<int> vi;
typedef vector<bool> vb;

vb use;
vi var;

void init(int n){
    var.clear();
    use.resize(n,false);
}

void run(int n){
    int length;
    scanf("%d", &length);
    for (int i = 0; i < length; ++i) {
        int input;
        scanf("%d", &input);
        var.pb(input)
    }

}

bool process(vi array, int cap) {
    int sum = 0;
    for (int i = 0; i < array.size(); ++i) {
        sum += array[i];
        use[i] = true;
        if(sum > cap) return false;
        if(sum == cap) return true;
    }
}
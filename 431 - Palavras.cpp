#include <bits/stdc++.h>

using namespace std;

string concat(vector<string> v) {
    string result = "";
    for (int i = 0; i < v.size(); ++i) {
        result += v.at(0);
    }
        cout << "->"<< result << endl;
    return result;
}

bool process(vector<string> a, vector<string> b) {
    do{
        do{
            if(!concat(a).compare(concat(b))) return true;
        } while(next_permutation(b.begin(),b.end()));
    } while(next_permutation(a.begin(),a.end()));
    return false;
}

int main(int argc, char const *argv[]) {
    int n,m;
    cin >> n >> m;
    vector<string> a,b;
    for (int i = 0; i < n; ++i) {
        string aux;
        cin >> aux;
        a.push_back(aux);
    } for (int i = 0; i < m; ++i) {
        string aux;
        cin >> aux;
        b.push_back(aux);
    }
    if(concat(a).size() >= 40 || concat(b).size() >= 40) cout << "N" << endl;
    else cout << (process(a,b) ? "S" : "N");

    return 0;
}
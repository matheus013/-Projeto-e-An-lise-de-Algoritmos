//
// Created by matheus on 13/07/16.
//

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

bool valid(vi vec, int cust) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (abs(vec[i] - vec[i + 1]) == cust)
            cust--;
        else if (abs(vec[i] - vec[i + 1]) > cust)
            return false;
    }
    return true;
}

int more(vi vec) {
    int def = vec[0];
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (abs(vec[i] - vec[i + 1]) > def)
            def = abs(vec[i] - vec[i + 1]);
    }
    return def;
}

int find(vi vec, int jumps) {
    if (valid(vec, jumps))
        return jumps;
    else
        return find(vec, ++jumps);
}

int main() {
    int t, n, aux, c = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        vi vec;
        vec.push_back(0);
        for (int i = 0; i < n; ++i) {
            cin >> aux;
            vec.push_back(aux);
        }
        cout << "Case " << c++ << ": " << find(vec, more(vec)) << endl;

    }
}
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

ii s(vi vec, int n) {
    ii result = {0, vec.size() - 1};
    //verificar extremos
    if (n >= vec[result.second]) {
        if (vec[result.second] == n)
            result.second--;
        result.first = result.second;
        result.second = -1;
        return result;
    }
    if (n <= vec[result.first]) {
        if (vec[result.first] == n)
            result.first++;
        result.second = result.first;
        result.first = -1;
        return result;
    }
    //caso geral
    while (result.first < result.second) {
        int mid = (result.first + result.second) / 2;
        if (vec[mid] == n) {
            result.first = mid - 1;
            result.second = mid + 1;
            return result;
        }
        else if (abs(result.first - result.second) == 1)
            return result;
        else if (vec[mid] > n) {
            result.second = mid;
        }
        else {
            result.first = mid;
        }
    }
    return result;
}

void print(int p, vi f) {
    if (p == -1)
        cout << 'X';
    else
        cout << f[p];
}

int main() {
    int n, aux;
    cin >> n;
    vi f, m;
    cin >> aux;
    f.push_back(aux);
    for (int i = 1; i < n; ++i) {
        cin >> aux;
        if (f.back() != aux)
            f.push_back(aux);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        m.push_back(aux);
    }
    for (int j = 0; j < m.size(); ++j) {
        ii r = s(f, m[j]);
        print(r.first, f);
        cout << ' ';
        print(r.second, f);
        cout << endl;
    }

}

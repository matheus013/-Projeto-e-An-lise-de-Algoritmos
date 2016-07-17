#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    string str;
    cin >> n >> t >> str;
    while (t--) {
        for (int i = 1; i < n; ++i) {
            if (str[i] == 'G' && str[i-1] == 'B') {
                swap(str[i],str[i-1]);
                ++i;
            }
        }
    }
    cout << str << '\n';
    return 0;
}
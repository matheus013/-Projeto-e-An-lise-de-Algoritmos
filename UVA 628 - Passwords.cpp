#include <bits/stdc++.h>

using namespace std;

int n, m;
string rule;
string dict[110], digits[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

void back(int v = 0, string s = "") {
    if(v == rule.size()){
        cout << s << endl;
        return;
    }
    switch(rule[v]) {
            case '#':
                for(int i = 0; i < n; i++)
                    back(v + 1, s + dict[i]);
                break;
            case '0':
                for(int i = 0; i < 10; i++)
                    back(v + 1, s + digits[i]);
                break;
        }
}

int main() {
    while(cin >> n) {
        cout << "--" << endl;
        for(int i = 0; i < n; i++)
            cin >> dict[i];
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> rule;
            back();
        }
    }
}

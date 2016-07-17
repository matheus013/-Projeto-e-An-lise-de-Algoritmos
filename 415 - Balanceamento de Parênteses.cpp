#include "bits/stdc++.h"

using namespace std;


bool isValid(string str, string oper){
    stack<char> stk;
    for (int i = 0; i < str.size(); ++i) {
        if(str[i] == oper[0])
            stk.push(str[i]);
        if(str[i] == oper[1]){
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty();
}
int main(){
    int n;
    cin >> n;
    getchar();
    for (int var = 0; var < n; ++var) {
        string str;
        getline(cin,str);
        if(isValid(str,"()") && isValid(str,"[]"))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

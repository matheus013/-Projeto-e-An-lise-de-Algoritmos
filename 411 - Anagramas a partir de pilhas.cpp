#include <bits/stdc++.h>

using namespace std;

typedef string::iterator si;

string in, out;

void lower(string &str) {
    for(si i = str.begin() ; i != str.end();++i)
        *i = tolower(*i);
}

void find(string a, string b, string stack, string path, int n) {
    if((unsigned int) n == in.length() * 2) {
        if(b == out)
            cout << path << endl;
        return;
    }
    if(a.length() > 0){
        string aux=" i";
        if(n==0)
            aux="i";
        find(a.substr(1, a.length() - 1), b, stack + a[0], path + aux, n + 1);
    }
    if(stack.length() > 0 && stack[stack.length() - 1] == out[b.length()])
        find(a, b + stack[stack.length() - 1], stack.substr(0, stack.length() - 1), path + " o", n + 1);
}

int main() {
    while(cin >> in >> out) {
        lower(in);
        lower(out);
        cout << "[" << endl;
        if(in.length() == out.length())
            find(in, "", "", "", 0);
        cout << "]" << endl;
    }
}


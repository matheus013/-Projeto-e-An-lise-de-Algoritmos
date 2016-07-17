#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    stack<string> stk;
    string list = "", comand;
    while(cin >> comand){
        if(comand != "PUSH" && comand != "POP"){
            list += comand + ' ';
            if(list.size()% 118 == 0){
                int last = list.size() - 1;
                list[last] = '\n';
            }
        }
        else{
            if(!list.empty()) {
                int last = list.size() - 1;
                list[last] = '\n';
                stk.push(list);
                list.clear();
            }
            if(comand == "POP") {
                if(stk.empty()) cout << "EMPTY STACK" << endl;
                else{
                    cout << stk.top();
                    stk.pop();
                }
            }
        }
    }
    return 0;
}

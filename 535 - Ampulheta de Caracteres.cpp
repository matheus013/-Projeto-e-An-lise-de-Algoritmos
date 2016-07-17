#include <bits/stdc++.h>

using namespace std;
void base(){
    cout << "** ";
    for (int i = 0; i < n - 2; ++i) cout << "* ";
    cout << "**\n";
}

void build(int n,int po) {
    int first = 2, second = 2*n - 2;
    int level = n - 2 - po;
    printf("> %d <\n", level );
    base();
    for (int j = 0; j < 2*n - 3; ++j) {
        cout << "*";
        for (int i = 1; i < n*2 ; ++i) {
            if(i == first || i == second){
             cout << '*';
            if(abs(first - second) <= 1 && first < second)
                    second--;
            }
            else
                cout << ' ';
        }
         cout << "*\n";
         first++;
         second--;
    }
    base();

}

int main() {

    int cases;
    cin >> cases;
    int aux = cases;
    while(cases--){
        printf("case %d:\n", aux - cases);
        int x,y;
        cin >> x >> y;
        build(x,y);
    }
    return 0;
}
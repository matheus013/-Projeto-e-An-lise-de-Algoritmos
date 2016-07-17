#include <bits/stdc++.h>

using namespace std;


#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)

#define WHITE 0
#define BLACK 3
#define RED 2
#define KILL 5
#define INF INT_MAX

#define DEBUG if(0)

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> grid;
typedef vector<string> vs;

int ana, bob;

void init(){
    ana = 0;
    bob = 0;
}
void turn(){
    int d1,d2;
    cin >> d1 >> d2;
    if(d1 == d2){
        ana++;
        bob++;
    }else if(d1 > d2){
        ana += bob;
        bob = 0;
    }else {
        bob += ana;
        ana = 0;
    }
}
void game(int n){
    int turns;
    cin >> turns;
    init();
    while(turns--){
        turn();
    }
    printf("Caso #%d: %d %d\n",n,ana,bob);
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
       game(i);
    }
}

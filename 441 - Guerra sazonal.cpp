#include <bits/stdc++.h>
#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)

#define WHITE 0
#define BLACK 3
#define SUP 2

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef vector<vi> grid;
int n;
grid g;
grid color;
vii all;
vvii ad;
int groups = 0;


void print(grid gri){
    feach(grid , gri , j){
        feach(vi , (*j) , i){
            ((*i) != INF) ? printf("%d ",(*i)) : printf("XX ") ;
        }
        cout << endl;
    }
    cout << "------------\n";
}
void resize(int n){
    groups = 0;
    all.clear();
    g.clear();
    color.clear();
    g.resize(n);
    for (int i = 0; i < n; ++i)
        g[i].resize(n);
    color.resize(n);
    for (int i = 0; i < n; ++i)
        color[i].resize(n,WHITE);
}

void mark(int a, int b){
    if(!g[a][b]) return;
    color[a][b] = BLACK;
    if(a-1 >= 0 && color.at(a-1)[b] == WHITE) mark(a-1,b);
    if(a+1 < n && color.at(a+1)[b]== WHITE ) mark(a+1,b);
    if(b-1 >= 0 && color.at(a)[b-1] == WHITE ) mark(a,b-1);
    if(b+1 < n && color.at(a)[b+1] == WHITE) mark(a,b+1);
    if(a-1 >= 0 && b-1 >= 0 && color.at(a-1)[b-1] == WHITE ) mark(a-1,b-1);
    if(a+1 < n && b-1 >= 0 && color.at(a+1)[b-1] == WHITE ) mark(a+1,b-1);
    if(a-1 >= 0 && b+1 < n && color.at(a-1)[b+1] == WHITE ) mark(a-1,b+1);
    if(a+1 < n && b+1 < n && color.at(a+1)[b+1] == WHITE ) mark(a+1,b+1);
}

void search(){
    feach(vii,all,i){
        if(color[(*i).first][(*i).second] == WHITE){
            mark((*i).first,(*i).second);
            groups++;
        }
    }
}

void run(){
    int x = 1;
    while (cin >> n) {
        resize(n);
        for (int i = 0; i < n; ++i){
            string str;
            cin >> str;
            for (int j = 0; j < n; ++j){
                g[i][j] = int(str[j] - '0');
                if(g[i][j] == 1){
                    all.push_back({i,j});
                }
            }
        }
        search();
        cout << "Image number " << x++ << " contains "<< groups << " war eagles."<<endl;
    }
}

int main() {
    run();
    return 0;
}

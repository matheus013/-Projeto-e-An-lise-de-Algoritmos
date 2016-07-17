#include <bits/stdc++.h>
#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)

using namespace std;

#define WHITE 0
#define BLACK 1
#define RED 2
#define INF numeric_limits<int>::max()


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> grid;

grid matriz;

void print(grid gri);

void init(int n){
    matriz.resize(n);
    farray(0,n,i){
        matriz[i].resize(n,INF);
    }
}

// vi

int main() {
    int n,x,y,cast;
    cin >> n;
    init(n);
    while(cin >> x >> y >> cast) {
        matriz[x][y] = cast;
        matriz[y][x] = cast;
    }
    print(matriz);
        return 0;
}

void print(grid gri){
    cout << "X ";
    farray(0 , gri.size(),i){
        cout << i << ' ';
    }
    cout << endl;
    int x = 0;
    feach(grid , gri , j){
        printf("%d ", x++);
        feach(vi , (*j) , i){
            ((*i) != INF) ? printf("%d ",(*i)) : printf("X ") ;
        }
        cout << endl;
    }
    cout << "-------------\n";
}
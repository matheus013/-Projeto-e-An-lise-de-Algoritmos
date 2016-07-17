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

grid matriz;
vs name;
vi color;
int rep;
vi all;
vi leafs;
int safado;
int susp;

unordered_map<string, int> my_hash;
void init(int n);
void build(int n);
void hunter();
bool isLeaf(int n);
bool desco(int n);
void print(grid gri);

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int s;
        cin >> s;
        init(s + 1);
        build(rep);
        hunter();
        print(matriz);
        printf("%d %d\n", susp,safado);
    }
}

void hunter() {
    for (int i = 1; i <= rep; ++i) {
        if(isLeaf(i)){
            susp++;
            leafs.push_back(i);
            (desco(i)) ? printf("&no -> %d\n",i ):printf("&yes -> %d\n",i );
            continue;
        }
        (desco(i)) ? printf("no -> %d\n",i ):printf("yes -> %d\n",i );
        }
}

bool isLeaf(int n){
    if(color[n] == KILL) return false;
    for (int i = 0; i < matriz.size(); ++i)
        if(matriz[n][i] == 1) return false;
    return true;
}

void build(int n){
   for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        if(b != 0)
            matriz[i][b] = 1;
    }
}
bool desco(int n){
    for (int i = 1; i < matriz.size(); ++i)
        if(matriz[i][n] == 1) return false;
    return true;
}
void init(int n){
    safado = 0;
    susp = 0;
    rep = n - 1;
    matriz.clear();
    color.clear();
    name.clear();
    my_hash.clear();
    color.resize(n,WHITE);
    matriz.resize(n);
    farray(0, n, i)
            matriz[i].resize(n, INF);
}

void print(grid gri){
    cout << "X ";
    farray(0 , gri.size(),i)
        cout << i << ' ';
    cout << endl;
    int x = 0;
    feach(grid , gri , j){
        printf("%d ", x++);
        feach(vi , (*j) , i)
            ((*i) != INF) ? printf("%d ",(*i)) : printf("X ") ;
        cout << endl;
    }
}
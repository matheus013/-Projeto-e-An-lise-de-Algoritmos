#include <bits/stdc++.h>
#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)

#define WHITE 0
#define BLACK 3
#define RED 2
#define KILL 5
#define INF INT_MAX

#define DEBUG if(0)

using namespace std;

int rep = 0;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> grid;
typedef vector<string> vs;

grid matriz;

vs name;
vi color;

unordered_map<string, int> my_hash;

void print(grid gri);
void insert(string a, string b);
void init(int n);


int turns = 0;

void listShow(vs stringList){
    feach(vs,stringList,i){
        cout << *i << endl;
    }
}
void killer(int n){
    color[n] = KILL;
    for (int i = 0; i < rep; ++i) {
        matriz[n][i] = INF;
        matriz[i][n] = INF;
        turns++;
    }
}

bool noLife(){
    for (int i = 0; i < rep; ++i)
        if(color[i] != KILL) return false;
    return true;
}
bool isLeaf(int n){
    if(color[n] == KILL) return false;
    for (int i = 0; i < matriz.size(); ++i)
        if(matriz[n][i] == 1) return false;
    return true;
}
void dfs(int start = 0) {
    vs aux;
    if(noLife()) return;
    for(int i = start; i < name.size(); i++)
        if(isLeaf(i) && color[i] != KILL){
            aux.push_back(name[i]);
            killer(i);
        }
        sort(aux.begin(),aux.end());
        listShow(aux);
        dfs();
}

int main() {
    int n;
    string x,y;
    while(cin >> n){
        init(n*2);
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            insert(x, y);
        }
        dfs();
    }
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

void insert(string a, string b){
    int x,y;
    if(!(my_hash.count(a) > 0)){
        name.push_back(a);
        my_hash.insert({a,rep++});
    }
    x = my_hash.at(a);
    if(!(my_hash.count(b) > 0)){
        name.push_back(b);
        my_hash.insert({b,rep++});
    }
    y = my_hash.at(b);
    matriz[x][y] = 1;
}

void init(int n, int p){
    matriz.clear();
    color.clear();
    name.clear();
    my_hash.clear();
    rep = 0;
    color.resize(p,WHITE);
    matriz.resize(n);
    farray(0, n, i)
            matriz[i].resize(n, INF);
}
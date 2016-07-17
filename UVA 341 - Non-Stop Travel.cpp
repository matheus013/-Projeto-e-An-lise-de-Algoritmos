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

unordered_map<string, int> my_hash;
int menor(vi l);
void init(int n);
void print(grid gri);
void djk(int a, int b, int rote = 0,int pre = -1);

void run(int n) {
    rep = n;
    int v,i = 1;
    while(n--){
        cin >> v;
        while(v--){
            int final,cust;
            cin >> final >> cust;
            matriz[i][final ] = cust;
        }
        ++i;
    }
    int start, end;
    cin >> start >> end;
    djk(start,end);
    (all.size() != 0) ? printf("; %d second delay\n", menor(all)) : printf("NO SHIPMENT POSSIBLE\n");
    all.clear();
}

int main() {
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        init(n + 1);
        run(n);
        print(matriz);
    }
    return 0;
}
void djk(int a, int b, int rote,int pre){
    printf("%d -> %d > %d // cust = %d\n",pre,a,b,rote);
    if(matriz[a][b] < INF) {
        printf("%d -> %d > %d // cust = %d\n",pre,a,b,rote + matriz[a][]b);
        all.push_back(rote + matriz[a][b]);
        return;
    }
    farray(0,rep,i)
        if(matriz[a][i] < INF && color[i] == WHITE && i != a) {
            color[a] = RED;
            djk(i, b, rote + matriz[a][i], a);
        }

}

void init(int n){
    matriz.clear();
    color.clear();
    name.clear();
    my_hash.clear();

    color.resize(n,WHITE);
    matriz.resize(n);
    farray(0, n, i)
            matriz[i].resize(n, INF);
    for (int i = 0; i < n; ++i)
        matriz[i][i] = 0;
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
int menor(vi l){
    int mine = INF;
    feach(vi, l,i)
        if((*i) < mine) mine = *i;
    return mine;
}
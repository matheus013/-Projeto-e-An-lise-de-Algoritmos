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

void insert();
void run(int count);
bool isLeaf(int n);
void print(grid gri);
int menor(vi l);

void bfs(int a, int b, int rote = 1){
    // printf("%d -> %d // cust = %d\n",a,b,rote);
    if(matriz[a][b] < INF) {
        all.push_back(rote);
        return;
    }
    farray(0,rep,i){
        if(matriz[a][i] < INF && color[i] == WHITE) {
            color[a] = RED;
            bfs(i,b,rote + matriz[a][i]);
        }
    }
}

int main(int argc, char const *argv[]) {
    int n, x = 1;
    cin >> n;
    printf("SHIPPING ROUTES OUTPUT\n");
    while(n--){
        run(x++);
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}

void insert(string a, string b){
    int x,y;
    x = my_hash.at(a);
    y = my_hash.at(b);
    matriz[x][y] = 1;
    matriz[y][x] = 1;
}

void init(int n){
    matriz.clear();
    color.clear();
    name.clear();
    my_hash.clear();
    rep = 0;
    color.resize(n,WHITE);
    matriz.resize(n);
    farray(0, n, i)
            matriz[i].resize(n, INF);
}

void run(int count){
    int portos, vias, box;
    cin >> portos >> vias >> box;

    init(portos);

    while(portos--){
        string aux;
        cin >> aux;
        name.push_back(aux);
        my_hash.insert({aux,rep++});
    }
    while(vias--){
        string a,b;
        cin >> a >> b;
        insert(a,b);
    }
        // print(matriz);
        printf("\nDATA SET  %d\n\n", count);
        while(box--){
        int cust;
        string a,b;
        cin >> cust >> a >> b;
        bfs(my_hash.at(a),my_hash.at(b));
        (all.size() != 0) ? printf("$%d\n", cust*menor(all)*100) : printf("NO SHIPMENT POSSIBLE\n");
        all.clear();
        farray(0,color.size(),j)
            color[j] = WHITE;
    }

}

bool isLeaf(int n){
    if(color[n] == KILL) return false;
    for (int i = 0; i < matriz.size(); ++i)
        if(matriz[n][i] == 1) return false;
    return true;
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
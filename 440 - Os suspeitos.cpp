#include <bits/stdc++.h>
#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)

#define WHITE 0
#define BLACK 1
#define SUP 2

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi visit;
vvii graph;
vii node;

void  append(int first,int secund = 0){
    node.push_back({first , secund});
}
void clear(){
    node.clear();
    graph.clear();
    visit.clear();
}

void show(vii v){
    feach(vii,v,i)
            cout << (*i).first << ' ';
    cout << endl;
}
void print(){
    feach(vvii , graph , j){
        feach(vii , (*j) , i){
            cout << i->first << ' ';
        }
        cout << endl;
    }
}
void init(int s){
    visit.clear();
    visit.resize(s);
    visit[0] = SUP;
}
int run(){
    int n, m,k,curr;
    cin >> n >> m;
    init(n);
    farray(0,m,i){
        cin >> k;
        node.clear();
        farray(0,k,j){
            cin >> curr;
            append(curr);
        }
        graph.push_back(node);
    }
    return n + m;
}

bool conteins(int o, vii population){
    feach(vii, population, i)
            if(i->first == o) return true;
    return false;
}

int infect(int start = 0){
    // cout << "inject > " << start << endl;
    for (int i = 0; i < graph.size(); ++i) {
        if(conteins(start , graph[i])){
            feach(vii , graph[i] , j){

                if(visit.at(j->first) != BLACK)
                    visit.at(j->first) = SUP;
                // infect(j->first);
            }
        }
    }
    visit.at(start) = BLACK;
}

int main(){
    while(run()){
        int sum = 0;
        farray(0,visit.size(), i){
            if(visit[i] == SUP){
                infect(i);
                i = 0;
            }
        }
        feach(vi , visit , i){
            if((*i) == BLACK){
                sum++;
            }
        }
        cout << sum << endl;
        clear();
    }
}

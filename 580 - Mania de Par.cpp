#include<bits/stdc++.h>
#define TRvii(c, it) for(vii::iterator it = (c).begin(); it != (c).end() ; it++)

#define WHITE 0
#define BLACK 1
#define GRAY 2
#define INF INT_MAX

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int vertex_size;
int *visit_status;
int *dist;
int *part;

vector<vii> adj_list;

ii inicio;
ii fim;
int n, A,B,V, K;

int p = 0;

void graph() {
    adj_list.clear();
    adj_list.resize(V + 1, vii());
    for(int i = 1 ; i <= K ; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    vertex_size = V + 1;
    visit_status = new int[vertex_size];
    dist = new int[vertex_size];
    part = new int[vertex_size];
}



void dijk(int start) {
    priority_queue <ii, vector<ii>, greater<ii> > pq; pq.push({0, start});
    while(!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first , u = front.second;
        if (d > dist[u]) continue;
        for(int j = 0 ; j < adj_list[u].size() ; j++) {
            ii v = adj_list[u][j];
            if(dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                part[v.first] = u;
                pq.push({dist[v.first] , v.first});
            }
        }
    }
}

void run() {
    ii i;
    cin >> V >> K;
    graph();
    vector<vii> adj_aux(V + 1, vii());;

    for(int i = 1; i <= V; i++)
        for(int j=0 ; j<(int) adj_list[i].size() ; j++) {
            int adj = adj_list[i][j].first;
            int custo = adj_list[i][j].second;
            if(!adj_list[adj].empty()) for(int k = 0 ; k <  adj_list[adj].size() ; k++) adj_aux[i].push_back({adj_list[adj][k].first , adj_list[adj][k].second + custo});
        }

    adj_list = adj_aux;
    A = 1; B = V;
    for(int i=0 ; i < vertex_size ; i++)
        dist[i] = INF;
    memset(part, 0, sizeof(int) * vertex_size);
    dist[A] = 0;
    dijk(A);
    (dist[B] < INF) ? printf("%d\n", dist[B] ) : printf("-1\n");;
}

int main() {
        run();

}

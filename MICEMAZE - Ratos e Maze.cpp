#include<bits/stdc++.h>
#define TRvii(c, it) for(vii::iterator it = (c).begin(); it != (c).end() ; it++)

#define WHITE 0
#define BLACK 1
#define GRAY 2
#define INF INT_MAX

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int vertex_size;
int *visit_status;
int *dist;
int *part;

vector<vii> adj_list;
vi ports;

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
        // cout << a << b << c<< endl;
        adj_list[a].push_back({b,c});
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

void init(){
    ports.resize(V + 1, INF);
    // graph();
        for(int i=0 ; i < vertex_size ; i++)
        dist[i] = INF;
    memset(part, 0, sizeof(int) * vertex_size);

}

void run() {
    int T;
    ii i;
    cin >> V;
    // init();
    cin >> B >> T >> K;
    graph();
    for (int i = 1; i <= V; ++i) {
        init();
        A = i;
        if(i == B) continue;
        dist[A] = 0;
        dijk(A);
        // printf("%d -> %d = %d\n",A,B, dist[B]);
        ports[A] = dist[B];
       }
       int D = 1;
       for (int i = 1; i <= V; ++i)
           if(ports[i] <= T)
            D++;
        printf("%d\n", D);
}

int main() {
    run();
}

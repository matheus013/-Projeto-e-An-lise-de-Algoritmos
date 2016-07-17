#include<bits/stdc++.h>

    using namespace std;

    typedef vector<string> vS;

    typedef map<string, vS> hashMap;

    typedef map<string , vS >::iterator iM;
    typedef vector<string>::iterator iV;

    class Grafo{
    public:

        bool **matriz;
        int **dist;

        Grafo(){
            dist = new int*[8];
            matriz = new bool*[8];
            for (int i = 0 ; i < 8; i++) {
                dist[i] = new int[8];
                matriz[i] = new bool[8];
            }
            for (int i = 0 ; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    dist[i][j] = 0;
                    matriz[i][j] = true;
                }
            }
        }

        void calc(int *x, int *y){

            list<int*> li;
            for (int i = 0 ; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    dist[i][j] = 0;
                    matriz[i][j] = true;
                }
            }
            dist[x[0]][x[1]] = 0;
            li.clear();
            int *p;
            li.push_back(x);
            matriz[x[0]][x[1]]=false;
            while(!li.empty()){
                int *r = li.front();
                li.pop_front();

                bool a = r[0]-2 >= 0 && r[1]-1 >= 0;
                bool b = r[0]-2 >= 0 && r[1]+1 < 8;
                bool c = r[0]-1 >= 0 && r[1]-2 >= 0;
                bool d = r[0]-1 >= 0 && r[1]+2 < 8;
                bool e = r[0]+1 < 8 && r[1]-2 >= 0;
                bool f = r[0]+1 < 8 && r[1]+2 >= 0;
                bool g = r[0]+2 < 8 && r[1]-1 >= 0;
                bool h = r[0]+2 < 8 && r[1]+1 < 8;

                if (a &&  matriz[r[0]-2][r[1]-1]){
                    matriz[r[0]-2][r[1]-1]=false;
                    p = new int[2];
                    p[0] = r[0]-2;
                    p[1] = r[1]-1;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                }
                if(b &&  matriz[r[0]-2][r[1]+1]) {
                    matriz[r[0]-2][r[1]+1]=false;

                    p = new int[2];
                    p[0] = r[0]-2;
                    p[1] = r[1]+1;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                }


                if(c && matriz[r[0]-1][r[1]-2]){
                    matriz[r[0]-1][r[1]-2]=false;

                    p = new int[2];
                    p[0] = r[0]-1;
                    p[1] = r[1]-2;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                }if (d && matriz[r[0]-1][r[1]+2]){
                    matriz[r[0]-1][r[1]+2]=false;

                    p = new int[2];
                    p[0] = r[0]-1;
                    p[1] = r[1]+2;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                    }
                if (e && matriz[r[0]+1][r[1]-2]){
                    matriz[r[0]+1][r[1]-2]=false;

                    p = new int[2];
                    p[0] = r[0]+1;
                    p[1] = r[1]-2;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                }if (f && matriz[r[0]+1][r[1]+2]){
                    matriz[r[0]+1][r[1]+2]=false;

                    p = new int[2];
                    p[0] = r[0]+1;
                    p[1] = r[1]+2;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                }if (g && matriz[r[0]+2][r[1]-1]){
                    matriz[r[0]+2][r[1]-1]=false;

                    p = new int[2];
                    p[0] = r[0]+2;
                    p[1] = r[1]-1;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                }if (h && matriz[r[0]+2][r[1]+1]){
                    matriz[r[0]+2][r[1]+1]=false;
                    p = new int[2];
                    p[0] = r[0]+2;
                    p[1] = r[1]+1;

                    li.push_back(p);
                    dist[p[0]][p[1]] = dist[r[0]][r[1]] + 1;

                    }
                //show(li,r);
                if(r[0] == y[0] && r[1] == y[1]){li.clear();}


            }
            cout << dist[y[0]][y[1]] << endl;
        }//Fim da função
};



int main(){
    Grafo *g;
    string a,b;
    int *x,*y,z;

    cin >> z;
    g = new Grafo();
    for (int i = 0 ; i < z; i++){
        x = new int[2];
        y = new int[2];
        cin >> a >> b;
        x[0] = (a[1]- '0') -1 ;
        x[1] = (a[0] - 96) -1 ;
        y[0] = (b[1]- '0') -1 ;
        y[1] = (b[0] - 96) -1 ;
// cout << a << ' ' << b << ' ';
        g->calc(x, y);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int table[10][10];
int num;
int m_count = 0;

void back( int table_aux[10][10], int x = 0, int y = 0, int count = 0) {
    if( x >= 10 || y >= 10 || x < 0 || y < 0) return;
    if(table_aux[x][y]==0) {
        int table_local[10][10];
        for(int i=0 ; i<10 ;i++)
            for(int j=0 ; j<10 ; j++)
                table_local[i][j] = table_aux[i][j];
        table_local[x][y] = 1;
        back(table_local, x-2, y-1, count+1);
        back(table_local, x-2, y+1, count+1);
        back(table_local, x-1, y-2, count+1);
        back(table_local, x-1, y+2, count+1);
        back(table_local, x+1, y-2, count+1);
        back(table_local, x+1, y+2, count+1);
        back(table_local, x+2, y-1, count+1);
        back(table_local, x+2, y+1, count+1);
    }
    else if(count > m_count)
        m_count = count;
}

void print(){
    for(int i = 0 ; i < 10 ; i++, cout << endl)
        for(int y = 0 ; y < 10 ; y++)
            printf(" %2d", table[i][y]);
}
int init() {
    int total=0;
    m_count = 0;
    for(int i=0 ; i<10 ; i++)
        for(int y=0 ; y<10 ; y++)
            table[i][y]=-1;
    for(int i=0 ; i<num ; i++) {
        int x, y;
        cin >> x >> y;
        total+=y;
        for(int j=0 ; j<10 ; j++)
            if(j >= x && j < y+x)
                table[i][j] = 0;
    }
    // print();
    back(table);
    return total - m_count;
}

int main() {
    cin >> num;
    int cont = 1;
    while(num) {
        int a = init();
        cout << "Case " << cont++ << ", " << a << " " << ((a == 1) ? "square":"squares") << " can not be reached." << endl;
                cin >> num;
    }
}

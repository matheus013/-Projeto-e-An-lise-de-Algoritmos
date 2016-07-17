#include <bits/stdc++.h>

using namespace std;

int cols[8] = {0,1,2,3,4,5,6,7};
void print(int n = 0);

bool validPosition(){
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if(abs(cols[i] - cols[j]) == abs(i - j) && i != j) return false;
    return true;
}
bool isSolution(int x, int y) {
    return cols[x-1] == y-1;
}
void process(int x,int y){
    int n = 1;
    do{
        if(validPosition() && isSolution(x,y)) print(n++);
        // if(validPosition() && !isSolution(x,y)) print(-1);
    }while(next_permutation(cols, cols + 8));

}
void print(int n) {
    printf("%2d      ",n);
    for (int i = 0; i < 8; ++i)
        (i < 7) ?  printf("%d ",cols[i] + 1) :  printf("%d",cols[i]+1);
    printf("\n");
}
int main(int argc, char const *argv[]){
    int n,x,y;
    cin >> n;
    while(n--){
    cin >> x >> y;
    cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
    process(y,x);
    cout << endl;
}

}
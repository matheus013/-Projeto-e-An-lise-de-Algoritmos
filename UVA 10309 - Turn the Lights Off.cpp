#include <bits/stdc++.h>
#define MIN 101
#define LENGTH 1024
#define feach(type,content) for(type::interator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)
using namespace std;

int steps[LENGTH];

struct grid {
    bool states[10][10];
};

void solve(grid inMatrix, string name);
int search(grid matrix, int row, int step);
void toggle(grid& matriz, int row, int col);

int main() {
    string name;
    while(true) {
        cin >> name;
        if(name == "end") break;
        grid g;
        farray(0,10,i)
            farray(0,10,j) {
                char input;
                cin >> input;
                g.states[i][j] = (input == '#' ? false : true);
            }

        solve(g, name);
    }
}

void toggle(grid& matriz, int row, int col) {
    matriz.states[row][col] = !matriz.states[row][col];
    if(row > 0) matriz.states[row - 1][col] = !matriz.states[row - 1][col];
    if(col > 0) matriz.states[row][col - 1] = !matriz.states[row][col - 1];
    if(row + 1 < 10) matriz.states[row + 1][col] = !matriz.states[row + 1][col];
    if(col + 1 < 10) matriz.states[row][col + 1] = !matriz.states[row][col + 1];
}

int search(grid matrix, int row, int step) {
    if(step > 100) return -1;
    farray(1,10,j)
        farray(0,10,i)
            if(matrix.states[j - 1][i]) {
                toggle(matrix, j, i);
                step++;
            }
    farray(0,10,i)
        if(matrix.states[9][i]) return -1;
    return step;
}

void solve(grid inMatrix, string name) {
    grid matrix;
    for(int i = 0; i < LENGTH; i++)
        steps[i] = -1;
    int step;
    int result;
    farray(0,LENGTH,i) {
        matrix = inMatrix;
        step = 0;
        bitset<10> bit_set(i);
        farray(0,10,j)
            if(bit_set.test(j)) {
                toggle(matrix, 0, j);
                step++;
            }
        result = search(matrix, 1, step);

        if(result != -1)
            steps[i] = result;
    }
    int min = MIN;
    farray(0,LENGTH,i)
        if(steps[i] != -1 && steps[i] < min)
            min = steps[i];
    cout << name << " " << ((min != MIN) ? min : -1) << endl;
}

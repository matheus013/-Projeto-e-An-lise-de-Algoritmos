#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi values;

int countSeq = 0;

void sumArray(int c){
    for (vi::iterator i = values.begin(); i != values.end(); ++i)
        if((*i) >= c) countSeq++;
}

void printArray(int * array,int size){
    for (int i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << endl;
}

int multiArray(const int *a, const int *b, int size){
    int result = 0;
    for (int i = 0; i < size; ++i) result += a[i]*b[i];
    return result;
}

struct Matrix{
    int rows;
    int columns;
    int **mtz;
    Matrix(int row,int column){
        rows = row;
        columns = column;
        mtz = new int*[row];
        for (int i = 0; i < row; ++i) mtz[i] = new int[column];
    }

    void print(){
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < columns; ++j)
                cout << mtz[i][j] << ' ';
            cout << endl;
        }
    }

    void clear() {
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < columns; ++j)
                mtz[i][j] = 0;
        }
    }
    void set(int value, int row, int column){
        mtz[row][column] = value;
    }

    void insertColumn(int * array, int column, int size){
        for (int i = 0; i < size; ++i) mtz[i][column] = array[i];
    }

    int * getColumn(int column){
        int *aux;
        aux = new int[rows];
        for (int i = 0; i < rows; ++i) aux[i] = mtz[i][column];
        return aux;
    }

    void insertRow(int * array, int row, int size){
        for (int i = 0; i < size; ++i) mtz[row][i] = array[i];
    }

    int * getRow(int row){
        int *aux;
        aux = new int[columns];
        for (int i = 0; i < columns; ++i) aux[i] = mtz[row][i];
        return aux;
    }

    Matrix tranposed() {
        Matrix result(columns,rows);
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < columns; ++j)
                result.set(mtz[i][j],j,i);
        }
        return result;
    }

    Matrix operator *(Matrix &mtz){
        if(columns == mtz.rows){
            Matrix result(rows,mtz.columns);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < mtz.columns; ++j) {
                    int product = multiArray(getRow(i), mtz.getColumn(j), columns);
                    result.set(product ,i,j);
                }
            }
            return result;
        }
        return Matrix(0,0);
    }
};

int main(){
    int row,column,sequency;
    while(1){
        cin >> row >> column >> sequency;
        Matrix mtz(row,column);
        if((row + column  + sequency) == 0) break;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j)
                cin >> mtz.mtz[i][j];
        }
        int count = 0;
        Matrix tranposed = mtz.tranposed();
        for (int i = 0; i < tranposed.rows; i++) {
            int max = 0;
            for (int j = 0; j < tranposed.columns; ++j) {
                if(tranposed.mtz[i][j] == 1) max++;
                else if(max != 0){
                    values.push_back(max);
                    max = 0;
                } 
                if((j == tranposed.columns - 1) && max != 0)
                    values.push_back(max);
            }
        }
        sumArray(sequency);
        cout << countSeq << endl;
        countSeq = 0;
    }
}

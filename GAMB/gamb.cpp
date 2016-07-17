#include <stdio.h>


void setOne(int **mtz, int size){
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j) mtz[i][j] = 1;
}

int main(int argc, char const *argv[]) {
    int mtz[4][4] = {0};

    setOne(mtz);
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef std::vector<int> vi;
 
 
void split(const string &str);
void process(int m, int n, const string &bitmap);
string process(int row, int col, int m, int n, vector<vi>& rows);
bool check(int common, int row, int col, int m, int n, vector<vi> &rows);

int main() {
    int test, r, c;
    cin >> test;
    while(test--){
        cin >> r >> c;
        string input = "";
        cout << "AQUI";
        for (int i = 0; i < r; ++i) {
            string aux;
            cin >> aux;
            input += aux;
        }
        cout << input;
        process(r, c, input);
    }
    return 0;
}
 
void split(const string &str) {
    for (int i = 0;i < str.size();++i) {
      	cout << str[i];
        if(i && i % 50 == 0)
          cout << endl;
    }
}
 
void process(int m, int n, const string &bitmap) {
  cout << "AQUI";
  vector<vi> rows(m);
  for (int i = 0;i < m;++i) 
    for (int j = 0; j < n ;++j) 
  		rows[i].push_back(bitmap[i*n+j]-'0');
  cout << "AQUI";
  split(process(0, 0, m, n, rows));
}
 
string process(int row, int col, int m, int n, vector<vi>& rows) {
    if (m == row|| n == col) return "";
    int common = rows[row][col];
    if (check(common, row, col, m, n, rows)) 
    	return (common) ? "1" : "0";
    else {
        int top = m / 2 + m % 2;
        int left = n / 2 + n % 2;
        return "D" + process(row, col, top, left, rows) + 
                process(row, col + left, top, n - left, rows) +
                process(row + top, col, m - top, left, rows) +
                process(row + top, col + left, m - top, n - left, rows);
    }
}

bool check(int common, int row, int col, int m, int n, vector<vi> &rows) {
	for (int i = row;i < row + m;++i) 
        for (int j = col;j < col + n;++j) 
            if (rows[i][j] != common) return false;
  return true;
}

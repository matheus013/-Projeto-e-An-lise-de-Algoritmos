#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

ii bug(vi books, int bag) {
    int i = 0, j = books.size() - 1;
    ii aux;
    while (i < j) {
        if (books[i] + books[j] < bag)
            ++i;
        else if (books[i] + books[j] == bag) {
            aux = {i, j};
            ++i, --j;
        }
        else
            --j;
    }
    return aux;
}


int main() {
    int n, bag;
    vi books;
    while (cin >> n) {
        int input;
        while (books.size() != n) {
            cin >> input;
            books.push_back(input);
        }
        sort(books.begin(), books.end());
        cin >> bag;
        ii result = bug(books, bag);
        cout << "Peter should buy books whose prices are " << books[result.first] << " and "
        << books[result.second] << "." << endl << endl;
        books.clear();
    }
}
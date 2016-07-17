#include <bits/stdc++.h>

using namespace std;
int field = 1;
int h,w;
std::vector<string> vec;
class Pos{
public:
	int x,y;
	Pos(int x,int y){
		this->x = x;
		this->y = y;
		// cout << x << ' ' << y << endl;
	}
};
//------------------------------------------------------------------------
void countMine(int a,int b){
if(a-1 >= 0 && vec.at(a-1)[b] != '*') vec.at(a-1)[b]++;
if(a+1 < w && vec.at(a+1)[b] != '*') vec.at(a+1)[b]++;
if(b-1 >= 0 && vec.at(a)[b-1] != '*') vec.at(a)[b-1]++;
if(b+1 < h && vec.at(a)[b+1] != '*') vec.at(a)[b+1]++;
if(a-1 >= 0 && b-1 >= 0 && vec.at(a-1)[b-1] != '*') vec.at(a-1)[b-1]++;
if(a+1 < w && b-1 >= 0 && vec.at(a+1)[b-1] != '*') vec.at(a+1)[b-1]++;
if(a-1 >= 0 && b+1 < h && vec.at(a-1)[b+1] != '*') vec.at(a-1)[b+1]++;
if(a+1 < w && b+1 < h && vec.at(a+1)[b+1] != '*') vec.at(a+1)[b+1]++;
}
//------------------------------------------------------------------------
void print(vector<string> v){
	cout << "Field #" << field << ":" << endl;
	field++;
	for (vector<string>::iterator i = vec.begin(); i != vec.end(); ++i){
		for (string::iterator j = (*i).begin() ; j != (*i).end(); ++j){
			if(*j != '*') cout << (int)*j;
			else cout << *j;
		}
		cout << endl;
	}
	// cout << "-----------------" << endl;
}
//------------------------------------------------------------------------

std::vector<Pos *> listPos;

//------------------------------------------------------------------------

int main(){
	do{
	cin >> w >> h;
	if(w+h == 0) break;
	for (int i = 0; i < w; ++i)	{
		string str = "";
		for (int j = 0; j < h; ++j)	{
			char aux;
			cin >> aux;
			if(aux == '*') listPos.push_back(new Pos(i,j));
			str += aux;
		}
		replace(str.begin(),str.end(),'.',(char)0);
		vec.push_back(str);
	}
	for (std::vector<Pos *>::iterator  i = listPos.begin(); i != listPos.end(); ++i){
		countMine((*i)->x,(*i)->y);
	}
	listPos.clear();
	print(vec);
	cout << endl;
	vec.clear();
	}while(1);
	cout << '\r';
}
#include <bits/stdc++.h>

#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
using namespace std;
#define SHOT 1000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int acabou;

int leak = 0;
int consume = 0;

queue<ii> buff;
vi array_sum(1000);

int taxe() { return leak + consume; }
int process(vii commands);
int bts(int start, int end);
bool go(int bag);


void print(){
	for (int i = 0; i < acabou; ++i)
		cout << array_sum[i] << ' ';
	cout << endl;
}




int main(int argc, char const *argv[]) {
	int point;
	vii commands(1000);
	while(cin >> point){
		string command;
		cin >> command;
		if(command == "Gas"){
			cin >> command;
			commands[point] = {point, 0};
		} else if( command == "Fuel"){
			cin >> command;
			int aux;
			cin >> aux;
			if(point+aux == 0) break;
			commands[point] = {point, aux};
		} else if(command == "Leak") {
			commands[point] = {point, -1};
		} else if(command == "Mechanic") {
			commands[point] = {point, -2};
		} else if(command == "Goal") {
			acabou = point;
			process(commands);
			print();
			break;
		}
	}

	return 0;
}



int process(vii commands){
	for (int i = 0; i < acabou; ++i)	{
		if(commands[i].second == -1)
			buff.push(commands[i]);
		else if(commands[i].second == -2)
			buff.push(commands[i]);
		else {
			if(!commands[i].second)
				array_sum[commands[i].first] = -1000;
			else
				buff.push(commands[i]);
		}
	}
	array_sum[0] = taxe();
	for (int i = 1; i < acabou; ++i) {
		if(array_sum[i] == -1000){
			array_sum[i] = 0;
			continue;
		}
		if(i == buff.front().first){
			if(buff.front().second == -1)
				leak++;
			else if(buff.front().second == -2)
				leak = 0;
			else {
				consume = buff.front().second;
			}
			buff.pop();
		}
		array_sum[i] += array_sum[i - 1] + taxe();
	}
}

bool go(int bag){
	for (int i = 0; i < acabou; ++i)	{
		if(bag - array_sum[i] < 0) return false;
		bag -= array_sum[i];
	}
}

int bts(int start, int end){
	int tank = INT_MAX;

	while( start < end){
		int mid = (start + end)/2;
		if(go(mid)){
			if(mid < tank)
				tank = mid;
		}
		if(mid > array_sum.back()){
			end = mid;
		} else {
			start = mid;
		}
	}
	return tank;
}
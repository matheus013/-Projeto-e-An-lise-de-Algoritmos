#include <bits/stdc++.h>
#define MAXSTEPS 100000 //Define o número máximo de jogadas
using namespace std;
string suit = "pceo";

map<char,int> values = {
    {'A',14},
    {'K',13},
    {'Q',12},
    {'J',11},
    {'T',10},
    {'9',9},
    {'8',8},
    {'7',7},
    {'6',6},
    {'5',5},
    {'4',4},
    {'3',3},
    {'2',2}
};

void makeDeck(queue<string> &a, queue<string> &b){
    for (int i = 0; i < 26; ++i) {
        string aux;
        cin >> aux;
        a.push(aux);
    }for (int i = 0; i < 26; ++i) {
        string aux;
        cin >> aux;
        b.push(aux);
    }

}
string dequeue(queue<string> &a){
    string aux = a.front();
    a.pop();
    return aux;
}

void war(queue<string> &player_one, queue<string> &player_two) {
    int turns = 0;
    string currentOne, currentTwo;
    queue<string> queueOfTable;
    bool inWar = false;
    while (!player_one.empty() && !player_two.empty() && (turns  < MAXSTEPS)) {
        turns ++;
        currentOne = dequeue(player_one);
        currentTwo = dequeue(player_two);
        queueOfTable.push(currentOne);
        queueOfTable.push(currentTwo);
        if (inWar) 
            inWar = false;
        else {
            if (values[currentOne[0]] > values[currentTwo[0]]){
                while (!queueOfTable.empty())
                    player_one.push(dequeue(queueOfTable));
            }
            else if (values[currentOne[0]] < values[currentTwo[0]]){
                while (!queueOfTable.empty())
                    player_two.push(dequeue(queueOfTable));
            }
            else if (values[currentOne[0]] == values[currentTwo[0]])
                inWar = true;
        }
    }
    if (!player_one.empty() && player_two.empty())
        cout << "jogador 1 ganhou com " << turns  << " passos" << endl;
    else if (player_one.empty() && !player_two.empty())
        cout << "jogador 2 ganhou com " << turns  << " passos" << endl;
    else
        cout << "jogo empatado apos 100000 jogadas. Jogador 1 |" 
					<< player_one.size() << "| cartas e jogador 2 |" 
					<< player_two.size() << "| cartas" << endl;
}
int main(){
    int games;
    cin >> games;
    for (int var = 0; var < games; ++var) {
        queue<string> player_one,player_two;
        makeDeck(player_one,player_two);
        war(player_one,player_two);
    }
    return(0);
}

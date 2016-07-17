#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
 
map<string, int>mp;
 
int pos = 1;
 
void create_map(string str, int n)
{
    if(str.size() == n)
    {
        mp[str] = pos++;
        return;
    }
 
    char last;
    if(str == "")
    {
        last = 'a';
    }
    else
    {
        last = str[str.size() - 1] + 1;
    }
    for(char i=last; i<='z'; i++)
    {
        create_map(str+i, n);
    }
 
}
 
 
 
 
int main()
{
    for(int i=1; i<6; i++)
    {
        create_map("", i);
    }
 
    string str;
    while(getline(cin, str))
    {
        printf("%d\n", mp[str]);
    }
 
    return 0;
}
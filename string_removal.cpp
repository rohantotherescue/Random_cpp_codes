#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int solve(string &s){
    stack<char> s;
    for(auto i: s){
        if(!s.empty() && ((i=='B' && s.top()=='B')||(i=='B' && s.top()=='A'))) s.pop();
        else s.push(i);
    }
    return s.size();
}

int main()
{
    
    return 0;
}
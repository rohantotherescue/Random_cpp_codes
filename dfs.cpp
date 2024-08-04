#include<iostream>
#include<algorithm>
using namespace std;

// vector<int> visited;
void dfs_recursion(vector<int> &vis, int node, vector<int> &ls, vector<int> &adj[]){
    vis[node]=1;
    ls.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it])dfs(vis, it, ls, adj);
    }
}

void dfs_iterative(vector<int> &adj[],int n, vector<int> &vis, vector<int> &ls, int source){
    stack<int> stk;
    stk.push(source);
    for(int i=1; i<= n; i++){
        if(vis[i]) continue;
    while(!stk.empty()){
        int node= stk.top();
        stk.pop();
        vid[node]=1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[child]) stk.push(it);
        }
    }
    }
}

int main()
{
    
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bfs(vector<vector<int>> &adj[], vector<int> &vis, int n, int source, vector<int> &ls){
    queue<int> q;
    q.push(source);
    for(int i=1; i<= n; i++){
        if(vis[i]) continue;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        vis[node]=1;
        ls.push_back(node);
        for(auto child: adj[node]) if(!vis[child])q.push(child);
    }
    }

}

int main()
{
    
    return 0;
}
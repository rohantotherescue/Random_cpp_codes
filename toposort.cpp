#include<iostream>
#include<algorithm>
using namespace std;

vector<int> toposort(int k, vector<vector<int>> &gr){
    vector<int> indeg(n+1, 0);
    for(int node=1; node<= k; node++){
        for(auto i: gr[node]){
            indeg[i]++;
        }
    }

    queue<int> q;
    vector<int> vis(k+1,0);
    for(int node=1; node<=k; node++){
        if(indeg[node]==0) q.push(node);
    }

    vector<int> topoSort;
    while(!q.empty()){
        int s= q.size();
        while(s--){
            int node= q.front();
            q.pop();

            vis[node]= true;
            topoSort.push_back(node);

            for(auto child: gr[node]){
                if(!vis[child]){
                    indeg[child]--;
                    if(indeg[child]==0)q.push(child);
                }
            }
        }
    }

    vector<int> notopo;
    for(int node=1; node<=k; node++){
        if(indeg[node]!=0) return notopo; 
    }
    return topoSort;
}

int main()
{
    
    return 0;
}
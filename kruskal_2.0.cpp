#include<iostream>
#include<algorithm>
#include <vector>
#include "./disjoint_set.cpp"
using namespace std;

//find the total length of the mst
int kruskal_2(int V, vector<vector<int>> adj[]){
    // sort the adj list on the weights

    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i< V; i++){
        for(auto it: adj[i]){
            int adjNode= it[0];
            int wt= it[1];
            int node=i;
            edges.push_back({wt, {node, adjNode}});
        }
    }

    DisjointSet ds(V);
    sort(edges.begin(), edges.end());
    int ans=0;
    for(auto it: edges){
        int wt= it.first;
        int u= it.second.first;
        int v= it.second.second;

        if(ds.findUpar(u)!= ds.findUpar(v)){
            ans+= wt;
            ds.unionBySize(u,v);
        }

    }


}


int main()
{
    //this time using disjoint set

    // given edges as [{node1, node2, wt}...] please note that these are biderectional
    int V;
    vector<vector<int>> list_of_lawaris_nodes;
    vector<vector<int>> adj_list[V];
    for(auto i: list_of_lawaris_nodes){
        int temp[2];
        temp[0]= i[1];
        temp[1]= i[2];
        adj_list[i[0]].push_back(temp);
        temp[0]= i[0];
        adj_list[i[1]].push_back(temp);
    } 

    //send this to the kruskal_2 method that will give you the length of the mst

    return 0;
}
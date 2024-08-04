#include<iostream>
#include<algorithm>
using namespace std;

class DisjointSet{
private:
    vector<int> rank, size, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i< n; i++) parent[i]=i;
    }

    int findUpar(int node){
        if(parent[node]== node) return node;
        else return parent[node]=findUpar(parent[node]); 
    }

    void unionByRank(int u, int v){
        int par_u= findUpdar(u);
        int par_v= findUpdar(v);
        if(par_u== par_v) return;
        else if(rank[par_u]> rank[par_v]){
            parent[par_v]= par_u;
        }else if(rank[par_u]< rank[par_v]){
            parent[par_u]= par_v;
        }else{
            parent[par_u]= par_v;
            rank[par_v]++;
        }
    }  //rank is just an indicator of superiority for the tree

    void unionBySize(int u, int v){
        int par_u= findUpdar(u);
        int par_v= findUpdar(v);
        if(par_u== par_v) return;
        else if(size[par_u]> size[par_v]){
            parent[par_v]= par_u;
            size[par_u]+= size[par_v];
        }else{
            parent[par_u]= par_v;
            size[par_v]+= size[par_u];
        }
    }
};

int main()
{
    
    return 0;
}
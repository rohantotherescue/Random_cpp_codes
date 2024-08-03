#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

vector<vector<int>> build_bidirectional(vector<vector<int>> input, int n){
    vector<vector<int>> gr(n);
    for(auto it: input){
        gr[it[0]].push_back(it[1]);
        gr[it[1]].push_back(it[0]);
    }
    return gr;
}

vector<vector<int>> build_unidirectional(vector<vector<int>> input, int n){
    vector<vector<int>> gr(n);
    for(auto it: input){
        gr[it[0]].push_back(it[1]);
    }
    return gr;
}

vector<vector<int>> kruskal(vector<vector<int>> gr, int n){
    vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
    for(int i=0; i<n; i++) dist[i][i]=0;
    for(int k=0; k< n; k++){
        for(int i=0; i< n; i++){
            for(int j=0; j< n; j++){
                if(dist[i][k]== INT_MAX || dist[k][j]==INT_MAX) continue;
                dist[i][j]= min(dist[i][j], dist[i][k]+ dist[k][j]);
            }
        }
    }
    return dist;
}

int main()
{
    // input is in form of vector of vectors, [[u1,v1], [u2, v2],...] : biderctional
    vector<vector<int>> inp;
    int n= inp.size();
    vector<vector<int>> adjMatrix= build_bidirectional(inp, n);
    vector<vector<int>> dist= kruskal(adjMatrix, n);
    return 0;
}
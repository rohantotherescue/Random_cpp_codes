#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dijkstra(vector<pair<int, int>> gr, int source, int destination){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n= gr.size(); // please note that the graph nodes are marked from 0 to n-1
    vector<int> distTo(n+1, INT_MAX);

    distTo[source]=0;
    pq.push({0,source});

    while(!pq.empty()){
        int prev= pq.top().second;
        pq.pop();

        for(auto it= gr[prev].begin(); it<= gr[prev].end(); it++){
            int next= it.first;
            int dis_next= it.second;
            if(distTo[next]> distTo[prev]+ dis_next) {distTo[next]= distTo[prev]+ dis_next;
            pq.push_back({distTo[next], next}); }
        }
    }
    return distTo[destination];
}

int main()
{
    
    return 0;
}
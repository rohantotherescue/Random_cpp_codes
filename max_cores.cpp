#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int solve(vector<int> &start, vector<int> &end){
    int ans=0;
    int n= start.size();
    // vector<vector<int>> sched;
    // for( int i=0; i< n; i++){
    //     sched.push_back({start[i], end[i]-start[i]});
    // }

    priority_queue <int, vector<int>, greater<int> > pq;
    int tty= end[0];
    pq.push(tty);

    // int maxi=sched[0][0];
    // maxi+= sched[0][1];
    // int mini= INT_MAX;
    // int tty= end[0];
    for(int i=1; i< n; i++){
        if(start[i]<=pq.top()){
            ans++;
            pq.push(end[i]);
        }else{
            tty+= pq.top();
            pq.pop();
            pq.push(tty);
        }
        // if(tty>= sched[i][0]){
        //     ans++;
        //     tty= max(sched[i][1], tty);
        //     mini= min(mini, sched[i][1]);
            
        // }
        // else if(tty> sched[i][0] && mini< sched[i][0]){
        //     tty= max(tty+sched[i][1], mini+ sched[i][1]);
        // }


        // if(tty>=start[i]) {
        //     ans++;
        //     tty= min(tty, end[i-1]);
        //     }
        // tty+=end[i];

        // this will miss out on middle free cores
        // if(tty> start[i]){
        //     ans++;
        // }
        // tty= min(end[i],tty);

        // if(start[i]< mini){
        //     ans++;
        //     mini= min(mini, end[i]-start[i]);
        // }
        // else{
        //     int tmp_maxi= max(maxi, (2*mini)+ end[i]);
        //     int tmp_mini= min(maxi, (2*mini)+ end[i]);
        //     maxi= tmp_maxi; mini= tmp_mini;
        // }
    }
    
    return ans;
}


int solve_correctly(vector<int> &start, vector<int> &end){
    int ans=0;
    int n= start.size();

    priority_queue <int, vector<int>, greater<int> > pq;
    int tty= end[0];
    pq.push(tty);

    for(int i=1; i< n; i++){
        if(start[i]<=pq.top()){
            ans++;
            pq.push(end[i]);
        }else{
            tty+= pq.top();
            pq.pop();
            pq.push(tty);
        }   
    }
    
    return ans;
}


int main()
{
    
    return 0;
}
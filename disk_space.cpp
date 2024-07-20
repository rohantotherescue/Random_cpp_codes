#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solve(vector<int> used, vector<int> totalCapacity){
    sort(totalCapacity.begin(), totalCapacity.end(), greater<int>());
    int sum=0;
    for(int i=0; i< used.size(); i++){
        sum+= used[i];
    }
    int ans=0;
    for(int i=0; i< totalCapacity.size(); i++){
        if(sum>0){
            ans++;
            sum-=totalCapacity[i];
        }else{
            break;
        }
    }
    return ans;
}

int main()
{
    
    return 0;
}
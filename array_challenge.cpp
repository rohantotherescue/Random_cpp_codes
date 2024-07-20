#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> brute_force(vector<int> arr){
    vector<int> ans;
    ans.push_back(0);
    for(int i=1; i< arr.size(); i++){
        int counter=0;
        for(int j=0; j< i; j++){
            if(arr[i]> arr[j]) counter+= abs(arr[i]-arr[j]);
            else if(arr[i]< arr[j]) counter-= abs(arr[i]-arr[j]);
        }
        ans.push_back(counter);
    }
    return ans;
}

vector<int> solvewith0nsq(vector<int> arr){
    vector<int> ans;
    ans.push_back(0);
    for(int i=1; i< arr.size(); i++){
        int counter=0;
        for(int j=0; j< i; j++){
            if(arr[i]> arr[j]) counter+= abs(arr[i]-arr[j]);
            else if(arr[i]< arr[j]) counter-= abs(arr[i]-arr[j]);
        }
        ans.push_back(counter);
    }
    return ans;
}

vector<int> solve_optimal(vector<int> arr){
    int n = arr.size();
    if (n == 0) return {};
    vector<int> ans(n, 0);
    int sum = 0; 
    int diffSum = 0; 

    for (int i = 1; i < n; ++i) {
        sum += arr[i-1];
        diffSum += (arr[i] - arr[i-1]) * i;
        ans[i] = diffSum;
    }

    return ans;
}

int main()
{
    
    return 0;
}
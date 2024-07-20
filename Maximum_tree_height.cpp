#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int soln(int n, vector<int>& glass){
    int ans=0;
    sort(glass.begin(), glass.end());
    for(int i=0; i< glass.size(); i++){
        if(ans<glass[i]) ans+= glass[i];
    }
    return ans;
}


int main()
{
    vector<int> input2= {2,1,2};
    int input1=3;

    int ans= soln(input1, input2);
    cout<< ans;
    return 0;
}
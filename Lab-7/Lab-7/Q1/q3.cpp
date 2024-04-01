// TIME COMPLEXITY :  O(N*WT) 
// SPACE COMPLEXITY : O(N*WT)
// where N is number of items and WT is weight limit

#include<bits/stdc++.h>
using namespace std;
int maxCost(int i,int W[],int V[],int wt,int n,vector<vector<int>>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i][wt]!=-1){
        return dp[i][wt];
    }
    // take it
    int cost =0;
    if(wt>=W[i]){
        cost = V[i]+ maxCost(i+1,W,V,wt-W[i],n,dp);
    }
    // not take it
    cost = max(cost,maxCost(i+1,W,V,wt,n,dp));
    return dp[i][wt] = cost;
}

int main(){
    int n,wt;
    cin>>n>>wt;
    int W[n];
    for(int i=0;i<n;i++){
        cin>>W[i];
    }
    int V[n];
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    vector<vector<int>>dp(n,vector<int>(wt+1,-1));
    cout<<maxCost(0,W,V,wt,n,dp)<<endl; // function call
    return 0;
}
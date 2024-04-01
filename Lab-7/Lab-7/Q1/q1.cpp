// TIME COMPLEXITY :  O(NLogN) 
// SPACE COMPLEXITY : O(N)
// where N is number of items

#include<bits/stdc++.h>
using namespace std;
int maxCost(int n,int W[],int V[],int wt){
    vector<pair<double,int>>p;
    for(int i=0;i<n;i++){
        p.push_back({V[i],i});
    }
    sort(p.begin(),p.end());
    int max_cost =0;
    for(int i=n-1;i>=0;i--){
       int ind = p[i].second; 
       if(wt>=W[ind]){
        max_cost+=V[ind];
        wt -=W[ind];
       }
    }
    return max_cost;
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
    cout<<maxCost(n,W,V,wt)<<endl; // function call
    return 0;
}
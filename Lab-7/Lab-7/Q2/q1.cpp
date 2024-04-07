// TIME COMPLEXITY :  O(N*LOG(N)) 
// SPACE COMPLEXITY : O(N)
// where N is number of job

#include<bits/stdc++.h>
using namespace std;
int maxProfit(int n,int D[],int P[]){
    vector<pair<int,int>>p;
    set<int>s;
    for(int i=0;i<n;i++){
      p.push_back({P[i],D[i]});
      s.insert(i+1);
    }
    sort(p.begin(),p.end());
    int ans =0;
    for(int i=n-1;i>=0;i--){
        auto it = s.upper_bound(p[i].second);
        if(it!=s.begin()){
            it--;
            ans+=p[i].first;
            s.erase(it);
        }
    }
    return ans;  
}


int main(){
    int n;
    cin>>n;
    int D[n];
    for(int i=0;i<n;i++){
        cin>>D[i];
    }
    int P[n];
    for(int i=0;i<n;i++){
        cin>>P[i];
    }
    cout<<maxProfit(n,D,P)<<endl;
    return 0;
}
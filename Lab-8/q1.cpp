// TIME COMPLEXITY : O(ElogE)
// SPACE COMPLEXITY: O(E+V)

#include<bits/stdc++.h>
using namespace std;

vector<int>par,rnk;

int findpar(int node){
   if(par[node]==node) return node;
   return par[node] = findpar(par[node]);
}

void Union(int u,int v){
  int par_u = findpar(u);
  int par_v = findpar(v);
  if(rnk[par_u]<rnk[par_v]){
    par[par_v] = par_u;
  }
  else if(rnk[par_u]>rnk[par_v]){
    par[par_u] = par_v;
  }
  else{
    par[par_u] = par_v;
    rnk[par_v]++;
  }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<long ,pair<int ,int>>>edges;
    for(int i=0;i<e;i++){
        long wt;
        cin>>wt;
        int u,v;
        cin>>u>>v;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());
    
    for(int i=0;i<v;i++){
       par.push_back(i);
       rnk.push_back(0);
    }
    int MST_weight = 0;
    vector<pair<int,int>>mx_st;

    for(int i=edges.size()-1;i>=0;i--){
        long W = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
       if(findpar(u)!=findpar(v)){
        mx_st.push_back({u,v});
        MST_weight+=W;
        cout<<u<<" "<<v<<endl;
        Union(u,v);
       }
    }

    return 0;
}
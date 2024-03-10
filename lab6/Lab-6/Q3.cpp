// TIME COMPLEXITY : O(3*(V+E)+V) = O(V+E) 
// SPACE COMPLEXITY : O(E + 4*V) = O(V+E) 
// where V is no. of vectex and E is no. of eadg
#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>&vis,vector<int>adj[],stack<int>&st){
    vis[i] =1;
    for(auto it:adj[i]){
        if(vis[it]==0){
            dfs(it,vis,adj,st);
        }
    }
    st.push(i);
}
void dfs2(int i,vector<int>&vis,vector<int>adjT[],vector<int>&temp){
    vis[i] =1;
    temp.push_back(i);
    for(auto it:adjT[i]){
        if(vis[it]==0){
            dfs2(it,vis,adjT,temp);
        }
    }
}
int main(){
    cout<<"ENTER THE NUMBER OF VERTEX"<<endl;
    int n;
    cin>>n;
    cout<<"ENTER THE NUMBER OF EADG"<<endl;
    int e;
    cin>>e;
    vector<int>adj[n+1];
    cout<<"ENTER THE EADGES OF THE GRAPH"<<endl;
    for(int i =0;i<e;i++){
        int x,y; // eadg from x to y
        cin>>x>>y;
        adj[x].push_back(y);
    }
    // sort all the nodes according to their finishing time
    stack<int>st; 
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
      if(vis[i]==0){
        dfs(i,vis,adj,st);
      }
    }
    // reverse all edges of the graph
    vector<int>adjT[n+1];
    for(int i=1;i<=n;i++){
        vis[i] =0; 
        for(auto it:adj[i]){
            adjT[it].push_back(i);
        }
    }
    //  Again perform DFS
    vector<vector<int>>ans;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(vis[node]==0){
            vector<int>temp;
            dfs2(node,vis,adjT,temp);
            ans.push_back(temp);
        }
    }
    //  Print ans;
    for(auto it:ans){
        for(int i=0;i<it.size();i++){
            cout<<it[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
// TIME COMPLEXITY : O(2*V+2*E) = O(V+E) 
// SPACE COMPLEXITY : O(4*V + 2*E) = O(V+E) 
// where V is no. of vectex and E is no. of eadg
#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<int>adj[],vector<int>&indeg,int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>topoSort;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return topoSort;
}
int main(){
    cout<<"ENTER THE NUMBER OF VERTEX"<<endl;
    int n;
    cin>>n;
    cout<<"ENTER THE NUMBER OF EADG"<<endl;
    int e;
    cin>>e;
    vector<int>adj[n+1];
    vector<int>indeg(n+1,0);
    cout<<"ENTER THE EADGES OF THE GRAPH"<<endl;
    for(int i =0;i<e;i++){
        int x,y; // eadg from x to y
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    vector<int>topoSort = topologicalSort(adj,indeg,n); // function call
    if(topoSort.size()!=n){
        cout<<"GRAPH IS NOT DAG"<<endl;
    }
    else{
        cout<<"TOPO SORT IS FOLLOWING"<<endl;
        for(int i=0;i<n;i++){
            cout<<topoSort[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
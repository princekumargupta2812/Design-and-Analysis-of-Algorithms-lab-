// TIME COMPLEXITY : O(E*V + E*LOG(E))
// SPACE COMPLEXITY : O(E+4*V) = O(E+V)

#include <bits/stdc++.h>
using namespace std;

int parent[100005];
vector<vector<int>>edges(100005,vector<int>(3));
vector<int>MST;
vector<int>MST_2;
int edg=0;

void initialise(int n){
	for (int i = 1; i <= n; i++){
		parent[i] = i;
    }
}

int find(int x){
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void union1(int i, int &sum){
	int x = find(edges[i][1]);
	int y = find(edges[i][2]);
	if (x != y) {
		parent[x] = y;
		MST.push_back(i);
		sum += edges[i][0];
	}
}

void union2(int i, int &sum,vector<int>&temp){
	int x = find(edges[i][1]);
	int y = find(edges[i][2]);
	if (x != y) {
		parent[x] = y;
		sum += edges[i][0];
		edg++;
        temp.push_back(i);
	}
}

int main(){
	int v, e;
	cin>>v>>e;
	initialise(v);
	for (int i = 0; i < e; i++) {
        int u,v,w;
        cin>>u>>v>>w;
		edges[i][0] = w;
		edges[i][1] = u;
		edges[i][2] = v;
	}
	sort(edges.begin(), edges.begin()+e);

	int sum = 0;
	for (int i = 0;i<e;i++) {
		 union1(i, sum);
	}
    cout<<"SUM OF WEIGHT OF MST : "<<sum<<endl;
	cout <<" FIRST MST OF THE GRAPH IS :"<<endl;
    for(int i=0;i<MST.size();i++){
        cout<<edges[MST[i]][1]<<" "<<edges[MST[i]][2]<<endl;
    }
    
	int second_mst = INT_MAX;
	sum = 0;
	for (int j=0;j<MST.size();j++) {
		initialise(v);
		edg = 0;
        vector<int>temp;
		for (int i = 0; i < e; i++) {
			if (i == MST[j])
				continue;
			union2(i, sum, temp);
		}
		if (edg != (v - 1)) {
			sum = 0;
			continue;
		}
		if (second_mst > sum){
			second_mst = sum;
            MST_2= temp;
        }
		sum = 0;
	}
    if(second_mst==INT_MAX){
        cout<<"ONLY ONE MST IS POSSIBLE"<<endl;
    }
    else{
        cout<<"SUM OF WEIGHT OF SECOND MST : "<<second_mst<<endl;
        cout <<" SECOND MST OF THE GRAPH IS :"<<endl;
        for(int i=0;i<MST_2.size();i++){
            cout<<edges[MST_2[i]][1]<<" "<<edges[MST_2[i]][2]<<endl;
        }
    }
	return 0;
}

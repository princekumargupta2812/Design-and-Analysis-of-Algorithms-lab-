// USED THE CONCEPT OF QUICK SORT BUT NOT SORT THE ARRAY HERE
// TIME COMPLEXITY :- O(N); Avarage complexity ,O(N*N) Worst Case
// SPACE COMPLEXITY :- O(1);

#include<bits/stdc++.h>
using namespace std;

int partitions(int l,int r,int a[]){
    int x=a[r];
    int i= l;
	for(int j= l;j<r;j++)
	{
		if (a[j]<=x)
		{
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[i],a[r]);
	return i;
}

int Kth_element(int l,int r,int k,int a[]){
	int pivotIdx=partitions(l,r,a);
	if(pivotIdx-l==k-1)
		return pivotIdx;
	else if(pivotIdx-l>k-1)
		return Kth_element(l,pivotIdx-1,k,a);
	return Kth_element(pivotIdx+1,r,k-pivotIdx+l-1,a);
}

int main(){
   freopen("input3.txt", "r", stdin);
   int n;
   int k;
   cout<<"Enter the size of array"<<endl;
   cin>>n;
   cout<<"Enter the value of K"<<endl;
   cin>>k;
   int a[n];
   cout<<"Enter elements array"<<endl;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int z = Kth_element(0,n-1,n-k+1,a); // function call

   cout<<a[z]<<endl;
   cout<<endl;
    return 0;
}
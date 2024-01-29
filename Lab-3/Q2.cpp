#include<bits/stdc++.h>
using namespace std;
int sum1(int a[],int mid,int i,int j)
{
    int h=0;
    int f=a[mid];
    for(int k=mid;k>=i;k--)
    {
       h+=a[k];
       f=max(f,h);
    }
    int h1=0;
    int l=a[mid];
    for(int k=mid;k<=j;k++)
    {
       h1+=a[k];
       l=max(l,h1);
    }
    return(max(f+l-a[mid],max(l,f)));

}
int partition(int a[],int i,int j)
{
  if(i==j)
  {
    return a[i];
  }
  int mid=(i+j)/2;
   int leftsum=partition(a, i, mid);
  int rightsum=partition(a,mid+1,j);
  return max(rightsum,max(sum1(a,mid,i,j),leftsum));

}
int  main(){
ios::sync_with_stdio(0); cin.tie(0);
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
cout<<partition(a,0,n-1);

return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// int partitions(int l,int r,int a[]){
//     int x=a[r];
//     int i= l;
// 	for(int j= l;j<r;j++)
// 	{
// 		if (a[j]<=x)
// 		{
// 			swap(a[i],a[j]);
// 			i++;
// 		}
// 	}
// 	swap(a[i],a[r]);
// 	return i;
// }

// int Median_element(int l,int r,int k,int a[]){
// 	int pivotIdx=partitions(l,r,a);
// 	if(pivotIdx-l==k-1)
// 		return pivotIdx;
// 	else if(pivotIdx-l>k-1)
// 		return Median_element(l,pivotIdx-1,k,a);
// 	return Median_element(pivotIdx+1,r,k-pivotIdx+l-1,a);
// }

// int main(){
//    int n;
//    cout<<"Enter the size of array"<<endl;
//    cin>>n;
//    int a[n];
//    cout<<"Enter elements array"<<endl;
//    for(int i=0;i<n;i++){
//     cin>>a[i];
//    }
//    int k = (n+1)/2;
//    int median = Median_element(0,n-1,k,a); // function call

//    cout<<a[median]<<endl;
//    cout<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long
int partition(int i,int j,int a[])
{   int pivot=a[j];
    int h=i;
    int l=j-1;
    while(h<l)
    {
        if(a[h]<=pivot)
        {
          h++;
        }
        if(a[l]>pivot)
        {
            l--;
        }
        if((a[h]>pivot)&&(a[l]<=pivot))
        {
            swap(a[l],a[h]);
            
        }
       
    }
    int p=j-1;
    for(;p>=i;p--)
    {
        if(pivot>=a[p])
        {
            break;
        }
    }
    swap(a[p+1],a[j]);
    return p+1;
   
}
int findmid(int i,int j,int k,int a[])
{
    int pivot=partition(i,j,a);
    if(pivot-i==k-1)
    {
        return pivot;
    }
    else if(pivot-i>k-1)
    {
        return findmid(i,pivot-1,k,a);
    }
    
       return  findmid(pivot+1,j,k-pivot+i-1,a);
    
}
signed main(){
ios::sync_with_stdio(0); cin.tie(0);

 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 int median =findmid(0,n-1,(n+1)/2,a);
cout<<a[median]<<endl;
 
 
return 0;
}
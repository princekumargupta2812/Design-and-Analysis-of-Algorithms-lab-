// TIME COMPLEXITY : O(N*log(N))
// SPACE COMPLEXITY : O(N)

#include<bits/stdc++.h>
using namespace std;

int mergeall(int l,int r,long int a[],int &count_inversion){
    int mid = l+(r-l)/2;
    long int temp_left[mid-l+1];
    for(int i=l;i<=mid;i++){
        temp_left[i-l] = a[i];
    }
    long int temp_right[r - mid];
    for(int i=mid+1;i<=r;i++){
        temp_right[i-mid-1] = a[i];
    }
    int k = l;
    int x1= 0;
    int x2 = 0;
    while(k<=r&&x1<=(mid-l)&&x2<=(r-mid-1)){
        if(temp_left[x1]<=temp_right[x2]){
            a[k] = temp_left[x1];
            k++;
            x1++;
        }
        else{
           count_inversion+=(mid-l-x1+1);
           a[k]=temp_right[x2];
           k++;
           x2++;
        }
    }
    while(x1<=(mid-l)){
        a[k] = temp_left[x1];
        k++;
        x1++;
    }
    while(x2<=(r-mid-1)){
        a[k] = temp_right[x2];
        k++;
        x2++;
    }
    return 0;

}

void merge_Sort(int l,int r,long int a[],int &count_inversion){
     if(l==r){
        return ;
     }
     int mid = l+(r-l)/2;
     merge_Sort(l,mid,a,count_inversion);
     merge_Sort(mid+1,r,a,count_inversion);
     mergeall(l,r,a,count_inversion);
}

int main(){   
    freopen("input1.txt", "r", stdin);
    
    cout<<"ENTER SIZE OF ARRAY"<<endl;
    int n;
    cin>>n;
    long int a[n];
    cout<<"ENTER THE ELEMENTS OF ARRAY"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count_inversion =0;
    merge_Sort(0,n-1,a,count_inversion); // function call
    cout<<count_inversion<<endl;
    return 0;
}
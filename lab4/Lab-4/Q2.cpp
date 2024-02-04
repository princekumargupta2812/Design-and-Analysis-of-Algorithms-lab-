// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
using namespace std;

double medianOfArray(int a[],int n,int b[],int m){
    int mid = (n+m+1)/2;
    mid--;
    int i =0;
    int j =0;
    int k =0;
    double ans = 0;
    while(k<(n+m)){
        if(i==n||b[j]<=a[i]){
            if((n+m)%2==1){
                if(k==mid){
                    ans+=b[j];
                }
            }
            else{
                if(k==mid||k==(mid+1)){
                    ans+=b[j];
                }
            }
            k++;
            j++;
        }
        else if(j==m||b[j]>a[i]){
            if((n+m)%2==1){
                if(k==mid){
                    ans+=a[i];
                }
            }
            else{
                if(k==mid||k==(mid+1)){
                    ans+=a[i];
                }
            }
            k++;
            i++;
        }
    }
    double f = ans;
    if((n+m)%2==0){
        return f/2;
    }
    return ans;
}



int main(){   
    freopen("input2.txt", "r", stdin);
    cout<<"ENTER SIZE OF  FIRST ARRAY"<<endl;
    int n;
    cin>>n;
    cout<<"ENTER SIZE OF  SECOND ARRAY"<<endl;
    int m;
    cin>>m;
    int a[n];
    cout<<"ENTER THE ELEMENTS OF FIRST ARRAY"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[m];
    cout<<"ENTER THE ELEMENTS OF SECOND ARRAY"<<endl;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    double  ans = medianOfArray(a,n,b,m);//function call
    cout<<setprecision(4)<<ans<<endl;
    return 0;
}
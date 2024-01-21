#include<bits/stdc++.h>
using namespace std;
vector<int>merge(int a[],int b[],int n,int m)
{   int i=0;
     int j=0;
     vector<int>ans;
    while(i<n&&j<m)
    {
      if(a[i]>b[j])
      {
        ans.push_back(b[j]);
        j++;
      }
      else
      {
        ans.push_back(a[i]);
        i++;
      }

    }
    if(i<n)
    {
        while(i<n)
        {
             ans.push_back(a[i]);
        i++;
        }
    }
    if(j<m)
    {
        ans.push_back(b[j]);
        j++; 
    }
    return ans;
}
vector<int>union_merge(int a[],int b[],int n,int m)
{   int i=0;
     int j=0;
     vector<int>ans;
    while(i<n&&j<m)
    {
      if(a[i]>b[j])
      {
        ans.push_back(b[j]);
        j++;
      }
      else if(a[i]==b[j])
      {
        ans.push_back(a[i]);
        i++;
        j++;
      }
      else
      {
        ans.push_back(a[i]);
        i++;
      }

    }
    if(i<n)
    {
        while(i<n)
        {
             ans.push_back(a[i]);
        i++;
        }
    }
    if(j<m)
    {
        ans.push_back(b[j]);
        j++; 
    }
    return ans;
}
vector<int>inter_merge(int a[],int b[],int n,int m)
{   int i=0;
     int j=0;
     vector<int>ans;
    while(i<n&&j<m)
    {
      if(a[i]>b[j])
      {
        
        j++;
      }
      else if(a[i]==b[j])
      {
        ans.push_back(a[i]);
        i++;
        j++;
      }
      else
      {
       
        i++;
      }

    }
    
    return ans;
}


int main(){
 int n,m;
 cin>>n>>m;
 int a[n];
 int b[n];

 for(int i=0;i<n;i++)
 cin>>a[i];

 for(int i=0;i<n;i++)
 cin>>b[i];



return 0;
}
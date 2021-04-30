#include <bits/stdc++.h>
using namespace std;


void insert(vector<int>&v,int temp,int size)
{
    if(size==0||v[size-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    
    int val = v[size-1];
    size--;
     v.pop_back();
     insert(v,temp,size);
     v.push_back(val);
    
    
}

void sort( vector<int>&v,int size)
{
    
    if(size==1)
        return;
        
    int temp=v[size-1];
    v.pop_back();
    size--;
    
    sort(v,size);
    insert(v,temp,size);
    
}


int main()
{
    vector<int>v;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
    
    sort(v,n);
    
    for(int i=0;i<n;i++)
    {
        
        cout<<v[i];
        
    }
    
    return 0;
}

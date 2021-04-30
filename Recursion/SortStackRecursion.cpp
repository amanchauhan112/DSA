//It is same as sorting array , just do push pop as done in stack and not as vector.

#include <bits/stdc++.h>
using namespace std;


void insert(stack<int>&s,int temp,int size)
{
    if(size==0||s.top()>=temp)
    {
        s.push(temp);
        return;
    }
    
    int val = s.top();
    size--;
    s.pop();
     insert(s,temp,size);
s.push(val);
    
    
}

void sort( stack<int>&s,int size)
{
    
    if(size==1)
        return;
        
    int temp=s.top();
    s.pop();
    size--;
    
    sort(s,size);
    insert(s,temp,size);
    
}


int main()
{
    stack<int>s;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        s.push(t);
    }
    
    sort(s,n);
    
    for(int i=0;i<n;i++)
    {
        
        cout<<s.top();
        s.pop();
        
    }
    
    return 0;
}

//OUTPUT
//5
//5 4 2 3 1
//12345

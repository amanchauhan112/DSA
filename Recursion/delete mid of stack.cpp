#include <bits/stdc++.h>
using namespace std;

void del_mid(stack<int>&s,int size,int original_size)
{
    if(size==(original_size/2)+1)
    {
        s.pop();
        return;
    }
    
    int val=s.top();
    s.pop();
    
    del_mid(s,--size,original_size);
    s.push(val);
}

int main()
{
    int n;
    cin>>n;
    
    stack<int>s;
    
    for(int i=0;i<n;i++)
    {
        int h;
        cin>>h;
        
        s.push(h);
    }
  //Here we are passing size and original_size
  //we can directy pass mid value only and decrease it and create our base condition accordingly 
    //like
    //int mid=size/2;
    //del_mid(s,mid);
//and base condition : if(mid==1) s.pop();return;
    del_mid(s,n,n);

    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    
    return 0;
}

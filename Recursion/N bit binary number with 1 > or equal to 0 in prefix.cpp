#include <bits/stdc++.h>
using namespace std;

void balance(int o,int z,string op,vector<string>&v,int n)
{
 
    if(n==0)
    {
        v.push_back(op);
        return;
    }
    
    if(o>z)
    {
           string op1=op;
        op1+="0";
       
   
        balance(o,z+1,op1,v,n-1);
    }
   if(o<n)
   {
       string op1=op;
        op1+="1";
        // in.erase(ip[0]+0)
    
        balance(o+1,z,op1,v,n-1);
   }
}

int main()
{
    int n;
    cin>>n;
    
    string output="1";
    int one=1,zero=0;
    n--;
    vector<string>v;
    
    balance(one,zero,output,v,n);
    
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
    
    return 0;
}

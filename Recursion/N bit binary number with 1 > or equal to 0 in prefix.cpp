//Eg. 11011
//Prefix 11011,1101,110,11,1
//Each prefix has 1 > equals 0

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
         string op1=op;
        op1+="1";
        balance(o+1,z,op1,v,n-1);

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

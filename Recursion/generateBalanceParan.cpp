//We have n i.e. number of open and close bracket
//print all strings of balanced paranthesis
//Eg . n 2 i.e 2 open 2 close
//()() and (())

#include <bits/stdc++.h>
using namespace std;

void balance(int o,int c,string op,vector<string>&v)
{
 
    if(o==0&c==0)
    {
        v.push_back(op);
        return;
    }
    
  
    if(o>0){
         string op1=op;
         op1+='(';
         balance(o-1,c,op1,v);
    }
    if(c>o){
         string op2=op;
         op2+=')';
         balance(o,c-1,op2,v);
    }


    
}

int main()
{
    int n;
    cin>>n;
    
    string output="";
    int open=n,close=n;
    
    vector<string>v;
    
    balance(open,close,output,v);
    
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
    
    return 0;
}

//To avoid duplicates use map before printing
//For lexographic order use vector and sort it 

#include <bits/stdc++.h>
using namespace std;

void subset(string ip,string op)
{
    
    if(ip.length()==0)
    {
        cout<<"\""<<op<<"\",";
        return;
    }
    
   string op1=op,op2=op;
   
   op2+=ip[0];
   
   ip.erase(ip.begin()+0);
   
   subset(ip,op1);
   subset(ip,op2);
   
    
}

int main()
{
    string input,output;
    
    cin>>input;
    
    cout<<"Subsets of given string are : \n ";
    
    subset(input,output);
    
    return 0;
}

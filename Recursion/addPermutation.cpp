//We need to add permutation inside string
// Eg. for ABC
// A_B_C A_BC AB_C ABC

#include <bits/stdc++.h>
using namespace std;

void addPermutation(string ip,string op)
{
 
    if(ip.length()==0)
    {
        cout<<"\""<<op<<"\",";
        return;
    }
    
   string op1=op,op2=op;
   
   op2=op2+"_"+ip[0];
   op1=op1+ip[0];
   ip.erase(ip.begin()+0);
    
   addPermutation(ip,op1);
   addPermutation(ip,op2);
    
}

int main()
{
    string input,output;
    
    cin>>input;
 
    output+=input[0];
    input.erase(input.begin()+0);   
       
    addPermutation(input,output);
    
    return 0;
}

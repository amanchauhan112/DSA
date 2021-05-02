//We need to do case change to upperCase permutation inside string
// Eg. for ab
// ab AB aB Ab

#include <bits/stdc++.h>
using namespace std;

void Permutation(string ip,string op)
{
 
    if(ip.length()==0)
    {
        cout<<"\""<<op<<"\",";
        return;
    }
    
   string op1=op,op2=op;
   
   op2+= toupper(ip[0]);
 
   op1=op1+ip[0];
   ip.erase(ip.begin()+0);
    
   Permutation(ip,op1);
   Permutation(ip,op2);
    
}

int main()
{
    string input,output;
    
    cin>>input;
  
    Permutation(input,output);
    
    return 0;
}

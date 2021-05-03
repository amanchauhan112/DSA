//We need to do case change permutation inside string
//skip digits
// Eg. for ab1
// ab1 AB1 aB1 Ab1

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
   
    if((ip[0]>='a'&&ip[0]<='z')||(ip[0]>='A'&&ip[0]<='Z'))
        {
            op2+= toupper(ip[0]);
            op1+= tolower(ip[0]);
            
            ip.erase(ip.begin()+0);
    
            Permutation(ip,op1);
            Permutation(ip,op2);
        }
    else 
    {
        op+= ip[0];
           ip.erase(ip.begin()+0);
    
        Permutation(ip,op);
    }



    
}

int main()
{
    string input,output;
    
    cin>>input;
  
    Permutation(input,output);
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void printN(int n){
    
    if(n<=1)
    {
         cout<<1;
           cout<<endl;
           cout<<1;
         return;
         
    }
       
    
    cout<<n;
    
    
    printN(n-1);

    cout<<n;
}

int main()
{
    
    int n;
    cin>>n;
    
    printN(n);
    
    return 0;
}

Output:

5 (Input)
54321
12345





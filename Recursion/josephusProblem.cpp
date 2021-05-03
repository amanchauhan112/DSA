//In a circle there are n people
//kill kth person and start counting from next to the killed person
//find remaining number

//other sol. not working
#include <bits/stdc++.h>
using namespace std;

// int balance(int k,int &ans,vector<int>v,int index)
// {
 
//     if(v.size()==1)
//     {
//         ans=v[0] ;
//         return ans;
//     }
//     else
//         return (balance(n - 1, k) + k-1) % n + 1;
//     // index=(index+k)%v.size();
//     // v.erase(v.begin()+index);
//     // balance(k,ans,v,index);
    
    
// }
int josephus(int n, int k)
{
 if (n == 1)
  return 1;
else
   return (josephus(n - 1, k) + k-1) % n + 1;
}

int main()
{
    int n,k;
    cin>>n>>k;

    // k--;
    
    // vector<int>v;
    // int ans=-1,index=0;
    
    // for(int i=0;i<n;i++)
    // {
    //   v[i]=i+1;
    // }
    
    // balance(k,ans,v,index);
    
    // cout<<balance(k,ans,v,index);
    cout<<josephus(n,k);
    return 0;
}

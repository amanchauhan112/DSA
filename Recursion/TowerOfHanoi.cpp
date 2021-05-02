//Here we have 3 towers
//First is Source which is 5 4 3 2 1(top)
//Second helper and Third destination
//We need to put Disc From source to destination tower in same manner as source
//but we cant put big disc above small disc.


#include <bits/stdc++.h>
using namespace std;

void hanoi(int s,int d,int h,int n,int & count)
{
    count++;
    if(n==1)
    {
        cout<<"Move disc from "<<s<<" to "<<d<<"\n";
        return;
    }
    
    hanoi(s,h,d,n-1,count);
    
    cout<<"Move disc from "<<s<<" to "<<d<<"\n";
    
    hanoi(h,d,s,n-1,count);
    
}

int main()
{
    int s,d,h,n,count=0;
    
    cin>>n;
    
    cout<<"1 is for source tower \n2 is for helper tower \n3 is for destination tower\n";
    
    s=1;
    h=2;
    d=3;
    
    hanoi(s,d,h,n,count);
    
    cout<<"Total number of steps : "<<count;
    
    return 0;
}

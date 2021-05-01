#include <bits/stdc++.h>
using namespace std;

//Supose stack is 1 2 3 4 5(top)
//So insert function will work as
//1(top)
//now insert 2
//so remove 1;
//insert 2 then insert 1
//similarly all steps
// so final stack will be 5 4 3 2 1(top)


void insert(stack<int>&s,int size,int val)
{
    if(size==0)
    {
        s.push(val);
        return;
    }
    
    int temp=s.top();
    s.pop();
    
    insert(s,--size,val);
    
    s.push(temp);

}

void reverse(stack<int>&s,int size)
{
    if(size==1)
    {
        return;
    }
    
    int val=s.top();
    s.pop();
    
    reverse(s,--size);
    
    insert(s,size,val);

}

int main()
{
    int n;
    cin>>n;
    
    stack<int>s;
    
    for(int i=0;i<n;i++)
    {
        int h;
        cin>>h;
        
        s.push(h);
    }

    reverse(s,n);

    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    
    return 0;
}

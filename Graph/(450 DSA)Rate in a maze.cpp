 void ansFunc(vector<string>&ans,int i,int j,vector<vector<int>> &m,int n,string str)
    {
      
        
        if(i==n-1&&j==n-1)
        {
            ans.push_back(str);
            return;
        }
          if (i >= 0 && j >= 0 && i < n && j < n && m[i][j])
            {
               m[i][j]=0;
               ansFunc(ans,i+1,j,m,n,str+"D"); 
               ansFunc(ans,i,j-1,m,n,str+"L"); 
               ansFunc(ans,i,j+1,m,n,str+"R"); 
               ansFunc(ans,i-1,j,m,n,str+"U"); 
               m[i][j]=1;
            }
            return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        // Your code goes here
        
        vector<string>ans;
        int i=0,j=0;
        
        string str;
        
        if(m[n-1][n-1]==0||m[0][0]==0)
            return ans;
        
      ansFunc(ans,i,j,m,n,str);   
        
      if(ans.size()==0)
           ans.push_back("-1");
      
      return ans;
        
    }

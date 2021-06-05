	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    
	    if(x1==x2&&y1==y2)  
	        return 0;
	    
	    int chess[1001][1001];
	    
	    for(int i=0;i<N;i++)
	    {
	        for(int j=0;j<N;j++)
	            chess[i][j]=0;
	    }
	    
	    
	    
	    queue<pair<int,int>>q;
	    q.push({x1-1,y1-1});
	    
	    while(!q.empty())
	    {
	        auto curr=q.front();
	        int r=curr.first;
	        int c=curr.second;
	        q.pop();
	        
	        if(r+1>=0&&r+1<N&&c+2>=0&&c+2<N&&chess[r+1][c+2]==0)
	        {
	            chess[r+1][c+2]=chess[r][c]+1;
	            q.push(make_pair(r+1,c+2));
	            
	        }
	         if(r-1>=0&&r-1<N&&c+2>=0&&c+2<N&&chess[r-1][c+2]==0)
	        {
	            chess[r-1][c+2]=chess[r][c]+1;
	            q.push(make_pair(r-1,c+2));
	            
	        }
	        if(r-2>=0&&r-2<N&&c+1>=0&&c+1<N&&chess[r-2][c+1]==0)
	        {
	            chess[r-2][c+1]=chess[r][c]+1;
	            q.push(make_pair(r-2,c+1));
	            
	        }
	         if(r+2>=0&&r+2<N&&c+1>=0&&c+1<N&&chess[r+2][c+1]==0)
	        {
	            chess[r+2][c+1]=chess[r][c]+1;
	            q.push(make_pair(r+2,c+1));
	            
	        }

	         
	         if(r-1>=0&&r-1<N&&c-2>=0&&c-2<N&&chess[r-1][c-2]==0)
	        {
	            chess[r-1][c-2]=chess[r][c]+1;
	            q.push(make_pair(r-1,c-2));
	            
	        }
	         if(r-2>=0&&r-2<N&&c-1>=0&&c-1<N&&chess[r-2][c-1]==0)
	        {
	            chess[r-2][c-1]=chess[r][c]+1;
	            q.push(make_pair(r-2,c-1));
	            
	        }
	         if(r+1>=0&&r+1<N&&c-2>=0&&c-2<N&&chess[r+1][c-2]==0)
	        {
	            chess[r+1][c-2]=chess[r][c]+1;
	            q.push(make_pair(r+1,c-2));
	            
	        }
	         if(r+2>=0&&r+2<N&&c-1>=0&&c-1<N&&chess[r+2][c-1]==0)
	        {
	            chess[r+2][c-1]=chess[r][c]+1;
	            q.push(make_pair(r+2,c-1));
	            
	        }
	        
	        
	    }
	    
	    return chess[x2-1][y2-1];
	    
	    return 0;
	}

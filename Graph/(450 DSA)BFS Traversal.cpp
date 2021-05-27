	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    
	    //For understanding purpose

	    
	    vector<int>v;
	    vector<int>visited(V,0);
	    queue<int>q;
	    q.push(0);
	    
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        v.push_back(temp);
	        
	   // for(int i=0;i<V;i++)
	   for(auto t:adj[temp])
	   
	    {
	        if(!visited[t])
	        {
	            
	            q.push(t);
	            visited[t]=1;
	            
	        }
	    }
	    
	    }
	    
	    return v;
	}

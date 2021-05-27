	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    
	    //For understanding purpose
	    // First node connected is given in adj
	    //For eg. : if 0 connected to 1 2 3
	    //adj[0] : 0->1->2->3
	   // then 1 and 3 are leaf node
	   // Node 2 is connected to leaf 4 
	   // so adj[2]: 2->4
	   // and adj[1],3,4:1,3,4
	    
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

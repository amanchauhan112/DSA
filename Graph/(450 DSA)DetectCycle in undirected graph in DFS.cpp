	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	  
	  bool visited[V];
	  memset(visited,false,sizeof(visited));//visited.size() is not valid  
	    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
           visited[i]=true;
            q.push(i);
            while(!q.empty())
            {
                int visited_count=0;
                int beg=q.front();
                q.pop();
                
                for(auto it=adj[beg].begin();it!=adj[beg].end();it++)
                {
                    if(!visited[*it])    //write *i and not i as it is iterator
                        {
                            q.push(*it);
                            visited[*it]=true;
                        }
                    else
                        {
                            visited_count++;
                        }
                }
                
                if(visited_count>1)
                    return true;
            }
        }
    }
    
    return false;
    
	}

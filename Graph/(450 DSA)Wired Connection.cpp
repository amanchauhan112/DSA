  void dfs(vector<vector<int>> &m,vector<bool> &visited,int src)
    {
        visited[src]=true;
        
        for(auto i:m[src])  //m is adj. list
        {
            if(!visited[i])
                dfs(m,visited,i);
        }
    }
        
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1)
            return -1;
        
//         map<int,int>m;  //use vector<vector<int>>v(n);       We are going to make adjuacency list so use vector
//         for(int i=0;i<connections.size();i++)
//         {
//             map[v[i][0]]=map[v[i][1]];
//             map[v[i][1]]=map[v[i][0]];
//         }
        
        vector<vector<int>>adj(n);
        
        for(auto node:connections)
        {
            adj[node[0]].push_back(node[1]);            
            adj[node[1]].push_back(node[0]);

        }
        
        vector<bool>visited(n,false);
        int extra=0;
                
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
           { dfs(adj,visited,i);
            extra++;}
        }  
        
        return extra-1;
    }

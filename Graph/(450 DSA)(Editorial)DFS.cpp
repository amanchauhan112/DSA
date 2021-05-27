// Recursive function for DFS:
// where v is the starting node/vertex

//first print current node and add its list and for each element of list repeat the same. 

// for checking visited or not:
//     map<int, bool> visited;

// Graph adj. map:
//     map<int, list<int>> adj;

// DFS traversal of the vertices reachable from v
    void DFS(int v);

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// In Algo like Kruskal, we used union and find method as:

//Find:{ if(parent[i]=- return i; else return Find(parent[i])  }
//Union:{  x=Find(parent,u);  y=Find(parent,v);  parent[x]=y;  }

//But this is O(n) approach
//Also if case is 0 1 2 3 
then tree can be : 0->1->2->3 (Like linked List)

We can do this in O(Log(n))
  
-->Her we will work on rank and path compression

              9
         /    |    \  
        4     5      6
     /     \        /  \
    0        3     7    8
            /  \
           1    2  



               9
         /    /  \    \
        4    5    6     3 
     /           /  \   /  \
    0           7    8  1   2
  
  
  //Here tree 3 1 2 moved upward, so its rank is increased.
  
  //We have Graph{{src,dest},{src,dest}........}
  //it has V , E
  //We also have subset (for Parents) => {{parent,rank},{parent,rank}-----V times...}


//Now ->
  
   for (int e = 0; e < E; ++e) {
        int x = find(subsets, graph->edge[e].src);
        int y = find(subsets, graph->edge[e].dest);
 
        if (x == y)
            return 1;
 
        Union(subsets, x, y);
    }

// A utility function to find set of an element i
// (uses path compression technique)

//If subset[i].parent==i return i
//else subset[i].parent=find(subsets,subsets[i].parent;

int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path
    // compression)
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int xroot, int yroot)
{
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and
    // increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// We are just checking Cycle in undirected Graph.

//1.Sort Edges according to weight.
//2.Pick an edge ,if it's not creating cycle add it to tree.
//3.Do step 2 till all edge connects.

// It's a greedy Algo

//T.C : O(E log E)

//Kruskal's Algorithm Applications
// In order to layout electrical wiring
// In computer network (LAN connection)

// If number of edges(E)=V-1 //We STOP

// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  
  for (i = 0; i < G.size(); i++) {
      
      
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    
//     cout<<i<<":"<<uRep<<","<<vRep<<"\n";
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int main() {
  Graph g(6);
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.print();
  return 0;
}



// First we are creating graph and sorting it.
//then we are making a parent array [0,1,2,3,4,5] (if V=5)
//Now we are takin (u,v) as uRep and vRep pair and checking if uRep!=vRep:
//if not ,push it into tree vector and make parent[uRep]=parent[vRep]
//else do nothing

//This is parent array after countering each edge pushed in tree

// 0 2 2 3 4 5 
// 0 2 5 3 4 5 
// 0 2 5 3 4 3 
// 0 2 5 4 4 3 
// 4 2 5 4 4 3 

//Final answer 
// Edge : Weight
// 1 - 2 : 2
// 2 - 5 : 2
// 2 - 3 : 3
// 3 - 4 : 3
// 0 - 1 : 4


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pointPair;

/* Structure "Graph" and "DisjointSets" */
/* Structure to represent a graph       */
struct Graph{
  int point;
  int edge;
  std::vector<pair<int, pointPair>> EDGE;

  /* Constructor */
  Graph(int P, int E){
    this->point = P;
    this->edge = E;
  }

  /* Utility function to add an edge */
   void addEdge(int u, int v, int w){
  EDGE.push_back({w, {u, v}});
  }

  /* Function to find MST using Kruskal's MST algorithm */
  int MST_KRUSKAL();
};

/* To represent Disjoint Sets */
struct DisjointSets{
  int *parent;
  int *rank;
  int n;
  /* Constructor */
  DisjointSets(int n){
    // Allocate memory
    this->n = n;
    this->parent = new int[n+1];
    this->rank = new int[n+1];

    /* Initially, all vertices are in diiferent sets and have rank 0 */
    for(int i=0; i<=n; i++){
      rank[i] =0;
      /* every element is parent of itself */
      parent[i] = i;
    }
  }
  /* Find the parent of a node 'u' Path Compression */
  int find(int u){
    /*   Make the parent of the nodes in the path     */
    /*   from u--> parent[u] point to parent[u]       */
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
  }

  /* Union by rank */
  void merge(int x, int y){
    x = find(x), y = find(y);

    /*   Make tree with smaller height    */
    /*   a subtree of the other tree      */
    /*   If rnk[x] <= rnk[y]              */
    if (rank[x] > rank[y]) parent[y] = x;
    else parent[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
  }
};

int Graph::MST_KRUSKAL()
{
  /*  Graph G with set of nodes G.V, weight matrix w.  */
  /*  MST is the edges set A={}.                       */

  /* Initialize result */
  int mst_wt = 0;

  /* Sort edge in increasing order on basis of cost */
  std::sort(EDGE.begin(), EDGE.end());

  /* Create disjoint sets */
  DisjointSets ds(point);

  /* Iterate through all sorte edges */
  std::vector<pair<int, pointPair>>::iterator it;

  for(it=EDGE.begin(); it!=EDGE.end(); it++){
    int u = it->second.first;
    int v = it->second.second;

    int set_u = ds.find(u);
    int set_v = ds.find(v);

    /*  Check if the selected edge is creating   */
    /*  a cycle or not (Cycle is created if u    */
    /*  and v belong to same set)                */
    if (set_u != set_v){
      /* Current edge will be in the MST so print it */
      cout << u << " - " << v << endl;

      /* Update MST weight */
      mst_wt += it->first;

      /* Merge two sets */
      ds.merge(set_u, set_v);
    }
  }
  return mst_wt;
}




int main()
{
  int point;
  int edge;
  std::cin >> point >> edge;
  Graph g(point, edge);

  /* making Graph */
  int w, u, v;
  for(int i=0; i<edge; i++){
    std::cin >> w >> u >> v;
    g.addEdge(w, u, v);
  }



  /* out put */
  std::cout << "Connecting vertex are" << std::endl;
  int mst_wt = g.MST_KRUSKAL();
  std::cout << "Weight of MST is " << mst_wt <<std::endl;

  return 0;
}

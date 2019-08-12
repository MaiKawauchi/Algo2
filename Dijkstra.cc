#include <iostream>
#include <queue>
#include <algorithm>
#define N 10000
#define INF 1000000000  //10^9

int n;
std::vector<std::pair<int, int> > adj[N];  //adjacent vertex

void dijkstra(){
  std::priority_queue<std::pair<int , int> > PQ;  //Container adapter
  std::vector<int> Set(N, 1); //create int number of N, all value initialization to 1
  std::vector<int> d(N, INF); //create int number of N, all value initialization to INF

  d[0] = 0;
  PQ.push(std::make_pair(0, 0)); //add elements of PQ
  Set[0] = 1;

  while( PQ.empty() != 1 ){
    std::pair<int, int> f = PQ.top(); //Extract elements in priority order
    PQ.pop();//Erase the next element

    int u = f.second;
    Set[u] = 2;

    if( d[u] < f.first*(-1) ) continue;

    //   std::cout << adj[u].size() << std::endl;
    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i].first;
      if( Set[v] == 2 )continue;
      if( d[v] > d[u] + adj[u][i].second ){
        d[v] = d[u] + adj[u][i].second;
        PQ.push(std::make_pair(d[v]*(-1), v));
        Set[v] = 1;
      }
    }
  }
  for(int j=0; j<n; j++){
    std::cout << "0 -> " << j << " cost " << (d[j] == INF ? -1 : d[j]) << std::endl;
  }
}

int main(){
  int u, k, v, c;

  //Input
  std::cin >> n;
  for(int i=0; i<n; i++){
    std::cin >> u >> k;
    for(int j=0; j<k; j++){
      std::cin >> v >> c;

      /* v:adjacent vertex u, c:waight from u to v */
      adj[u].push_back(std::make_pair(v, c));
    }
  }
  dijkstra();
  return 0;
}

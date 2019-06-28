#include <iostream>
#include <stack>

using namespace std;

static const int N = 101;  // MAX number of point
static const int WHITE = 0;
static const int BLACK = 1;
static const int GRAY = 2;

/* 0:WHITE, 1:BRACK, 2: GRAY  */
int coloer[N];
int firstVisit[N];
int secondVisit[N];
int A[N][N];
int n;
int nt[N];
int Time;

/*********************************************************
 * u:Top of stack
 *********************************************************/
int next(int u)
{
  for(int v=nt[u]; v<n; v++){
    nt[u] = v+1;
    if( A[u][v] ) return v;
  }
  return -1;
}
/*********************************************************
 * id:number of "i",  n:number of point
 *********************************************************/
void DFS_Visit(int r)
{
  for(int i=0; i<n; i++) nt[i] = 0;

  std::stack<int> S;
  S.push(r);
  coloer[r] = GRAY;    // 2:GRAY
  firstVisit[r] = ++Time;

  while( !S.empty() ){
    int u = S.top();
    int v = next(u);
    if( v != -1 ){
      if( coloer[v] == WHITE ){  // 0:WHITE;
        coloer[v] = GRAY;
        firstVisit[v] = ++Time;
        S.push(v);
      }
    }else{
      S.pop();
      coloer[u] = BLACK;
      secondVisit[u] = ++Time;
    }
  }
}

/*********************************************************
 * id:number of "i",  n:number of point
 *********************************************************/
void Depth()
{
  /* Initialization */
  for(int i=0; i<n; i++){
    coloer[i] = WHITE;   // 0:WHITE
    nt[i] = 0;
  }
  Time = 0;

  /* visit each node */
  for(int u=0; u<n; u++){
    if(coloer[u] == WHITE) DFS_Visit(u);  // 0:WHITE
  }
  for(int i=0; i<n; i++){
    std::cout << i+1 << " " << firstVisit[i]
              << " " << secondVisit[i] << std::endl;
  }
}

int main(){

  std::cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++) A[i][j]=0;
  }

  /* u:vertex number, k:time, v:adjacency point */
  int u, k, v;
  for(int i=0; i<n; i++){
    std::cin >> u >> k;
    u--;
    for(int j=0; j<k; j++){
      std::cin >> v;
      v--;
      A[u][v]=1;
    }
  }

  Depth();

  return 0;
}

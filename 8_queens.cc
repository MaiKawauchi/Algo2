/*
Position one queen and show some solutions.
*/
#include <iostream>
using namespace std;

#define N 8
#define Free -1
#define NoFree 1

bool m[N][N];
int row[N];
int col[N];
int dposition[N*2-1];
int dnegotiation[N*2-1];

void Initialize()
{
  for(int i=0; i<N; i++) {
    row[i] = Free,
    col[i] = Free;
  }
  for(int i=0; i<2*N-1; i++){
    dposition[i] = Free,
      dnegotiation[i] = Free;
  }
}

void Print()
{
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if( m[i][j] ){
        if( row[i] != j ) return;
      }
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      std::cout << ((row[i] == j) ? "Q" : "." );
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void putQueen()
{
  for(int col=0; col<N; col++){
  }
}

void Recursive(int i){
  //success placement of Queen
  if( i == N ){
    Print();
    return;
  }
  //if attacked by Queen, ignore.
  for(int j=0; j<N; j++){
    if( col[j] == NoFree ||
        dposition[i+j] == NoFree ||
        dnegotiation[i-j+N-1] == NoFree ) continue;

    //placement of Queen in (i,j)
    row[i] = j;
    col[j] = dposition[i+j] = dnegotiation[i-j+N-1] = NoFree;
    //next row
    Recursive(i+1);
    //Remove Queen placed in (i,j)
    row[i] = col[j] = dposition[i+j] = dnegotiation[i-j+N-1] = Free;
  }
  //Failure
}
int main()
{
  Initialize();

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      m[i][j] = false;
    }
  }

  int r, c;
  std::cin >> r >> c;
  m[r][c] = true;
  Recursive(0);
}

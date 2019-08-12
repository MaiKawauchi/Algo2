#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rand_seq[] = {};

/*---------------------------------------*/
/* RAND1                                 */
/* n:Number of random integers           */
/*---------------------------------------*/
void RAND1(int n)
{
  /* seed */
  int x = 53402397;
  for(int i=0; i<n; i++) rand_seq[i] = {};
  for(int i=1; i<=n; i++){
    x = ((65539 * x) + 125654);

    /* Check for overflow */
    if(x < 0){
      x += 2147483647;
      x += 1;
    }
    rand_seq[i] = x;
  }
}

/*---------------------------------------*/
/* RAND2                                 */
/* n:Number of random integers           */
/*---------------------------------------*/
void RAND2(int n)
{
  /* seed */
  int x = 1;
  int A = 48271;
  int M = 2147483647;
  int Q = M / A;
  int R = M % A;
  for(int i=0; i<n; i++) rand_seq[i] = {};
  for(int i=1; i<=n; i++){
    x = A * (x % Q) - R * (x / Q);

    /* Check for overflow */
    if(x < 0){
      x += M;  //  +(M-1)
    }
    rand_seq[i] = x;
  }
}


/*---------------------------------------*/
/* RAND3                                 */
/* n:Number of random integers           */
/*---------------------------------------*/
void RAND3(int n)
{
  /* seed */
  int x = 1;
  int next = 0;
  int B[100]={};
  RAND2(55);
  for(int i=0; i<55; i++) {
    B[i] = rand_seq[i];
    rand_seq[i] = 0;
  }
  for(int i=0; i<=n; i++){
    int j = (next + 31) % 55;
    x = B[j] - B[next];

    /* Check for overflow */
    if(x<0){
      x += 2147483647;
      x += 1;
    }
    B[next] = x;
    next = (next + 1) % 55;
    rand_seq[i] = x;
  }
}

int main()
{
  int n;
  std::cin >> n;

  /*--------------------------- RAND1 ------------------------------*/
  RAND1(n);
  std::cout <<  "----- Rand1 -----"<< std::endl;
  for(int i=1; i<=n; i++) std::cout << rand_seq[i] << std::endl;

  /*--------------------------- RAND2 ------------------------------*/
  RAND2(n);
  std::cout <<  "----- Rand2 -----"<< std::endl;
  for(int i=1; i<=n; i++) std::cout << rand_seq[i] << std::endl;

  /*--------------------------- RAND3 ------------------------------*/
  RAND3(n);
  std::cout <<  "----- Rand3 -----"<< std::endl;
  for(int i=1; i<=n; i++) std::cout << rand_seq[i] << std::endl;

  return 0;
}

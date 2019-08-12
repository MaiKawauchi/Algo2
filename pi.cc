#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>

using namespace std;

double PI(int n)
{
  double inCircle = 0.0;
  double x, y;
  double d;

  /* 乱数の種を初期化 */
  //  std::random_device rd;
  //  std::mt19937 mt(rd());


  /* 0 〜 1 の乱数を生成・出力 */
  for(int i=1; i<=n; i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;
    d = ((x - 0.5)*(x - 0.5)) + ((y - 0.5)*(y - 0.5));
    if( d < 0.25) inCircle += 1;
  }

  return 4 * inCircle / n;
}

int main()
{
  int N;
  cin >> N;

  for(int i=0; i<10; i++){
    //PI(N);
    cout << PI(N) << endl;
  }
  return 0;
}

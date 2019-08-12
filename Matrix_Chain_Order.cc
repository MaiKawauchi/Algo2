#include <bits/stdc++.h>
//#include <iomanip>
using namespace std;

void Print(int n, int i, int j, int *brackets, char &piyo)
{
  if(i==j){
    cout << piyo++;
    return;
  }
  std::cout << "(";
  Print(n, i, *((brackets+i*n)+j), brackets, piyo);
  Print(n, *((brackets+i*n)+j) + 1, j, brackets, piyo);
  std::cout << "(";
}

void MatrixChainOrder(int p[], int n)
{
  int min = INT_MAX;
  int m[n][n];
  int brackets[n][n];

  /* cost is zero when multiplying one matrix */
  for (int i=1; i<n; i++) m[i][i] = 0;

  /* L is chain length */
  for(int L=2; L<n; L++){
    for(int i=1; i<n-L+1; i++){
      int j = i+L-1;
      m[i][j] = min;
      for(int k=i; k<j-1; k++){
        int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if(q < m[i][j]){
          m[i][j] = q;
          brackets[i][j] = k;
        }
      }
    }
  }
  char piyo = 'A';

  cout << "Optimal Parenthesization is : ";
  Print(n, 1, n-1, (int *)brackets, piyo);
  cout << endl;
  cout << "nOptimal Cost is : " << m[1][n-1] << endl;
  for(int i=1; i<n; i++){
    for(int j=1; j<n; j++){
      if(i==j) m[i][j] = 0;
      if(i>j) m[i][j] =0;
      cout << std::setprecision(5) << m[i][j] << ", ";
    }
    cout << endl;
  }
}

int main()
{
  int arr[] = {30,35,15,5,10,20,25};
  int n = sizeof(arr)/sizeof(arr[0]) -1;
  MatrixChainOrder(arr, n);

  return 0;
}

#include <stdio.h>
#include <iostream>
//using namespace std:

const int MAX = 100;

void multiplyMatrixRec(int row1, int col1, int A[][MAX],
                       int row2, int col2, int B[][MAX],
                       int C[][MAX])
{
    static int i = 0, j = 0, k = 0;
    // If all rows traversed.
    if (i >= row1)
        return;

    // If i < row1
    if (j < col2){
      if (k < col1){
         C[i][j] += A[i][k] * B[k][j];
         k++;
         multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
      }
      k = 0;
      j++;
      multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
    }
    j = 0;
    i++;
    multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
}
/*-------------------------------------------------------*/
// Function to multiply two matrices A[][] and B[][]
/*-------------------------------------------------------*/
void multiplyMatrix(int row1, int col1, int A[][MAX],
                    int row2, int col2, int B[][MAX])
{

  int C[MAX][MAX] = {0};

  multiplyMatrixRec(row1, col1, A, row2, col2, B, C);

  for (int i = 0; i < row1; i++)
    {
      for (int j = 0; j < col2; j++)
        std::cout << C[i][j] << " ";
      std::cout << std::endl;
    }
}

int main()
{
  /*--- If you calculate another matrix, change under the matrix ----*/
  int A[][MAX] = { {1, 3},
                   {7, 5}};

  int B[][MAX] = { {6, 8},
                   {4, 2} };

  /*----- N * N , number of matrix -----*/
  int row1 = 2, col1 = 2, row2 = 2, col2 = 2;
  multiplyMatrix(row1, col1, A, row2, col2, B);

  return 0;
}

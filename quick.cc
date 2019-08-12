#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>

void printArray(int arr[], int n);

using namespace std;
int *rand_seq;

/*--------------------------------------------------------------------*/
/*  pibot                                                             */
/*--------------------------------------------------------------------*/
static int randomNumber(int low, int high)
{
  static mt19937 mt(high);
  uniform_int_distribution<> range_rnd{ low /* Minimum value */, high /* Maximum value */ };
  const auto valRnd = range_rnd( mt ); /* Get random number in specified range */
  return valRnd;
}

/*--------------------------------------------------------------------*/
/*  create random array                                               */
/*--------------------------------------------------------------------*/
void RAND(int n)
{
  rand_seq = new int[n];
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
    rand_seq[i-1] = x;
  }
}



int partition(int arr[], int low, int high,int mid)
{
  cout << arr[0]  <<" " <<low << " "<< high  <<", "<< mid <<endl;
  int i = low-1, j = high+1;
  int pibot = arr[mid];
  while (i<j) {
    do {
      i++;
      // if(i>=mid) break;
    } while (arr[i] < pibot);
    do {
      j--;
      //  if(j<=mid) break;
    } while (arr[j] > pibot);
    if (i >= j)
      return j;

    swap(arr[i], arr[j]);
  }
}


int partition_r(int arr[], int low, int high, int pi)
{
  int mid = (high-low) / 2 + low;
  swap(arr[pi], arr[mid]);

  return partition(arr, low, high, mid);
}

void quickSort(int arr[], int low, int high) 
{ 
  if (low < high) { 
    int pi = randomNumber(low, high); 

    int mid= partition_r(arr, low, high, pi);

    quickSort(arr, low, mid); 
    quickSort(arr, mid + 1, high); 
  }
}



void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}


// Driver program to test above functions
int main()
{
  int N;
  cin >> N;
  int arr[] = {};
  double sum=0;
  double ave=0;

  for(int i=0; i<100; i++){
    clock_t start = clock();
  RAND(N);
  quickSort(rand_seq, 0, N-1);
  clock_t end = clock();
  sum = sum + (double)end-(double)start;
  }
  ave = sum/100;
  cout << "Sorted array: ";
  printArray(rand_seq, N);

  cout << ave << endl;
  return 0;
}

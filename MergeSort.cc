#include <iostream>
#include <vector>

using namespace std;

#define MAX 500000
#define SENTINEL 200000

int merge(int A, int B){ // A->left, B->right
  std::vector<int> Left;
  std::vector<int> Right;
  std::vector<int> result;
  bool b = result.empty();
  std::cout << std::boolalpha << b << std::endl;
  Left.push_back(A);
  Right.push_back(B);

  std::cout << Left.size() << std::endl;

  while( Left.size() > 0 || Right.size() > 0){
    if(Left.size()>0 && Right.size()>0){
      if(Left[1] <= Right[1]){
        result.push_back(Left[1]);
        Left.erase(Left.begin() + 1);
      }else{
        result.push_back(Right[1]);
        Right.erase(Right.begin() + 1);
      }
    }else if(Left.size()>0){
      result.push_back(Left[1]);
      Left.erase(Left.begin() + 1);
    }else if(Right.size()>0){
      result.push_back(Right[1]);
      Right.erase(Right.begin() + 1);
    }
  }
  int i=0;
  return result[i];
  i++;
}

int mergeSort(int A){ // A->str
  std::vector<int> str;
  std::vector<int> Left;
  std::vector<int> Right;
  int mid;
  str.push_back(A);
  mid = str.size()/2;
  for(int i=1; i<=mid; i++) Left.push_back(mergeSort(str[i]));
  for(int i=mid+1; i<=str.size(); i++) Right.push_back(mergeSort(str[i]));
  int i=0;
  i++;
  return merge(Left[i], Right[i]);
}

int main(){
  std::vector<int> result;
  int A[MAX];
  int n;

  std::cin >> n;
  for(int i=0; i<n; i++){
    std::cin >> A[i];
    mergeSort(A[i]);
  }
  for(int i=0; i<n; i++){
    if(i) std::cout << " ";
    std::cout << result[i] << " ";
  }
  std::cout << endl;

  return 0;
}

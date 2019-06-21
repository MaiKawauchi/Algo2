#include <iostream>
#include <vector>

using namespace std;

void merge( std::vector<int> Left,
	    std::vector<int> Right,
	    std::vector<int>& result)
{  
  result.clear();

  while( Left.size() > 0 || Right.size() > 0 ){
    if( Left.size() > 0 && Right.size() > 0 ){
      if(Left[0] <= Right[0]){
        result.push_back( Right[0] );
	Right.erase( Right.begin() );
      }else{
        result.push_back( Left[0] );
        Left.erase( Left.begin() );
      }
    }else if( Left.size() > 0 ){
      result.push_back( Left[0] );
      Left.erase( Left.begin() );
    }else if( Right.size() > 0 ){
      result.push_back( Right[0] );
      Right.erase( Right.begin() );
    }
  }
}

int mergeSort(std::vector<int>& A)
{
  if( A.size() <= 1 ) return 0;
  int mid = A.size()/2;

  std::vector<int> Left = std::vector<int>( A.begin(), A.begin()+mid );
  std::vector<int> Right = std::vector<int>( A.begin()+mid, A.end() );

  mergeSort( Left );
  mergeSort( Right );
  merge( Left, Right, A );
}

int main(){
  std::vector<int> data = {8, 6, 4, 7, 1};
  mergeSort( data );

  std::sort( data.begin(), data.end() );
  for(int i=0; i<data.size(); ++i) std::cout << data[i] << " ";
  std::cout << std::endl;

  return 0;
}

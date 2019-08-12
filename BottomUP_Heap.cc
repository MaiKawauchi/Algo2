#include <iostream>
#include <vector>

int h;
int key[500010];


void BottomUPHeap(int i){
  int l = i*2;
  int r = i*2+1;
  int largest = l;
  if(l <= h && key[l] > key[i]){ largest = l; }
  else { largest = i; }
  if(r <= h && key[r] > key[largest]){ largest = r; }
  if(largest != i){
    std::swap(key[i], key[largest]);
    BottomUPHeap(largest);
  }
}

void buildBottomUPHeap(){
  for(int i=h/2; i>=1; i--){ BottomUPHeap(i); }
}

int main(){
  std::cin >> h;
  for(int i=1; i<h+1; i++){ std::cin >> key[i]; }

  buildBottomUPHeap();

  for(int i=1;i<h+1; i++){
    if( i!=h+1 ){ std::cout << " "; }
    std::cout << key[i];
  }
  std::cout << std::endl;
  return 0;
}

#include <iostream>
#include <queue>
#include <map>
#include <cstdio>

using namespace std;

struct vertex {
  char str;
  vertex *left;
  vertex *right;
  int cost;

  vertex(char _c, vertex *_left, vertex *_right, int _cost)
    : str(_c), left(_left), right(_right), cost(_cost) {}
};

struct vertexComp {
  bool operator()(const vertex *x, const vertex *y) const {
    return x->cost > y->cost;
  }
};

void getEncode(map<char, string> &encode, vertex *vp, string s) {
  if(vp == NULL)
    return;
  if(vp->str)
    encode[vp->str] = s;
  getEncode(encode, vp->left, s+'0');
  getEncode(encode, vp->right, s+'1');
}

void huffmanCoding(int cnt[]) {
  priority_queue<vertex*, vector<vertex *>, vertexComp> Q;
  for(int i = 0; i < 26; i++)
    Q.push(new vertex((char)('A'+i), NULL, NULL, cnt[i]));

  while(Q.size() > 1) {
    vertex *ver1 = Q.top(); Q.pop();
    vertex *ver2 = Q.top(); Q.pop();
    Q.push(new vertex(0, ver1, ver2, ver1->cost + ver2->cost));
  }

  map<char, string> encode;
  getEncode(encode, Q.top(), "");

  for(map<char, string>::iterator itr = encode.begin(); itr != encode.end(); itr++){
    if(cnt[itr->first-'A'] > 0){
      printf("%c [%6d] -> %10s\n", itr->first, cnt[itr->first-'A'], itr->second.c_str());
    }
  }
}

int main() {
  int str, cnt[26] = {0};
  while((str = getchar()) != EOF) {
    if('A' <= str && str <= 'Z')
      ++cnt[str-'A'];
  }

  huffmanCoding(cnt);

  return 0;
}

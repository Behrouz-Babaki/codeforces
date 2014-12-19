#include <iostream>
#include <vector>
#include <utility>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::make_pair;

typedef vector<pair<size_t, size_t> > vss;
typedef vector<vss> vvss;

vvss tree;
vector<size_t> sum;
vector<size_t> sum_sq;
vector<size_t> num;

size_t f (size_t first, size_t second) {
  return first + second;
}

void dfs (size_t node, size_t parent) {
  
}

int main(void) {
  size_t n;
  cin >> n;
  tree.resize(n+1,0);
  sum.resize(n+1,0);
  sum_sq.resize(n+1,0);
  num.resize(n+1);

  size_t first, second, weight;
  for (size_t i = 0; i <n-1; i++) {
    cin >> first >> second >> weight;
    tree[first].push_back(make_pair(second, weight));
    tree[second].push_back(make_pair(first, weight));
  }
  
  //The offline computation
  dfs(1, -1);
  
  size_t q;
  cin >> q;
  for (size_t i = 0; i < q; i++) {
    cin >> first >> second;
    cout << f(first,second) << endl;
  }

  return 0;
}

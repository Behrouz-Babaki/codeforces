#include <iostream>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::cin;
using std::multiset;
using std::max;

int max_pairs(multiset< int >&, multiset< int >&);

int main(void) {
  int m, n, j;

  cin >> n;
  multiset< int > a;
  for(int i=0; i<n; i++) {
    cin >> j;
    a.insert(j);
  }
  
  cin >> m;
  multiset< int > b;
  for(int i=0; i<m; i++) {
    cin >> j;
    b.insert(j);
  }

  cout << max_pairs(a, b) << endl;

  return 0;
}

int max_pairs(multiset< int >& a, multiset< int >&b){

  if (a.empty() || b.empty())
    return 0;

  auto pos = a.begin();
  int boy = *pos;
  a.erase(pos);
  int max_val = max_pairs(a, b);

  for (int inc=-1; inc <= 1; inc++) {
    int girl = boy + inc;
    pos = b.find(girl);
    if (pos != b.end()) {
      b.erase(pos);
      max_val = max(max_val , max_pairs(a, b) + 1);
      b.insert(girl);
    }
  }

  a.insert(boy);
  return max_val;
}



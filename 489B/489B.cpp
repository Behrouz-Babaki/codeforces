#include <iostream>
#include <algorithm>
#include <set>

using std::cout;
using std::endl;
using std::cin;
using std::set;
using std::max;

int max_pairs(set< int >&, set< int >&);

int main(void) {
  int m, n, j;

  cin >> n;
  set< int > a;
  for(int i=0; i<n; i++) {
    cin >> j;
    a.insert(j);
  }
  
  cin >> m;
  set< int > b;
  for(int i=0; i<m; i++) {
    cin >> j;
    b.insert(j);
  }

  cout << max_pairs(a, b) << endl;

  return 0;
}

int max_pairs(set< int >& a, set< int >&b){
  if (a.empty() || b.empty())
    return 0;

  set< int >::iterator pos = a.begin();
  int boy = *pos;
  a.erase(pos);
  int max_val = max_pairs(a, b);

  for (int inc=-1; inc <= 1; inc+=2) {
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

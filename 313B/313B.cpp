#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main(void) {
  string st;
  cin >> st;
  int n = st.size();
  vector< int > counts(n);
  counts[0] = 0;
  for (int i=1; i<n; i++) 
    counts[i] = counts[i-1] + (st[i-1] == st[i]);

  int m;
  cin >> m;
  for (int i=0; i<m; i++) {
    int l, r;
    cin >> l >> r;
    cout << counts[r-1] - counts[l-1] << endl;
  }
  return 0;
}

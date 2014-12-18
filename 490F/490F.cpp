#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::lower_bound;
using std::max;

vector<int> d;
vector<int> graph [6001];
int r[6001];
int n;
int ans;

void dfs (int q, int p) {
  auto itr = lower_bound(d.begin(), d.end(), r[q]);
  int save = *itr;
  *itr = r[q];
  ans = max(ans, int(itr - d.begin()) + 1);
  
  for (auto i : graph[q])
    if (i != p)
      dfs (i, q);

  *itr = save;
}

int main(void) {
  cin >> n;

  for (int i = 1; i <=n ; i++)
    cin >> r[i];
  
  for (int i= 1; i < n; i++) {
    int first, second;
    cin >> first >> second;
    graph[first].push_back(second) , graph[second].push_back(first);
  }

  ans = 0;
  for (int i=1; i<=n; i++) {
    d.resize(n + 1, 10e6 + 1);
    dfs (i, -1);
  }

  cout << ans << endl;
  return 0;
}

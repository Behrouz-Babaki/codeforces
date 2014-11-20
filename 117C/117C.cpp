#include <iostream>
#include <vector>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::ws;
using std::string;
using std::getline;
using std::vector;

typedef vector<size_t> vs;
typedef vector<int> vi;
typedef vector<vs> vvs;

#define TRvvs(c, it) \
  for (vvs::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

#define TRvs(c, it) \
  for (vs::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

#define TRvi(c, it) \
  for (vi::iterator it = (c).begin(), eit = (c).end(); it != eit; it++)

void dfs(vvs& graph, size_t u);

vs dfs_num;
vi parent;
int a, b, c;
bool finished;

int main(void) {
  size_t n;
  cin >> n >> ws;
  vvs graph(n, vs());

  dfs_num.resize(n, 0);
  parent.resize(n, -1);
  finished = false;
  a = b = c = -1;

  string line;
  for (size_t line_cnt = 0; line_cnt < n; line_cnt++) {
    getline(cin, line);
    for (size_t char_cnt = 0; char_cnt < n; char_cnt++) {
      if (line.at(char_cnt) == '1')
	graph[line_cnt].push_back(char_cnt);
    }
  }
  for (size_t counter = 0; counter < n; counter++)
    if (!dfs_num[counter])
      dfs(graph, counter);
  if (a >= 0)
    cout << a+1 << " " << b+1 << " " << c+1 << endl;
  else
    cout << -1 << endl;

  return 0;
}

void dfs(vvs& graph, size_t u) {
  TRvs (graph[u], it)
    if (!dfs_num[*it]) {
      dfs_num[*it] = 1;
      parent[*it] = u;
      dfs(graph, *it);
      if (finished)
	return;
    }
    else if (parent[u] != -1 &&
	     parent[parent[u]] == *it) {
      a = u;
      c = parent[u];
      b = parent[c];
      finished = true;
    }
}

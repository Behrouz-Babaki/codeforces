#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
using std::lower_bound;
using std::max;

int main(void) {
  int n;
  cin >> n;
  vector<pair<int, int> > trees(n);
  for (int tree_cnt = 0; tree_cnt < n; tree_cnt++) {
    pair<int, int> current_tree;
    cin >> current_tree.first >> current_tree.second;
    trees[tree_cnt] = current_tree;
  }
  sort(trees.begin(), trees.end());
  vector<pair<int, int> >::iterator itr = lower_bound(trees.begin(), 
						      trees.end(), 
						      make_pair(0, 0));
  vector<pair<int, int> >::iterator itr2 = itr;
  int mult = 1;
  int num = 1;
  int total1 = 0;
  while (itr2 != trees.end() && itr2 >= trees.begin()) {
    total1 += itr2->second;
    mult *= -1;
    itr2 += (num * mult);
    num++;
  }
  
  itr2 = itr-1;
  mult = -1;
  num = 1;
  int total2 = 0;
  while (itr2 != trees.end() && itr2 >= trees.begin()) {
    total2 += itr2->second;
    mult *= -1;
    itr2 += (num * mult);
    num++;
  }

  cout << max(total1,total2) << endl;

  return 0;
}

#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::max;

int main(void) {
  int length;
  int piece[3];
  cin >> length >> piece[0] >> piece[1] >> piece[2];
  vector<int> memo(length+1);
  memo[0] = 0;
  for (int i=1; i<=length; i++) {
    int m = -1;
    for (int j=0; j<3; j++)
      if (i >= piece[j] && memo[i-piece[j]]>=0)
      m = max(m, 1+memo[i-piece[j]]);
    memo[i] = m;
  }
  cout << memo[length] << endl;
  return 0;
}

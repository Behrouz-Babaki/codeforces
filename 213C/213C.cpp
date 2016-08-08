#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

int main(void) {
  int n;
  cin >> n;
  vector<vector<int> > nums(n, vector<int>(n));
  vector<vector<vector<int> > > memo(2*n-1, vector<vector<int> >(n, vector<int>(n, -1e6)));

  for (int row=0; row<n; row++)
    for (int col=0; col<n; col++)
      cin >> nums[row][col];

  memo[0][0][0] = nums[0][0];
  for (int d=1; d<2*n-1; d++) {
    int first, last;
    if (d<n) {
      first = 0;
      last = d;
    } 
    else {
      first = d-n+1;
      last = n-1;
    }
    for (int r1=first; r1<=last; r1++)
      for (int r2=first; r2<=last; r2++) {
  	int c1 = d - r1;
  	int c2 = d - r2;
  	int m = -(1e6);
  	if (r1 > 0 && c2>0)
  	  m = max(m, memo[d-1][r1-1][r2]);
  	if (c1 > 0 && c2>0)
  	  m = max(m, memo[d-1][r1][r2]);
  	if (c1 > 0 && r2 > 0)
  	  m = max(m, memo[d-1][r1][r2-1]);
  	if (r1>0 && r2 > 0)
  	  m = max(m, memo[d-1][r1-1][r2-1]);
  	// update the memo table
  	memo[d][r1][r2] = m + nums[r1][c1];
  	if (r1 != r2)
  	  memo[d][r1][r2] += nums[r2][c2];
      }
  }
  cout << memo[2*n-2][n-1][n-1] << endl;
  return 0;
}

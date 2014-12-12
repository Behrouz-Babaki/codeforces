#include <iostream>
#include <algorithm>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::min;
using std::sort;
using std::vector;


int main(void) {
  size_t m, n;
  cin >> n >> m;
  vector<int> numbers(m);
  for(size_t counter = 0; counter < m; counter++)
    cin >> numbers[counter];
  sort(numbers.begin(), numbers.end());

  size_t diff = numbers[n-1] - numbers[0];
  size_t diff2;
  for(size_t counter = n; counter < m; counter++) {
    diff2 = numbers[counter] - numbers[counter-n+1];
    if (diff2 < diff)
      diff = diff2;
  }

  cout << diff << endl;
  return 0;
}

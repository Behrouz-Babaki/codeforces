#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(void) {
  int n, d;
  cin >> n >> d;
  vector<int> prices(n);
  for (int i=0; i<n; i++)
    cin >> prices[i];
  
  return 0;
}

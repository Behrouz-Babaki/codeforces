#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (void) {
  size_t m, n, a;
  cin >> m >> n >> a;
  unsigned long long int res1 = (m/a + (size_t)(m%a != 0));
  unsigned long long int res2 = (n/a + (size_t)(n%a != 0));
  unsigned long long int result = res1 * res2;
  cout << result << endl;
  return 0;
}

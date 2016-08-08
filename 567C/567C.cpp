#include <iostream>
#include <map>

using std::endl;
using std::cout;
using std::cin;
using std::map;

int main(void) {
  int n, k;
  cin >> n >> k;
  unsigned long long count = 0;
  map<unsigned long long, unsigned long long> c1;
  map<unsigned long long, unsigned long long> c2;
  
  for (int i=0; i<n; i++) {
    long num;
    cin >> num;
    if (num%k == 0) {
      count += c2[num/k];
      c2[num] += c1[num/k];
    }
    c1[num]++;
  }

  cout << count << endl;
  return 0;
}

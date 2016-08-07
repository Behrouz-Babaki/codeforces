#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(void) {
  int n;
  cin >> n;
  int longest = 1;
  int current_seq = 1;
  int current;
  int prev;
  cin >> prev;
  for (int i=1; i<n; i++) {
   cin >> current;
   if (current >= prev) {
     current_seq++;
     longest = (longest < current_seq) ? current_seq : longest;
   }
   else
     current_seq = 1;
   prev = current;
  }

  cout << longest << endl;
  return 0;
}

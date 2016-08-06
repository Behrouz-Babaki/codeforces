#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min;

int main(void) {
  int n, d;
  cin >> n >> d;
  
  vector<int> prices(n);
  int total = 0;
  for (int i=0; i<n; i++) {
    cin >> prices[i];
    total += prices[i];
  }

  vector<bool> possible_totals(total+1, false);
  possible_totals[0] = true;

  int running_total = 0;
  for (int i=0; i<n; i++) {
    // update possible totals
    int current_price = prices[i];
    running_total += current_price;
    for (int j=running_total; j>=current_price; j--) {
      if (possible_totals[j-current_price])
	possible_totals[j] = true;
    }
  }

  int index = 0;
  int days = 0;
  bool found = false;
  while (!found) {
    bool found_max = false;
    int current_index = min(index + d, total);
    for (; !found_max && current_index > index; current_index--)
      if (possible_totals[current_index]) {
	found_max = true;
	days++;
	index = current_index;
      }
    if (!found_max || index==total) {
      cout << index << " " << days << endl;
      found = true;
    }
  }

  return 0;
}

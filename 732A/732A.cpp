#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::vector;

int main(void) {
  int t;
  cin >> t;
  for (int cnt=0; cnt<t; cnt++) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++)
      cin >> a[i];
    for (int i=0; i<n; i++)
      cin >> b[i];

    int a_sum = 0, b_sum = 0, d_sum = 0;
    for (int i=0; i<n; i++) {
      a_sum += a[i];
      b_sum += b[i];
      int d = a[i] - b[i];
      d = d > 0 ? d : -d;
      d_sum += d;
    }

    if (a_sum != b_sum) {
      cout << "-1" << endl;
      continue;
    }

    cout << d_sum / 2 << endl;

    for (int i=0; i<n; i++) {
      if (a[i] > b[i]) {
        int diff = a[i] - b[i];
        for (int j=i+1; diff > 0 && j<n; j++)
          while (a[j] < b[j] && diff >0) {
            a[j]++;
            diff--;
            cout << i+1 << " " << j+1 << endl;
          }
      }
      else if (a[i] < b[i]) {
        int diff = b[i] - a[i];
        for (int j=i+1; diff > 0 && j<n; j++)
          while (a[j] > b[j] && diff >0) {
            a[j]--;
            diff--;
            cout << j+1 << " " << i+1 << endl;
          }
      }
    }
  }
  return 0;
}

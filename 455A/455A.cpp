#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::max;

int main(void) {
  int N;
  cin >> N;
  vector<long long int> seq(100001, 0);
  vector<long long int> res(100001, 0);

  int num;
  for (int i=0; i<N; i++) {
    cin >> num;
    seq[num]++;
  }

  res[1] = seq[1];
  for (int i=2, size=res.size(); i<size; i++)
    res[i] = max(seq[i]*i + res[i-2], res[i-1]);
  cout << res.back() << endl;

  return 0;
}

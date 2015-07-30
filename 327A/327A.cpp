#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  int n;
  cin >> n;
  vector<int> seq(n);
  vector<int> cum(n);
  
  cin >> seq[0];
  cum[0] = seq[0];
  
  for (int i=1; i<n; i++){
    cin >> seq[i];
    cum[i] = cum[i-1] + seq[i];
  }
  
  int mx = 0;
  for (int i=0; i<n; i++) {
    int k = ( i ? cum[i-1] : 0);
    for (int j=i; j<n; j++){
      int rest = cum[n-1] - cum[j] + k;
      int flipped = (j-i+1) - (cum[j] - k);
      if (rest + flipped > mx)
  	mx = rest + flipped;
    }
  }

  cout << mx << endl;
  return 0;
}

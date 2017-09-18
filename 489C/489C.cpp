#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::pow;
using std::string;

bool max(int, int, string&, int);
bool min(int, int, string&, int);

int main(void) {
  int m, s;
  cin >> m >> s;

  string mx;
  if (!max(m, s, mx, m>1)) {
    cout << "-1 -1" << endl;
    return 0;
  }

  string mn;
  min(m, s, mn, m>1);
  cout << mn << " " << mx << endl;
  return 0;
}

bool max(int m, int s, string& st, int j) {
  if (m == 0)
    return s ? false: true;

  if (s > 9 * m)
    return false;
  
  bool mx = false;
  for (int i=9; !mx && i>=j; i--)
    if (s-i >= 0) {
      mx = max(m-1, s-i, st, 0);
      if (mx)
	st =  static_cast<char> ('0' + i) + st;
    }

  return mx;
}

bool min(int m, int s, string& st, int j) {
  if (m == 0)
    return s ? false : true;
  
  if (s > 9 * m)
    return false;
  
  bool mn = false;
  for (int i=j; !mn && i<10 && s-i >= 0; i++) {
    mn = min(m-1, s-i, st, 0);
    if (mn)
      st = static_cast<char>('0' + i) + st;
  }

  return mn;
}

#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;

class info {
public:
  info () {}
  info (int c, int s, int e) :
    count(c), start(s), end(e){}
  int count;
  int start;
  int end;
};

int main(void) {
  int n;
  cin >> n;
  map<int, info> mem;
  int max_count = 1;
  for (int cnt=1; cnt<=n; cnt++) {
    int num;
    cin >> num;
    if (mem.find(num) == mem.end()) {
      info i(1, cnt, cnt);
      mem[num] = i;
    }
    else {
      info & i = mem[num];
      i.count++;
      if (i.count > max_count)
	max_count = i.count;
      i.end = cnt;
    }
  }

  int start,end;
  bool first = true;
  for (auto itr = mem.begin(), end_itr = mem.end(); itr != end_itr; itr++) {
    if ((itr->second).count == max_count) {
      if (first) {
	start = (itr->second).start;
	end = (itr->second).end;
	first = false;
      }
      else if ( (itr->second).end - (itr->second).start < end - start) {
	start = (itr->second).start;
	end = (itr->second).end;
      }
    }
  }
  cout << start << " " << end << endl;
  return 0;
}

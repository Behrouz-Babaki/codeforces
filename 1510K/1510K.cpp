#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void swap1(vector<int> &numbers);
void swap2(vector<int> &numbers);
void print_vec(const vector<int> &numbers);

int main(void)
{
  size_t n;
  cin >> n;

  vector<int> numbers(2 * n);
  vector<int> target(2 * n);
  for (int i = 0; i < 2 * n; i++)
  {
    cin >> numbers[i];
    target[i] = i + 1;
  }

  if (numbers == target)
  {
    cout << 0 << endl;
    exit(0);
  }

  vector<int> initial(numbers);

  int count = 0;
  bool is_initial = false, is_target = false;
  while (!is_target && !is_initial)
    for (auto f : {swap1, swap2})
    {
      f(numbers);
      count++;
      is_initial = (numbers == initial);
      is_target = (numbers == target);
      if (is_target || is_initial)
        break;
    }

  int min = is_target ? count : -1;
  numbers = initial;
  count = 0;
  is_initial = false;
  is_target = false;
  while (!is_target && !is_initial)
    for (auto f : {swap2, swap1})
    {
      f(numbers);
      count++;
      is_initial = (numbers == initial);
      is_target = (numbers == target);
      if (is_initial || is_target)
        break;
    }

  if (is_target)
    if (min < 0)
      min = count;
    else
      min = min < count ? min : count;

  cout << min << endl;
  return 0;
}


void swap1(vector<int> &numbers)
{
  for (int i = 0, s = numbers.size(); i < s; i += 2)
  {
    int temp = numbers[i];
    numbers[i] = numbers[i + 1];
    numbers[i + 1] = temp;
  }
}

void swap2(vector<int> &numbers)
{
  for (int i = 0, s = numbers.size() / 2; i < s; i++)
  {
    int temp = numbers[i];
    numbers[i] = numbers[i + s];
    numbers[i + s] = temp;
  }
}

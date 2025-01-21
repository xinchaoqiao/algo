#include <iostream>
#include <vector>
using namespace std;
int solution(int m, int n, std::vector<std::vector<int>> p) {
  // Edit your code here
  int sum = 0;
  int cmax = m > n ? m : n;
  vector<int> v(cmax+1, 0);

  for (auto fir : p) {
    v[fir[0]] = fir[1];
  }
  for (int i = 1; i < m; i++) {
    if (v[i] > v[i - 1] || v[i] == 0) {
      v[i] = v[i - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    sum += v[i];
  }
  // cout << sum << endl;
  return sum;
}

int main() {
  // Add your test cases here
  std::cout << (solution(5, 4, {{0, 2}, {1, 3}, {2, 1}, {3, 2}}) == 7);
  return 0;
}

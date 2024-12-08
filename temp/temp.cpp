#include <iostream>
const int N = 3e3 + 10;
using namespace std;
<<<<<<< HEAD
int n, m;
int arr[N];
int main() {
  cin >> n >> m;
  for (int i = 0;i < n;i++) {
    cin >> arr[i];
  }
  int max = arr[1] + arr[2] + arr[0], count = 0;
  for (int i = m - 1;i < n;i++) {
    count = 0;
    int tm = m - 1;
    while (tm >= 0) {
      count += arr[tm--];
    }
    if (max > count) max = count;

  }
  cout << max << endl;
  return 0;
=======

int main(void) {
    string n;
    getline(cin, n);
    //stod()注意 函数只能转换整数 如果有字符串，无法运行
    cout << stod(n) << endl;

    return 0;
>>>>>>> 355c1d1 (rebase)
}
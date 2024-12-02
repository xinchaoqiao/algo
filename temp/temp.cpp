#include <iostream>
#include <vector>
using namespace std;
int n;
int a, b;
int main() {
    cin >> n;
    int unhappy = 0;
    vector<int> v;
    while (n--) {
        scanf("%d %d", &a, &b);
        unhappy += a + b - 8;
        v.push_back(unhappy);
    }
    int sum = 0;
    for (auto vv : v) {
        sum += vv;
    }
    cout << sum << endl;
    return 0;
}
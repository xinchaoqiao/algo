#include <iostream>
#include <algorithm>
const int N = 3e3 + 10;
using namespace std;
int n, m;
int a[N],h[N];
int main(void) {
    cin >> n >> m;
    for (int i = 0;i < n;i++) scanf("%d", &a[i]);
    for (int i = 0;i <= n - m;i++) {
        for (int k = i;k < i + m;k++) {
            h[i] += a[k];
        }
    }
    sort(h, h + n - m);
    cout << h[0] << endl;
    return 0;
}
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], s[N];
int n, m;
int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i])
        s[i] = s[i - 1] + a[i];
    }
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}
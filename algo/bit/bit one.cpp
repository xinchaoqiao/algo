#include <bits/stdc++.h>
using namespace std;
int n;
int lowbit(int x) {
    return x & -x;//返回数字二进制的最后一个1
}
int main(void) {
    scanf("%d", &n);
    while (n--) {
        int x;
        cin >> x;
        int res = 0;
        while (x) x -= lowbit(x), res++;
        cout << res << endl;
    }
    return 0;
}
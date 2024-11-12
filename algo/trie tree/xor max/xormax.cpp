#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 3e6;//M 三百万行
int n;
int son[M][2], idx;
int a[N];
void insert(int x) {
    int p = 0;
    for (int i = 30;~i;i--) {
        int& s = son[p][x >> i & 1];//获取最后一位是0 是1 获取最后一位
        if (!s) s = ++idx;
        p = s;
    }
}

int query(int x) {
    int res = 0, p = 0;
    for (int i = 30;~i;i--) {
        int s = x >> i & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}
int main(void) {

    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0;i < n;i++)
        res = max(res, query(a[i]));
    printf("%d\n", res);
    return 0;
}
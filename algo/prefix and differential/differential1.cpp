#include <iostream>
using namespace std;
const int N = 100010;
int n, m;
int a[N], b[N];
void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}
int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i += ) {
        cin >> a[i];
        insert(i, i, a[i]);//给a[i]赋值的同时使差分数组加上c
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for (int i = 1; i <= n;i++)
        a[i] = a[i - 1] + b[i];
        printf("%d", a[i]);
        return 0;
}
//b[i]相当于a[i] 的 原数组   每次b[i] 都相当于减去前一位 然后加上a[i] 获得a[n]  ;

 //一般地，我们认为原序列就是差分序列的前缀和，所以把差分看做前缀和的逆运算

//差分作用
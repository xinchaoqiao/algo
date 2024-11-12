#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
int stk[N], tt;
int main(void) {
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        //如果stk[tt] 大于等于 x  则删除栈顶元素
        while (tt && stk[tt] >= x) tt--;
        if (tt) cout << stk[tt] << " ";
        else cout << -1 << " ";//tt 不存在 说明没有比x小的了
        stk[++tt] = x;
    }
    return 0;
}
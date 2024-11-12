#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k;
int q[N], a[N];
int main(void) {
    scanf("%d%d", &n, &k);
    for (int i = 0;i < n;i++)scanf("%d", &a[i]);

    int hh = 0, tt = -1;
    for (int i = 0;i < n;i++) {
        //是否能增加新元素
        if (hh <= tt && q[hh] < i - k + 1)hh++;
        //能的话保证单调
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    cout << endl;
    tt = -1, hh = 0;
    for (int i = 0;i < n;i++) {
        if (hh <= tt && q[hh] < i - k + 1)hh++;//滑框右移
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;    
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    return 0;
}
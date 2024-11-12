#include <iostream>
using namespace std;
typedef unsigned long long ULL;
//假设Rp足够好
const int N = 100010, P = 131; //P 表示 P进制,P = 131 or 13331经验值
int n, m;
char str[N];
ULL h[N], p[N];
ULL get_hash(int l, int r) {//计算字符串中随机一段的哈希值
    return h[r] - h[l-1] * p[r - l + 1];//高位对齐;
}
int main() {
    scanf("%d%d%s", &n, &m,str + 1);
    p[0] = 1;
    for (int i = 1;i <= n;i++) {
        p[i] = p[i - 1] * P; //储存p次幂
        h[i] = h[i - 1] * P + str[i];//每一子字符串的哈希值
    }

    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get_hash(l1, r1) == get_hash(l2, r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}
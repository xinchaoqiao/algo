//开放寻址法
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200003, null = 0x3f3f3f3f;//最大值
int h[N];
int find(int x) {
    int k = (x % N + N) % N;//使余数始终是正的
    
    while (h[k] != null && h[k] != x) {//h[k]不是空的  且不等于查询的数
        k++;
        if (k == N) k = 0;//如果k遍历到最后那么从0开始循环
    }
    return k;//k两层含义:1.如果h[k] == x k为查询数的位置 2.h[k] != x 或者找到空位置 k 不进入while 找到空位置 直接赋值
}
int main() {
    int n;
    scanf("%d", &n);
    memset(h, 0x3f3f3f3f, sizeof h);
    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if (*op == 'I') h[k] = x;
        else {
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
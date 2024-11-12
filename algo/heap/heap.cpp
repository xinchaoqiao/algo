#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int h[N],_size;
int n, m;
void down(int u) {
    int t = u;//t表示每次的最小值
    if (u * 2 <= _size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= _size && h[u * 2 + 1 ] < h[t]) t = u * 2 + 1;
    if (u != t) {
        swap(h[u], h[t]);
        down(t);//从t节点开始向后排序
    }
}
int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) scanf("%d", &h[i]);
    _size = n;
    for (int i = n / 2;i;i--) down(i);//每次都是倒数第二层 最后一层可以不用遍历 倒数第二层已经遍历的 最后一层 这里的复杂度为 O(n);

    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[_size--];
        down(1); // 从 1 节点开始向后排序
    }
    return 0;
}
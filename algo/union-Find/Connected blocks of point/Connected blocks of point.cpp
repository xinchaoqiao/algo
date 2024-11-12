#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int p[N], _size[N];//_size维护连通块的节点数量  根节点有意义就行  size只看根节点的  其他节点的size没有意义 表示的是连通块的节点数量
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) {
        p[i] = i;
        _size[i] = 1;
    }
    char op[5];
    int a, b;
    while (m--) {
        scanf("%s", op);
        //连通集合
        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue;
            _size[find(b)] += _size[find(a)];//这两行顺序不能变 一定要先把根节点的数量相加 再 把a连接到b;
            p[find(a)] = find(b);
        }
        else if (op[1] == '1') {
            scanf("%d%d",&a,&b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else {
            scanf("%d", &a);
            printf("%d\n", _size[find(a)]);
        }
    }
    return 0;
}

//树是边数最少的连通图
//树就是特殊的图
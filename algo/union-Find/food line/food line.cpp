#include <iostream>
using namespace std;
const int N = 50010;
int n, m;
int p[N], d[N];//路径压缩 + 带权
int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];//当前节点到 根节点距离
        p[x] = t; //带权并查集 路径压缩
    }
    return p[x];
}
int main(void) {
    //不管是否为同类还是异类，都把他放在同一集合中 ，即：只要知道了两个动物的关系就把他们放在集合里面去。这样，就可以间接得出各动物之间的关系
    //核心：如何确定每个点之间的关系？=》如何确定每个点与根节点之间的关系?
    //通过到根节点模上3的距离来判断：1表示可以吃根节点，2表示被根节点吃，3表示与根节点是同类
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++) p[i] = i;
    int res = 0;
    while (m--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (x > n || y > n) res++;
        else {
            int px = find(x), py = find(y);
            if (t == 1) {//告诉我们是同类
                if (px == py && (d[x] - d[y]) % 3 ) res++;//判断告诉的同类是真假  是 距离根节点 的距离相同 相减 == 0  res++ 不执行 否则 执行 
                else if (px != py) {//是同类但是不在一棵树  放到一棵树上
                    p[px] = py;
                    d[px] = d[y] - d[x];// (d[x] + ? ) == d[y];
                }
            }
            else {
                if (px == py && (d[x] - d[y] - 1) % 3) res++; // x 吃 y d[x] - d[y] == 1; 
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];//(d[x] + ? - d[y]) % 3 == 1;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0; 
}
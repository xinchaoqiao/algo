#include <iostream>
using namespace std;
const int N = 10;
int n;
bool row[N], col[N], dg[2 * N], udg[2 * N];
char g[N][N];
void dfs(int x, int y, int s) {
    if (s > n) return;
    if (y == n) {
        y = 0;
        x++;
    }

    if (x == n) {
        if (s == n) {
            for (int i = 0;i < n;i++) puts(g[i]);
            puts("");
        }
        return;
    }
    //尝试放置皇后
    dfs(x, y + 1, s);

    if (!row[x] && !col[y] && !dg[y - x] && !udg[y - x + n]) { // 副对角线 y = -x + b ->    b = y + x
        g[x][y] = 'Q';
        row[x] = col[y] = dg[y - x] = udg[y + x + n] = true;
        //
        dfs(x, y + 1, s + 1);//进行下一个皇后的放置
        g[x][y] = '.';
        row[x] = col[y] = dg[y - x] = udg[y + x + n] = false;
    }
}

/*
当尝试在当前位置放置皇后后，
如果满足条件（即行、列和对角线都没有皇后），
则递归调用dfs函数尝试在下一位置放置皇后。
*/
int main(void) {
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) g[i][j] = '.';
    dfs(0, 0, 0);
        return 0;
}
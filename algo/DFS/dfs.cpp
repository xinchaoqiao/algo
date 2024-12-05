#include <iostream>
using namespace std;
const int N = 10;
int n;
int path[N];
bool st[N];
// 深搜 暴搜
void dfs(int u) {
    if (u == n) {
        for (int i = 0;i < n;i++) printf("%d ", path[i]);
        puts("");
        return;
    }

    for (int i = 1;i <= n;i++) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            //path[u] = 0;  回溯，将数字i从当前排列中移除。
            st[i] = false;//重塑 取消标记，数字i可以再次被使用。
        }
    }
}
int main(void) {
    scanf("%d", &n);
    dfs(0);
    return 0;
}
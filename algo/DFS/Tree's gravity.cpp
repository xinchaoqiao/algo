#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
    树的重心 : 最大连通块中的最小的那个node 就是 重心
*/
const int N = 1e5 + 10;
const int M = 2 * N;
int n, ans = N;
bool st[N];
int h[N], ne[M], e[M], idx;
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u) {
    st[u] = true;
    int res = 0;
    int sum = 1;//res max point
    for (int i = h[u];i != -1;i = ne[i]) {
        int value = e[i];
        if (!st[value]) {
            int s = dfs(value);
            res = max(res, s);//find the max point region
            sum += s;
        }
    }
    
    res = max(res, n-sum);
    ans = min(res, ans);
    return sum;
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    
    return 0;
}
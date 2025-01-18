#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1000010, M = N * 2;
bool st[N];
int h[N], ne[M], e[M], idx;
// 深搜 暴搜
//add index
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void def(int u) {
    st[u] = true;//this node is searched
    for (int i = 0;i != -1;i = ne[i]) {
        int value = e[i];
        if (!st[u]) dfs(value);//not search go on

    }
}
int main() {
    memset(h,-1,sizeof h);//in cstring
    dfs(1);
    return 0;
}
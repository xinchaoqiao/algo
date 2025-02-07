#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
const int N = 1e5 + 10;
vector<int> g[N];
int d[N];
int visited[N];
int bfs(int start) {
    queue<int> q;
    q.push(start);
    memset(d, -1, sizeof d);
    d[start] = 0;
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto neighbor : g[cur]) {
            if (visited[neighbor] == 0) {
                visited[neighbor] = 1;
                d[neighbor] = d[cur] + 1;
                q.push(neighbor);
            }
        }
    }
    return d[n];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    cout << bfs(1) << endl;
    return 0;
}
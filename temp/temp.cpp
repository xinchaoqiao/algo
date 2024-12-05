#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
const int N = 11;
bool st[N];
int path[N];
int n;
void dfs(int u) {
    if (u == n) {
        for (int i = 0;i < n;i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1;i <= n;i++) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
int main() {

    cin >> n;
    dfs(0);
    return 0;
}
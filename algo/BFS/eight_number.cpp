#include <bits/stdc++.h>
using namespace std;
int bfs(string start) {
    string end = "12345678x";
    queue<string> q;
    unordered_map<string,int> d;

    q.push(start);
    d[start] = 0;
    int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int distance = d[t];
        if (t == end) return distance; // 最短原因，首先符合条件的一定最短，返回

        // 状态转移
        int k = t.find('x');
        int x = k / 3, y = k % 3;// 一维映射二维 
        for (int i = 0;i < 4;i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]);//二维映射一维
                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[k], t[a * 3 + b]);//恢复状态
            }
        }
    }
    return -1;
}
int main(void) {
    string start;
    for (int i = 0;i < 9;i++) {
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    return 0;
}
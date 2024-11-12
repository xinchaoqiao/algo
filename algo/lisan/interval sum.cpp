#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef pair<int, int> PII;
const int N = 300010;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}
int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0;i < n;i++) {
        int x, c;
        scanf("%d %d", &x, &c);
        add.push_back({ x,c });
        alls.push_back(x);
    }

    for (int i = 0;i < m;i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        query.push_back({ l,r });
        alls.push_back(l);
        alls.push_back(r);
    }

    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    //插入
    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    //预处理前缀和
    for (int i = 1;i <= alls.size();i++)s[i] = s[i - 1] + a[i];

    //处理询问
    for (auto item : query) {
        int l = find(item.first), r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}
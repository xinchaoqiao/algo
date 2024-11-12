#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n;
vector<PII> segs;
void merge(vector<PII>& segs) {
    vector<PII> res;
    int st = -2e9, ed = -2e9;
    sort(segs.begin(), segs.end());
    for (auto seg : segs) {
        if (ed < seg.first) {
            //区间没有重叠,添加上一段区间
            if (st != -2e9) res.push_back({ st,ed });
            st = seg.first, ed = seg.second;
        }
        //区间重叠,更新右边的区间 继续循环判断区间重叠.
        else ed = max(ed, seg.second);
    }
    //处理最后一段区间
    if (st != -2e9) res.push_back({ st,ed });
    segs = res;
}
int main(void) {
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        segs.push_back({ l,r });
    }

    merge(segs);
    cout << segs.size() << endl;
    return 0;
}
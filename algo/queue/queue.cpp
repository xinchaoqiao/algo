#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int hh, tt, q[N];
int m;
void init() {
    tt = -1;
}
void push(int x) {
    q[++tt] = x;
}
void pop() {
    hh++;
}
bool empty() {
    return !(hh <= tt);
}
int query() {
    return q[hh];
}
int main(void) {
    init();
    scanf("%d", &m);
    while (m--) {
        string str;
        cin >> str;
        if (str == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (str == "empty") {
            if (empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if (str == "pop") {
            pop();
        }
        else cout << query() << endl;
    }
    return 0;
}
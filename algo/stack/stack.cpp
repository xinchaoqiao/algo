#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int stk[N], tt;
void push(int x) {
    stk[++tt] = x;
}
void pop() {
    tt--;
}
void empty() {
    if (tt) cout << "NO" << endl;
    else cout << "YES" << endl;
}
int query() {
    return stk[tt];
}

int main(void) {
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (s == "pop") pop();
        else if (s == "empty") empty();
        else cout << query() << endl;
    }

    return 0;
}
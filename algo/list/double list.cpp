#include <iostream>
using namespace std;
const int N = 100010;
int m, l[N], r[N], e[N], idx;

void init() {
    //0 表示左端点  1 表示右端点
    r[0] = 1;
    l[1] = 0;
    // 0 1 已经被占用 idx 只能从 2开始
    idx = 2;
}
// 在下标k右边插入一个数    右边: l[k],x    
void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx++;
}

//删除第k个点
void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main(void) {
    init();
    cin >> m;
    
    while (m--) {
        string op;
        cin >> op;
        if (op == "L") {
            int x;
            cin >> x;
            add(0, x);
        }
        else if (op == "R") {
            int x;
            cin >> x;
            add(l[1], x);
        }
        else if (op == "D") {
            int k;
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL") {
            int k, x;
            cin >> k >> x;
            add(l[k+1], x);
        }
        else {//IR  
            int k, x;
            cin >> k >> x;
            add(k+1, x);
        }
    }
    for (int i = r[0];i != 1;i = r[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}
#include <iostream>
using namespace std;
const int N = 100010;
int head, e[N], ne[N], idx;
int m;
void init() {
    //head下一位为空 直接赋值为-1
    head = -1;
    //当前操作的下标
    idx = 0;
}
//添加到头节点的位置  添加到头节点  头节点是移动的 不是不动的
void add_to_head(int x) {
    e[idx] = x;
    //下一位是空
    ne[idx] = head;
    //
    head = idx++;
}
//将x插入到下标是k的后边
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}
//将下标k的点后一个点移除
void remove(int k) {
    ne[k] = ne[ne[k]];
}
int main(void) {
    init();
    cin >> m;
    while (m--) {
        char op;
        
        cin >> op;//读入操作符
        if (op == 'H') {
            int x;
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'I') {
            int k, x;
            cin >> k >> x;
            add(k - 1, x);
        }
        else  {
            int k;
            cin >> k;
            if (!k) head = ne[head];
            remove(k - 1);
        }
    }

    //遍历单链表
    for (int i = head; i != -1;i = ne[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int son[N][26], cnt[N], idx;//son[i][j] 表示节点 i 的第 j 个子节点  idx(节点索引) 是一个全局索引，用于分配新的节点。 cnt 是一个数组，用于存储每个节点的字符串计数。
char str[N];

void insert(char str[]) {
    //初始化根节点p   //p 是当前节点的索引，初始为根节点（索引为0）。
    int p = 0;
    for (int i = 0;str[i];i++) {//一个循环代表一个字符串
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;//如果当前节点 p 没有子节点 u，则分配一个新的节点，并更新 son[p][u]。
        p = son[p][u];
    }
    cnt[p]++;//每次插入都会使p的节点增多一个  
   
}
int query(char str[]) {
    int p = 0;
    for (int i = 0;str[i];i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}
int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}
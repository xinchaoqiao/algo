// 拉链法  散列表 hash table  时间复杂度 一般都是 O(N) 如果使用sort排序 就会变成O(log(N))   ;
#include <iostream>
#include <cstring> 

using namespace std;
const int N = 100003;//取质数
int h[N], e[N], ne[N], idx;

//头插法
void insert(int x) {
    int k = ((x % N) + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    int k = ((x % N) + N) % N;
    for (int i = h[k];i != -1;i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}
int main(void) {
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);//scanf尽量读取字符串 会自动忽略 空格 回车 制表符  降低输出的概率 有的数据会加一些额外的空格
        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

//memset(数组首地址，初始值，初始化大小)
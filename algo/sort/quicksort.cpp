// 不稳定
#include <iostream>
#include <ctime>
using namespace std;
int n;
//数的最大上限
const int N 1e6 + 10;
int q[N];
void quick_sort(int q[], int l, int r) {
    //边界判断
    if (l >= r) {
        return;
    }
    //定义基准数,i 和 j 因为每次先移动一位 所以要在边界外
    int rand_idx = rand() % (r - l + 1) + l;//对整个区间取余
    swap(q[l], q[rand_idx]);
    int x = q[l], i = l - 1, j = r + 1;
    //两层循环 找到之后再次寻找 直到不满足条件
    
    while (i < j) {
        do i++;while (q[i] < x);//找到x左边大于等于x的数
        do j--;while (q[j] > x);//找到x右边小于等于x的数
        if (i < j) swap(q[i], q[j]);
    }
    //分治思想
    quick_sort(q, l, j);//j和i是相同的 
    quick_sort(q, j + 1, r);//写i的话 j+1 变 i-1

    /*
    //do while 多操作一次 用j需要+1 用i需要-1 i上- j下+
    quick_sort(q, l, i-1);//j和i是相同的
    quick_sort(q, i, r);//写i的话 j+1 变 i-1
     */

}
int main(void) {
    srand(time(nullptr));
    //读取n 个数
    scanf("%d", &n);
    for (int i = 0; i < n;i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n;i++) printf("%d", q[i]);

    return 0;
}
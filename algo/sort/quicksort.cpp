// 不稳定
#include <iostream>
#include <ctime>
using namespace std;
int n;
//数的最大上限
const int N = 1e6 + 10;
int q[N];
void quick_sort(int q[], int l, int r) {
    //边界判断
    if (l >= r) {//当左边界大于等于右边界时，说明当前区间只有一个元素或为空，不需要排序，直接返回。
        return;
    }
    int rand_idx = rand() % (r - l + 1) + l;//随机选择一个索引的值作为基准数 增加性能
    swap(q[l], q[rand_idx]);
    //快排核心
    int x = q[l], i = l - 1, j = r + 1;//i 和 j 分别初始化为区间左右边界的外侧，因为后续使用 do-while 循环会先移动一次指针。
    while (i < j) {
        do i++;while (q[i] < x);//从左向右移动指针 i，直到找到一个大于等于基准数 x 的元素。
        do j--;while (q[j] > x);//从右向左移动指针 j，直到找到一个小于等于基准数 x 的元素。
        if (i < j) swap(q[i], q[j]);
    }
    //分治思想
    quick_sort(q, l, j);//j和i是相同的 
    quick_sort(q, j + 1, r);//写i的话 j+1 变 i-1

    /*
        循环结束时，会有 i >= j。实际上，最终 i 和 j 指针会交错或者重合，并且满足以下性质：
        所有小于等于基准数 x 的元素都在 j 及其左边。
        所有大于等于基准数 x 的元素都在 i 及其右边。
    */
}
int main(void) {
    ios::sync_with_stdio(false);//解除同步流
    cout.tie(0), cin.tie(0);
    srand(time(nullptr));
    //读取n 个数
    cin >> n;
    for (int i = 0; i < n;i++) cin >> q[i];

    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n;i++) cout << q[i];

    return 0;
}
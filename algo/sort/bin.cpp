//两个模板 二分左边界和右边界
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int q[N];
int main(void) {

    int x;
    scanf("%d", &n,&x);
    int l = 0, r = n - 1;
    //左边界
    while (l < r) {
        int mid = l + r >> 1;
        if (q[mid] >= x) r = mid;
        else l = mid + 1;
    }


    //右边界
    while (l < r) {
        int mid = l + r >> 1;
        if (q[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return 0;
}
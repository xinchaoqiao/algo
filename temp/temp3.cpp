#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    //c++数据自然溢出 最大的溢出成为最小的 可以用来判断类型
    ll x = 2147483648;
    int y = x;
    printf("%lld\n", x);
    printf("%d", y);
    return 0;
}
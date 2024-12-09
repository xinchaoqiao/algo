#include <iostream>
using namespace std;
typedef long long ll;
/*
    快速计算   x^y
*/
ll ksm(ll x, ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
int main(void) {
    cout << ksm(2, 3) << endl;
    return 0;
}
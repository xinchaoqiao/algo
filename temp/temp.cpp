#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ksm(ll x,ll y) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}

int main(void) {
    int x, n;
    cin >> x >> n;
    cout << ksm(x + 1, n) << endl;
    return 0;
}
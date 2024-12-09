#include <iostream>
using namespace std;
typedef long long ll;
/*
    快速计算 (a ^ k) % p 

*/
ll ksm(ll a, ll k, ll p) {
    ll res = 1;
    while (k) {
        if (k & 1) res *= a % p;
        a *= a % p;
        k >>= 1;
    }
    return res;
}
int main(void) {
    cout << ksm(3, 2, 5) << endl;
    return 0;
}
#include <iostream>
using namespace std;
typedef long long ll;
/*
    快速幂(欧拉降幂)
    快速计算 (a ^ k) % p 不能写成*=  因为要先 * 然后 %

*/
ll ksm(ll a, ll k, ll p) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
int main(void) {
    int n;
    
    cin >> n;
    while (n--) {
        int a, k, q;
        scanf("%d%d%d", &a, &k, &q);
        cout << ksm(a, k, q) << endl;
    }
    
    return 0;
}
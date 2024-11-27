#include <iostream>
using namespace std;
typedef long long ll;
int main(void) {
    ll x1, x2, y1, y2;
    int i1, i2, i3, i4;
    scanf("%lld %lld %lld %lld", &x1, &x2, &y1, &y2);
    i1 = x1, i2 = x2, i3 = y1, i4 = y2;
    if (x1 * y1 != i1 * i3 || x1 * y2 != i1 * i4 || x2 * y1 != i2 * i3 || x2 * y2 != i2 * i4) {
        printf("long long int");
    }
    else printf("int");
    return 0;
}
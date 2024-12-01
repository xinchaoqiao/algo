#include <iostream>
#include <algorithm>
using namespace std;
int a1, a2, b1, b2;
char spc;
int main(void) {
    scanf("%d", &a1);
    spc = getchar();
    scanf("%d", &a2);


    scanf("%d", &b1);
    spc = getchar();
    scanf("%d", &b2);

    int c1 = a1 * b1;
    int c2 = a2 * b2;

    printf("%d %d", c2 / __gcd(c1, c2), c1 / __gcd(c1, c2));

        return 0;
}
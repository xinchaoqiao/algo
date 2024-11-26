#include <iostream>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    bool flag = false;
    int sum = 0, putin = 0;
    int i = 0;
    while (sum != n) {
        scanf("%d", &putin);
        if (!flag) {
            for (i ;i < putin;i++) {
                printf("%d", 0);
                if (i % n == 0) puts("");
            }
        }
        else {
            for (i;i < putin;i++) {
                printf("%d", 1);
                if (i % n == 0) puts("");
            }
        }
        sum += putin;
    }

    return 0;
}
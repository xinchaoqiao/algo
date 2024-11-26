#include <iostream>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    bool flag = false;
    int sum = 0, putin = 0;
    int pn = 1;
    while (true) {
        scanf("%d", &putin);
        sum += putin;
        if (!flag) {
            for (int i = 0;i < putin;i++,pn++) {
                printf("%d", 0);
                if (pn % n == 0) printf("\n");
            }
            flag = !flag;
        }
        else {
            for (int i = 0;i < putin;i++,pn++) {
                printf("%d", 1);
                if (pn % n == 0) printf("\n");
            }
            flag = !flag;
        }
        if (sum == n * n) break;
    }

    return 0;
}
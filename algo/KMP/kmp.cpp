#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
char s[M], p[N];
int ne[N];
int m, n;
int main(void) {
    cin >> n >> p + 1 >> m >> s + 1;
    //next 
    for (int i = 2, j = 0;i <= n;i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1])j++;
        ne[i] = j;
    }
    //KMP匹配过程
    for (int i = 1, j = 0;i <= m;i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    return 0;
}
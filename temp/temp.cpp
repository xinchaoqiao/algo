#include <iostream>
using namespace std;

int n, m;

int main(void) {
    cin >> n >> m;
    int s1 = 0, s2 = 0;
    s2 = ((m + 1) * (n + 1) * n * m) / 4;
    for (;m >= 0 && n >= 0;m--, n--) {
        s1 += m * n;
    }
    cout << s1 << " " << s2-s1 << endl;
    return 0;
}
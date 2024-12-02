#include <iostream>
using namespace std;

int n, m;

int main(void) {
    cin >> n >> m;
    int s1 = 0, s2 = 0;
    s2 = ((m + 1) * (n + 1) * n * m) / 4;//所有长方形个数  包括正方形
    for (;m >= 0 && n >= 0;m--, n--) {
        s1 += m * n;
    }//累加正方形

    //正方形 边长为1 m*n 边长为2 (m-1) * (n -1) 边长为 m-(m-1) * n-(n-1) == 1
    cout << s1 << " " << s2 - s1 << endl;
    return 0;
}
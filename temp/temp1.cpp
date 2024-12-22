#include <bits/stdc++.h>
using namespace std;
int main() {
    int x = 3;
    auto lam = [&x]() {
        x++;
        cout << x << endl;
        };
    lam();
    return 0;
}
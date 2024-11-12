#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> div(vector<int>& A, int b, int& r) {
    r = 0;
    vector<int> C;
    for (int i = 0;i < A.size();i++) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;   
}
int main(void) {
    string a;
    int b, r;
    cin >> a >> b;
    vector<int> A;
    for (int i = 0;i < a.length();i++) A.push_back(a[i] - '0');
    auto C = div(A, b, r);
    for (int i = C.size() - 1;i >= 0;i--) printf("%d", C[i]);
    cout << endl << r << endl;
    return 0;
}
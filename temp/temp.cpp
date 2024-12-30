#include <iostream>
#include <string>
using namespace std;

int solution(int a, int b) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    string sb = to_string(b);
    string sa = to_string(a);
    string s_max = sa + sb;
    for (int i = 0;i <= sa.length();i++) {
        string cur = sa.substr(0, i) + sb + sa.substr(i);
        if (s_max < cur) {
            s_max = cur;
        }
    }
    cout << s_max << endl;
    return stoi(s_max);
}

int main() {
    cout << (solution(76543, 4) == 765443) << endl;
    cout << (solution(1, 0) == 10) << endl;
    cout << (solution(44, 5) == 544) << endl;
    cout << (solution(666, 6) == 6666) << endl;
    cout << (solution(17, 1) == 171) << endl;
    return 0;
}
#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(const string& s) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    string tm(s.size(), ' ');
    transform(s.begin(),s.end(),tm.begin(),::tolower);
    cout << tm << endl;
    return 0;
}

int main() {
    cout << (solution("AUBTMKAxfuu") == 1) << endl;
    return 0;
}
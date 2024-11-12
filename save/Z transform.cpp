#include <iostream>
#include <vector>
#include "Utils.h"
#include <algorithm>
using namespace std;
int main(void) {
    string s = "papa";
    int numRows = 2;
    vector<string> v(2);
    int i = 0, flag = -1;
    for (auto c : s) {
        v[i].push_back(c);//新点
        if (i == 0 || i == numRows - 1) flag = -flag;//N字形变换核心
        i += flag;//核心
    }
    string rel = "";
    for (auto row : v) {
        rel += row;
    }
    cout << rel << endl;
    return 0;
}
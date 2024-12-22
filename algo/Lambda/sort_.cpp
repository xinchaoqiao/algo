/*
    sort()函数 lambda函数使用

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void func() {
    vector<int> nums = { 1,4,2,3,5 };
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
        });

    for (auto num : nums) {
        cout << num << endl;
    }
}

int main() {
    func();
    return 0;
}
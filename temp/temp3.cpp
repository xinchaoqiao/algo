#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
    vector<int> nums = { 15,12,15 };

    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    auto it = unique(nums.begin(), nums.end());
    nums.erase(it, nums.end());
    for (int i = 0;i < nums.size();i++) {
        cout << nums[i] << endl;
    }
    return 0;
}
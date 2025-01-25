#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, std::vector<int> A) {
    // Edit your code here
    int rel = 0;
    //滑动窗口
    deque<pair<int, int>> slide;
    for (int k = 1;k <= n;k++)
        for (int i = 0;i < n;i++) {
            // 单调
            while (!slide.empty() && slide.front().second >= A[i]) {
                slide.pop_back();
            }
            // 添加元素
            slide.emplace_back(i, A[i]);
            // 窗口
            while (slide.front().first <= i - k) {
                slide.pop_front();
            }
            //窗口完全形成
            if (i >= k - 1) {
                rel = max(k * slide.front().second, rel);
            }
        }
    cout << rel << endl;
    return rel;
}

int main() {
    // Add your test cases here
    std::vector<int> A_case1 = std::vector<int>{ 1, 2, 3, 4, 5 };
    std::cout << (solution(5, A_case1) == 9) << std::endl;
    return 0;
}

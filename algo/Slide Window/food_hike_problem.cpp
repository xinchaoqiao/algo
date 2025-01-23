/*
    滑动窗口 —— 单调队列

*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int solution(int n, int k, std::vector<int> data) {
    // Edit your code here
    deque<pair<int, int>> mins;// 双端队列 插入 index 和 value
    int rel = 0;
    for(int i = 0;i < n;i++){
        // 队列不为空 且 队尾元素大于当前元素时 移除队尾元素
        while(!mins.empty() && mins.back().second > data[i]){
            mins.pop_back();
        }
        //添加当前元素的值和索引
        mins.emplace_back(i,data[i]);//比push_back()快;

        //检查队头索引范围
        while(mins.front().first <= i - k ){
            mins.pop_front();
        }
        rel+=mins.front().second;
    }
    cout << rel << endl;
    return rel;
}

int main() {
    // Add your test cases here

    std::cout << (solution(5, 2, {1, 2, 3, 3, 2}) == 9) << std::endl;
    return 0;
}

/*
    滑动窗口 —— 单调队列

*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int solution(int n, int k, std::vector<int> data) {
    deque<pair<int, int>> mins;// 双端队列 插入 index 和 value
    int rel = 0;
    for(int i = 0;i < n;i++){
        // 是否单调
        while(!mins.empty() && mins.back().second > data[i]){
            mins.pop_back();
        }
        //添加元素
        mins.emplace_back(i,data[i]);//比push_back()快;

        //是否在窗口内
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

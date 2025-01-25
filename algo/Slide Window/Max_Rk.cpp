#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, std::vector<int> A) {
  // Edit your code here
  
  int rel = -1;
  for (int k = 1; k <= n; k++){
    deque<pair<int, int>> mins;
    for (int i = 0; i < n; i++) {
        // 是否单调
        while(!mins.empty() && mins.back().second > A[i]){
            mins.pop_back();
        }
        //添加元素
        mins.emplace_back(i,A[i]);//比push_back()快;

        //是否在窗口内
        while(mins.front().first <= i - k ){
            mins.pop_front();
        }
        //计算当前窗口面积
        if(i >= k-1){
            rel = max(rel,k*mins.front().second);
        }
    }
  }
  return rel;
}

int main() {
  // Add your test cases here
  std::vector<int> A_case1 = std::vector<int>{1, 2, 3, 4, 5};
  std::cout << (solution(5, A_case1) == 9) << std::endl;
  return 0;
}

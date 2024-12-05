#include <iostream>
#include <vector>
using namespace std;
// index 表示层数 cursum 表示当前组合的和
int dfs(const vector<string> numberString, int index, int cursum) {
    if (index == numberString.size()) {
        if (cursum % 2 == 0) return 1;
        return 0;
    }
    int count = 0;
    for (auto dig : numberString[index]) {
        count += dfs(numberString, index + 1, cursum + dig - '0');
    }
    return count;
}
int solution(vector<int> numbers) {
    vector<string> numberString;
    for (auto num : numbers) {
        numberString.push_back(to_string(num));
    }
    return dfs(numberString, 0, 0);
}
int main(void) {

    // You can add more test cases here
  std::cout << (solution({123, 456, 789}) == 14) << std::endl;
  std::cout << (solution({123456789}) == 4) << std::endl;
  std::cout << (solution({14329, 7568}) == 10) << std::endl;
  return 0;
}
// dfs 暴搜 
/*
    依赖于 for循环
for遍历第一组数据的每个值 判断条件返回count 循环内count相加
递归遍历 第二组每个值 判断条件返回count 循环内count相加
递归遍历 第三组每个值 判断条件返回count 循环内count相加
*/
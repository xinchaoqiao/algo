#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// 实现 solution 函数，用于计算结果并格式化为保留两位小数的字符串
std::string solution(int n, int x, const std::vector<int>& a) {
    // 断言 n 是否等于向量 a 的长度

    int sum_val = 0;
    // 计算向量 a 中所有元素的和
    for (int num : a) {
        sum_val += num;
    }
    // 计算结果
    double result = static_cast<double>(sum_val) / 4 / x;
    cout << result << endl;
    // 创建输出字符串流对象
    std::ostringstream oss;
    // 设置输出格式为固定点表示法
    oss << std::fixed;
    // 设置小数位数为两位
    oss << std::setprecision(2);
    // 将结果写入字符串流
    oss << result;
    // 将字符串流中的内容转换为字符串并返回
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // 测试用例 1
    std::cout << (solution(4, 1, {2, 3, 4, 5}) == "3.50") << std::endl;
    // 测试用例 2
    cout << (solution(10, 4, {7,1,7,16,3,16,6,5,4,3,5,1,2,11,17,7}) == "6.94") << endl;
    cout << (solution(12, 4, {10,16,4,7,7,3,8,1,5,13,10,6}) == "5.62") << endl;
    return 0;
}
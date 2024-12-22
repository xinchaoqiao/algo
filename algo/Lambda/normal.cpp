/*
    Lambda表达式如何接受参数
    Lambda 前边有类型 ：临时局部函数定义
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x = 3;
    auto mul = [x](int y) {
        return x * y;
        };
    cout << mul(3) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
stack<int> num;
stack<char> op;
void eval() {
    auto b = num.top();num.pop();
    auto a = num.top();num.pop();
    auto c = op.top();op.pop();
    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}
int main(void) {
    //优先级 数越大优先级越大
    unordered_map<char, int> pr{{'+', 1}, { '-',1 }, { '*',2 }, { '/',2 }};
    
    //遍历每个字符
    string str;
    cin >> str;
    for (int i = 0;i < str.size();i++) {
        auto c = str[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            i = j - 1;
            num.push(x);
        }
        else if (c == '(') op.push(c);
        else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        }
        //普通运算符 + - * / 
        else {
            //如果栈顶运算符(上一个运算符)的优先级大于等于 当前符号的优先级 使后两个数字和最后一个符号运算
            while (op.size() && pr[op.top()] >= pr[c]) eval();
            op.push(c);
        }
    }
    //处理剩余运算符
    while (op.size()) eval();
    cout << num.top() << endl;
    return 0;
}

//表达式求值步骤
/*
1.定义优先级
2.遍历每个字符
3.考虑数字,运算符
4.eval后两个数处理
5.处理剩余运算符
*/
class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int n = s.length();
        int i = 0, flag = 1;
        //跳过前导空格
        while (i < n && s[i] == ' ')i++;
        if (i == n) return 0;
        //判断符号
        if (s[i] == '-') {
            flag = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        //跳过前导0
        while (i < n && s[i] == '0') i++;
        if (i == n) return 0;
        //读取数字
        for (;i < n;i++) {
            char ch = s[i];
            if (ch < '0' || ch > '9')break;
            num = num * 10 + (ch - '0');//转换为整数
            //判断溢出必须每个循环都要判断一次
            long long rel = num * flag;
            if (rel > INT_MAX) return INT_MAX;
            if (rel < INT_MIN) return INT_MIN;
        }
        return num * flag;
    }
};
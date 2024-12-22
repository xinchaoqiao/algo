# 字符串格式化拼接

```c++
/*
    sprintf(char*,const char*...)可变参数 不能使用string 需要使用c风格字符串 用c_str()转换
    char 类型可以自动转换为 string 类型
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    char tmp[20];
    string rel;
    string s1 = "121", s2 = "222";
    sprintf(tmp, "%s,%s", s1.c_str(), s2.c_str());
    rel = tmp;
    cout << rel << endl;
    return 0;
}
```

/*
sprintf(char*,const char*...)可变参数 不能使用string 需要使用c风格字符串 用c_str()转换
char 类型可以自动转换为 string 类型
*/

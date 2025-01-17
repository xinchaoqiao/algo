```c++
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str = "Hello, World!";
    std::string result(str.size(), ' '); // 创建一个与原字符串大小相同的结果字符串
    // 使用 transform 算法将字符串中的字符转换为小写，并存储在 result 中
    std::transform(str.begin(), str.end(), result.begin(), [](unsigned char c) {
        return std::tolower(c);  // 这里可以使用::tolower
    });
    // 输出转换后的字符串
    std::cout << result << std::endl;
    return 0;
}
```

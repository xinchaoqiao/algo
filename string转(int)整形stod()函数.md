# 函数stod()

```c++
#include <iostream>
using namespace std;

int main(void) {
    string n;
    getline(cin, n);
    //stod()注意 函数只能转换整数 如果有字符串，无法运行
    cout << stod(n) << endl;

    return 0;
}
```


### 1. 函数头文件

在使用`stod`函数之前，需要包含`<string>`头文件，因为该函数是定义在`<string>`头文件所关联的标准库命名空间中的，代码示例如下：

收起

cpp

复制

```cpp
#include <string>
```

### 2. 函数原型及基本参数说明

`stod`函数的原型如下：

收起

cpp

复制

```cpp
double stod( const std::string& str, std::size_t* idx = 0 );
```

* **第一个参数 `str`**：这是一个常量引用，指向要被转换为双精度浮点数的字符串。这个字符串需要符合浮点数的表示格式，比如包含整数部分、小数点以及小数部分（可选）等，同时还可以包含表示正负的符号等，例如 `"3.14"`、`"-2.5"` 这样的字符串都是合法的输入。
* **第二个参数 `idx`（可选）**：它是一个指向 `std::size_t` 类型的指针，通常用于获取转换结束后在原字符串中的位置索引。如果不需要获取这个索引信息，可以将其省略（传入默认值 `0`）；如果传入了有效的指针，函数执行完后，该指针指向的变量会被赋值为字符串中第一个未参与转换的字符的索引位置。

### 3. 函数返回值

`stod`函数返回转换后的双精度浮点数（`double`类型）结果。

例如，如果输入字符串 `"123.45"`，调用`stod`函数就会返回对应的双精度浮点数 `123.45`。



#### 示例二（获取转换结束后的索引）

```cpp
#include <iostream>
#include <string>

int main() {
    std::string numStr = "  12.56abc";  // 字符串前面有空格，后面还有其他非数字字符
    std::size_t idx;
    double num = std::stod(numStr, &idx);
    std::cout << "转换后的浮点数为: " << num << std::endl;
    std::cout << "转换结束后的索引位置为: " << idx << std::endl;
    return 0;
}
```

在这个例子中，由于传入了 `&idx` 来获取索引信息，运行结果会显示类似如下内容（假设 ASCII 编码环境）：


```plaintext
转换后的浮点数为: 12.56
转换结束后的索引位置为: 5
```

这是因为前面的空格会被自动跳过，然后转换到数字部分结束（到字符 `'a'` 之前），此时对应的索引就是 `5`（从 `0` 开始计数）。

### 5. 异常处理

当输入的字符串不符合浮点数格式要求时，`stod`函数会抛出 `std::invalid_argument` 异常；如果转换过程中发生溢出等错误情况，会抛出 `std::out_of_range` 异常。

# C++ `std::function` 用法笔记(可以看作函数指针)

## 一、概述

`std::function` 是 C++ 标准库 `<functional>` 头文件中的一个通用多态函数包装器，它可以存储、复制和调用任何可调用对象，如普通函数、成员函数、函数指针、lambda 表达式等，极大地增强了代码的灵活性和可复用性。

## 二、基本语法

```
 #include <functional>
 
 // 语法形式，T 为返回类型，Args 为参数类型列表
 std::function<T(Args...)> func;
```

** 例如，定义一个接受两个 **`int` 类型参数并返回 `int` 类型结果的 `std::function` 对象：

```
 std::function<int(int, int)> func;
```

## 三、存储不同类型的可调用对象

### 1. 存储普通函数

```
 #include <iostream>
 #include <functional>
 
 // 普通函数
 int add(int a, int b) {
     return a + b;
 }
 
 int main() {
     std::function<int(int, int)> func = add;
     int result = func(3, 5);
     std::cout << "Result of add: " << result << std::endl;
     return 0;
 }
```

**解释**：将普通函数 `add` 赋值给 `std::function` 对象 `func`，之后可以像调用普通函数一样调用 `func`。

### 2. 存储 lambda 表达式

```
 #include <iostream>
 #include <functional>
 
 int main() {
     auto multiply = [](int a, int b) {
         return a * b;
     };
     std::function<int(int, int)> func = multiply;
     int result = func(4, 6);
     std::cout << "Result of multiply: " << result << std::endl;
     return 0;
 }
```

**解释**：定义一个 lambda 表达式 `multiply`，并将其赋值给 `std::function` 对象 `func`，然后调用 `func` 执行 lambda 表达式的逻辑。

### 3. 存储成员函数

```
 #include <iostream>
 #include <functional>
 
 class Calculator {
 public:
     int subtract(int a, int b) {
         return a - b;
     }
 };
 
 int main() {
     Calculator calc;
     std::function<int(Calculator*, int, int)> func = &Calculator::subtract;
     int result = func(&calc, 8, 3);
     std::cout << "Result of subtract: " << result << std::endl;
     return 0;
 }
```

**解释**：对于成员函数，需要使用对象指针作为第一个参数。这里将 `Calculator` 类的成员函数 `subtract` 赋值给 `std::function` 对象 `func`，调用时传入对象指针 `&calc` 以及其他参数。

## 四、作为函数参数和返回值

### 1. 作为函数参数

```
 #include <iostream>
 #include <functional>
 
 int operate(int a, int b, std::function<int(int, int)> func) {
     return func(a, b);
 }
 
 int main() {
     auto divide = [](int a, int b) {
         return a / b;
     };
     int result = operate(10, 2, divide);
     std::cout << "Result of divide: " << result << std::endl;
     return 0;
 }
```

**解释**：`operate` 函数接受一个 `std::function` 对象作为参数，这样可以传入不同的可调用对象实现不同的操作。

### 2. 作为函数返回值

```
 #include <iostream>
 #include <functional>
 
 std::function<int(int, int)> getAdder() {
     return [](int a, int b) {
         return a + b;
     };
 }
 
 int main() {
     std::function<int(int, int)> adder = getAdder();
     int result = adder(3, 7);
     std::cout << "Result of adder: " << result << std::endl;
     return 0;
 }
```

**解释**：`getAdder` 函数返回一个 `std::function` 对象，该对象存储了一个 lambda 表达式，用于实现加法操作。

## 五、检查是否为空

```
 #include <iostream>
 #include <functional>
 
 int main() {
     std::function<int(int, int)> func;
     if (func.empty()) {
         std::cout << "Function is empty." << std::endl;
     }
     if (!func) {
         std::cout << "Function is also considered empty." << std::endl;
     }
     return 0;
 }
```

**解释**：可以使用 `empty()` 成员函数或布尔转换来检查 `std::function` 对象是否为空。

## 六、注意事项

* **性能开销**：`std::function` 是一个类型擦除的包装器，使用它会有一定的性能开销，尤其是在频繁调用的场景下，需要权衡使用。
* **类型匹配**：存储的可调用对象的签名必须与 `std::function` 模板参数指定的签名一致，否则会导致编译错误。

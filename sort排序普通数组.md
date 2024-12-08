# sort排序普通函数

```c++
    sort(h, h + n - m);
```

sort(__first,__end); 原理:利用指针

给一个区间 左闭右开

从0开始排序 升序

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[5];
    for (int i = 0;i < 5;i++) cin >> a[i];
    sort(a, a + 5);
    for (int i = 0;i < 5;i++) {
        cout << a[i] << endl;
    }
    return 0;
}
```

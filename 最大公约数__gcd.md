# __gec()函数

algorithm 库的函数

求两个数的最大公约数 用于化简

```c++
#include <iostream>
#include <algorithm>
using namespace std;
int a1, a2, b1, b2;
char spc;
int main(void) {
    scanf("%d", &a1);
    spc = getchar();
    scanf("%d", &a2);


    scanf("%d", &b1);
    spc = getchar();
    scanf("%d", &b2);

    int c1 = a1 * b1;
    int c2 = a2 * b2;

    printf("%d %d", c2 / __gcd(c1, c2), c1 / __gcd(c1, c2));

    return 0;
}
```

## __gcd函数

```c++
  template<typename _EuclideanRingElement>
    _EuclideanRingElement
    __gcd(_EuclideanRingElement __m, _EuclideanRingElement __n)
    {
      while (__n != 0)
	{
	  _EuclideanRingElement __t = __m % __n;
	  __m = __n;
	  __n = __t;
	}
      return __m;
    }
```

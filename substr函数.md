# substr()函数

`substr(len)`从pos位置截取到字符串结尾

`substr(offset,len)` 从0 截取到 pos 位置 【0，pos）前包后不包

如果截取某一段的字符串

`substr(i,pos-i)`eg: 111111.11 i = 2 pos = 5，2,3则 答案：1111.1

string find（） 函数 如果没找到  将会=string::npos

如果不等于string::npos 字符串里边包含字符

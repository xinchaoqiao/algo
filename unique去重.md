# unique 去重

需要先排序，使相同的元素相邻 然后再进行去重

```c++
sort(nums.begin(),nums.end());
auto it = unique(nums.begin(),nums.end()); // 返回去重后 最后一个元素的下一个位置
nums.erase(it,nums.end());
```

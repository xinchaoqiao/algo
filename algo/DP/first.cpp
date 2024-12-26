/*链接：
https://www.marscode.cn/practice/8eld5702wn8297?problem_id=7424418560666877996
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int solution(int n, int H, int A, vector<int> h, vector<int> a) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    unordered_map<int, int> dp;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (H > h[i] && A > a[i]) {
            dp[i] = 1;//给每个能打过的怪物初始化
            for (int j = 0; j < i; j++) {//检查与之前怪物的关系
                if (h[j] < h[i] && a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);//dp[i]是之前能打过怪物的总和
                }
            }
            cnt = max(dp[i], cnt);
        }
    }
    return cnt;
}

int main() {
    cout << (solution(3, 4, 5, { 1, 2, 3 }, { 3, 2, 1 }) == 1) << endl;
    cout << (solution(5, 10, 10, { 6, 9, 12, 4, 7 }, { 8, 9, 10, 2, 5 }) == 2)
        << endl;
    cout << (solution(4, 20, 25, { 10, 15, 18, 22 }, { 12, 18, 20, 26 }) == 3)
        << endl;
    return 0;
}
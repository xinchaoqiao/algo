#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int H, int A, vector<int> h, vector<int> a) {
    // 创建一个结构体来存储怪物的血量和攻击力
    struct Monster {
        int health;
        int attack;
        bool operator<(const Monster& other) const {
            return health < other.health && attack < other.attack;
        }
    };

    // 将怪物信息存储到结构体数组中
    vector<Monster> monsters(n);
    for (int i = 0; i < n; ++i) {
        monsters[i] = {h[i], a[i]};
    }

    // 按照血量和攻击力排序
    sort(monsters.begin(), monsters.end(), [](const Monster& m1, const Monster& m2) {
        if (m1.health == m2.health) return m1.attack < m2.attack;
        return m1.health < m2.health;
    });

    // 动态规划数组，dp[i]表示以第i个怪物结尾的最长递增子序列的长度
    vector<int> dp(n, 1);
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (monsters[i] < monsters[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    cout << max_len << endl;
    return max_len;
}

int main() {
    cout << (solution(3, 4, 5, { 1, 2, 3 }, { 3, 2, 1 }) == 1) << endl;
    cout << (solution(5, 10, 10, { 6, 9, 12, 4, 7 }, { 8, 9, 10, 2, 5 }) == 2) << endl;
    cout << (solution(4, 20, 25, { 10, 15, 18, 22 }, { 12, 18, 20, 26 }) == 3) << endl;
    cout << (solution(13, 17, 14, {2,3,12,13,7,8,5,15,1,12,17,14,4}, { 13,13,8,15,2,5,7,8,13,7,6,8,1}) == 4) << endl;
    return 0;
}
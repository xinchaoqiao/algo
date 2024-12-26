#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(const int n, const int H, const int A, vector<int> h, vector<int> a) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    struct Monster {
        int health;
        int attack;


        bool operator<(const Monster& other)const {
            return health < other.health && attack < other.attack;
        }
    };
    // 存储每个怪物信息
    vector<Monster> monster(n);
    for (int i = 0;i < n;i++) {
        monster[i] = { h[i],a[i] };
    }

    sort(monster.begin(), monster.end(), [](const Monster& m1, const Monster& m2) {
        if (m1.health == m2.health) return m1.attack < m2.attack;
        return m1.health < m2.health;
        });
    for (int i = 0;i < n;i++) {
        cout << "i = " << i << ' ' << monster[i].health << ' ' << monster[i].attack << endl;
    }
    int rel = 0;
    for (int i = 0;i < n;i++) {
        if (monster[i].health >= H || monster[i].attack >= A) continue;
        if (monster[i].health < H && monster[i].attack < A) {
            rel++;
        }
    }
    return rel;
}

int main() {
    cout << (solution(3, 4, 5, { 1, 2, 3 }, { 3, 2, 1 }) == 1) << endl;
    cout << (solution(5, 10, 10, { 6, 9, 12, 4, 7 }, { 8, 9, 10, 2, 5 }) == 2) << endl;
    cout << (solution(4, 20, 25, { 10, 15, 18, 22 }, { 12, 18, 20, 26 }) == 3) << endl;
    cout << (solution(13, 17, 14, { 2,3,12,13,7,8,5,15,1,12,17,14,4 }, { 13,13,8,15,2,5,7,8,13,7,6,8,1 }) == 4) << endl;
    return 0;
}
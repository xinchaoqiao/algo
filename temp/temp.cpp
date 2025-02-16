#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


long solution(const std::string& s, const std::vector<int>& a, int m, int k) {
    // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
    // write code here
    vector<pair<char, int>> v;
    for (int i = 0;i < a.size();i++) {
        v.push_back({ s[i],a[i] });
    }
    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
        });
    int sum = 0, cnt = 0, total = 0;
    for (int i = 0;i < a.size();i++) {
        if (total == k) {
            return sum;
        }


        if (v[i].first == '0') {
            sum += v[i].second;
            total++;
        }
        else {
            if (cnt == m) {
                continue;
            }
            cnt++;
            total++;
            sum += v[i].second;
        }

    }
    if (total != k)
        return -1;
}

int main() {
    std::cout << (solution("001", { 10, 20, 30 }, 1, 2) == 30) << std::endl;
    std::cout << (solution("111", { 10, 20, 30 }, 1, 2) == -1) << std::endl;
    std::cout << (solution("0101", { 5, 15, 10, 20 }, 2, 3) == 30) << std::endl;
    return 0;
}
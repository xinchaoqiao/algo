#include <iostream>
#include <vector>
using namespace std;
int solution(int m, int n, std::vector<std::vector<int>> p) {
    // Edit your code here
    int sum = 0;
    vector<int> v(m, 0);
    for (int i = 0;i < m;i++) {
        
        cout << p[i][0] << endl;
    }
    return sum;
}

int main() {
    // Add your test cases here
    std::cout << (solution(5, 4, {{0, 2}, {1, 3}, {2, 1}, {3, 2}}) == 7);
    return 0;
}

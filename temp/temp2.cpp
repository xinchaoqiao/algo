#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    int rel = *max_element(v.begin(), v.end());
    cout << rel << endl;
    return 0;
}
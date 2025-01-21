#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
    map<string, map<string, int>> my_map = {
        {"王力宏",{{"语文",88},{"数学",99}}},
        {"周杰伦",{{"语文",77},{"数学",22}} }
    };
    for (auto mm : my_map) {
        cout << "姓名：" << mm.first << endl;
        for (auto m : mm.second) {
            cout << m.first <<"： " << m.second << endl;
        }
    }
    return 0;
}
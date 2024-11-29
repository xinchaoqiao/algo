#include <iostream>
#include <string>

using namespace std;

std::string solution(const std::string& s) {
    // write code here
    int i = 0;
    while (s[i] == '0') {
        if (s[i + 1] == '.')
            break;
        i++;
    }
    auto pos = s.find('.');
    string before, behind;
    if (pos != string::npos) {
        before = s.substr(i, pos - i);
        behind = s.substr(pos);
    }
    else {
        before = s.substr(i);
    }

    string rel;
    int count = 0;
    for (int j = before.size() - 1;j >= 0;j--) {
        rel = before[j] + rel;
        count++;
        if (count % 3 == 0 && j != 0) {
            rel = ',' + rel;
        }
    }
    rel += behind;
    return rel;
}

int main() {
    cout << (solution("1294512.12412") == "1,294,512.12412") << endl;
    return 0;
}
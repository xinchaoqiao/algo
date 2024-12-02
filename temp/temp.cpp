#include <iostream>
#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;


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
const double de = 0.98;
double s, x;
int main() {
    scanf("%lf %lf", &s, &x);
    double fs = 7;
    double disfish = 0;
    bool flag = false;
    while (true) {
        disfish += fs;
        if (disfish >= s + x && !flag) {
            cout << 'n' << endl;
            return 0;
        }
        //判断这一秒结束是否在范围内
        if (disfish >= s - x && disfish <= s + x) {
            flag = true;
        }

        //如果在范围内 判断下一秒能否游出去 不能返回y
        if (disfish+fs*de >= s - x && disfish+fs*de <= s + x && flag) {
            cout << 'y' << endl;
            return 0;
        } // 能游出去 返回n
        else {
            cout << 'n' << endl;
            return 0;
        }
        fs *= de;
    }
    return 0;
}

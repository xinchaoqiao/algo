#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<string> q;
    string start = "1213";
    string end = "121";
    q.push(start);
    q.push(end);
    cout << q.size() << endl;
    while (q.size()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
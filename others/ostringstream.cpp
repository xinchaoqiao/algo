#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    double relsult = 5.625;
    ostringstream oss;
    oss << fixed;
    oss << setprecision(2);
    oss << relsult;
    cout << oss.str() << endl;
    return 0;
}
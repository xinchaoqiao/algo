#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int count = 0;
	bool flag = false;
	for (int i = 0;i < sizeof str;i++) {
		if (str[i] == '0' && flag == false) count++;
		else {
			cout << count << " ";
			count = 0;
			flag = !flag;
		}

		if (str[i] == '1' && flag == true) count++;
		else {
			cout << count << " ";
			count = 0;
			flag = !flag;
		}

	}
	return 0;
}
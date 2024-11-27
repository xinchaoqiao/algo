#include <iostream>
#include <string.h>
using namespace std;
const int N = 210;
char rel[N * N], str[N];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	strcat(rel, str);
	for (int i = 1;i < n;i++) {
		scanf("%s", str);
		strcat(rel, str);
	}
	printf("%d ", n);
	if (rel[0] == '1') printf("%d ", 0);
	int count = 0;
	for (int i = 0;i < strlen(rel) - 1;i++) {
		if (rel[i] == rel[i + 1]) count++;
		else {
			printf("%d ", count + 1);
			count = 0;
		}
	}
	printf("%d", ++count);
	return 0;
}
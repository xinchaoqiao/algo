#include <iostream>
using namespace std;
const int N = 10010;
int arr[N];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0;i < n;i++) scanf("%d", &arr[i]);
    int count = 1, max = 1;
    for (int i = 0; i <= n - 1;i++) {
        if (arr[i] + 1 == arr[i + 1]) {
            if (i == n - 1)count++;
            count++;
        }
        else {
            if (max < count) max = count;
            count = 1;
        }
    }
    printf("%d", max);
    return 0;
}
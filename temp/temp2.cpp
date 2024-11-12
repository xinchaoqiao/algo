#include <stdio.h>
#include <string.h>
void MaxLength(char arr[100]) {
    int cnt[100] = {0};
    int start = cnt[0], end = 0;
    int max = 0;
    int n = strlen(arr);
    for (int i = 0, j = 1;i < n;i++) {
        if (arr[i] == ' ') cnt[j++] = i;//空格的下标
        if (arr[i] == NULL) cnt[j++] = n;
    }
    int count = 0;
    for (int i = 0, times = 0;i < n;i++) {
        if (arr[i] != ' ' ) count++;
        if (max < count) {
            max = count;
            start = end;
            end = cnt[++times];
            count = 0;
        }
    }
    for (int i = 0;i < end - start - 1;i++) {
        puts(&arr[i]);
    }
}
int main() {
    char arr[100];
    gets(arr);
    MaxLength(arr);
    return 0;
}
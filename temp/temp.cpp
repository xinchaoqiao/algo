#include <stdio.h>
#include <string.h>

void MaxLength(char *str) {
    int start = 0, end = 0, maxLen = 0, len = 0;
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            len++;
            if (len > maxLen) {
                maxLen = len;
                start = end;
            }
        } else {
            len = 0;
            end = i + 1;
        }
    }

    for (int i = start; i < start + maxLen; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[100];
    //fgets(str, sizeof(str), stdin); // 读取字符串
    gets(str);
    MaxLength(str);
    return 0;
}

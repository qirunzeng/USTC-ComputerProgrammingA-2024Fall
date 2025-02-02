#include <stdio.h>
#include <string.h>
#define StrLen 11

void udf_getString(char[], int strlength);
int udf_strlen(char s[]);
void udf_sort(char s[][StrLen], int strNum);
void udf_print(char s[][StrLen], int strNum);

int main(void) {
    int strNum;
    scanf("%d", &strNum);
    getchar(); // 吸收换行符
    char s[strNum][StrLen];
    for (int i = 0; i < strNum; i++) {
        udf_getString(s[i], StrLen);
    }
    udf_sort(s, strNum);
    udf_print(s, strNum);
    return 0;
}

void udf_getString(char string[], int strlength) {
    char temp;
    int j = 0;
    for (int i = 0; i < strlength; i++) {
        string[i] = '\0';
    }
    while ((temp = getchar()) != '\n' && j < strlength - 1) { // 检查j防止越界
        string[j++] = temp;
    }
    string[j] = '\0'; // 确保字符串以\0结尾
}

int udf_strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

void udf_sort(char s[][StrLen], int strNum) {
    int i, j, k;
    char temp[StrLen];
    for (i = 0; i < strNum - 1; i++) {
        k = i;
        for (j = i + 1; j < strNum; j++) {
            if (udf_strlen(s[k]) > udf_strlen(s[j]) ||
                (udf_strlen(s[k]) == udf_strlen(s[j]) && strcmp(s[k], s[j]) > 0)) {
                k = j;
            }
        }
        if (k != i) {
            for (j = 0; j < StrLen; j++) {
                temp[j] = s[i][j];
                s[i][j] = s[k][j];
                s[k][j] = temp[j];
            }
        }
    }
}

void udf_print(char s[][StrLen], int strNum) {
    for (int i = 0; i < strNum; i++) {
        printf("%s\n", s[i]); // 直接使用%s打印字符串
    }
}

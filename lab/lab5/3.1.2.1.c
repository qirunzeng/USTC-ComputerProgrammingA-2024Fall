#include <stdio.h>

unsigned long sums(const int digit, const int level) {
    // unsigned long sum = 0, item = (unsigned long)digit;
    // for (int i = 0; i < level; ++i) {
    //     sum += item;
    //     item = item * 10 + digit;
    // }
    unsigned long sum = 0;
    for (int i = 1; i <= level; ++i) {
        sum = sum * 10 + digit * i;
    }
    return sum;
}

int main() {
    int digit, level;
    unsigned long ssum = 0;
    printf("请输入项数和基数：");
    scanf("%d %d", &digit, &level);
    ssum = sums(digit, level);
    printf("结果：%lu\n", ssum);
    return 0;
}
#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("Error Input...\n");
        return 0;
    }
    int c, d;
    if (a > b) {
        c = a;
        d = b;
    } else {
        c = b;
        d = a;
    }
    int g = gcd(c, d);
    a /= g;
    b /= g;
    printf("%d / %d 为最简分数\n", a, b);
    return 0;
}
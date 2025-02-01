#include <stdio.h>

int is_perfect_number(const int n, int *factors) {
    int s = 0;
    int cnt = 0;
    for (int i = 1; (i<<1) <= n; ++i) {
        if (n % i == 0) {
            s += i;
            factors[cnt++] = i;
        }
    }
    return s == n ? cnt : 0;
}

int main() {
    int n;
    int factors[32767];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int len = is_perfect_number(i, factors);
        if (len > 0) {
            printf("%d ", i);
            for (int j = 0; j < len; ++j) {
                printf("%d ", factors[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
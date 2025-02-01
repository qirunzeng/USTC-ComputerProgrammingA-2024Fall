#include <stdio.h>

struct complex {
    double real;
    double imag;
};

struct complex complexMul(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

struct complex complexAdd(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

struct complex complexSub(struct complex a, struct complex b) {
    struct complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

struct complex complexDiv(struct complex a, struct complex b) {
    struct complex c;
    c.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    c.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
    return c;
}

int main() {
    int choice;
    struct complex a, b, c;
    printf("输入第一个复数的实部和虚部：");
    scanf("%lf %lf", &a.real, &a.imag);
    printf("输入第二个复数的实部和虚部：");
    scanf("%lf %lf", &b.real, &b.imag);
    printf("请选择操作（1: 加法，2: 减法，3: 乘法，4: 除法）：");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            c = complexAdd(a, b);
            printf("结果为：%.2lf + %.2lfi\n", c.real, c.imag);
            break;
        case 2:
            c = complexSub(a, b);
            printf("结果为：%.2lf + %.2lfi\n", c.real, c.imag);
            break;
        case 3:
            c = complexMul(a, b);
            printf("结果为：%.2lf + %.2lfi\n", c.real, c.imag);
            break;
        case 4:
            c = complexDiv(a, b);
            printf("结果为：%.2lf + %.2lfi\n", c.real, c.imag);
            break;
        default:
            printf("无效选择\n");
    }
    return 0;
}
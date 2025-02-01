#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_LEN 114514  // 数组最大长度

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define POW2(x) ((x) * (x))
#define ABS(x) ((x) > 0 ? (x) : -(x))

// 全局变量
int array[MAX_LEN];  // 数组
int length = 0;      // 实际使用的数组长度

// 功能函数声明
void Config() {
    printf("输入数组长度：");
    scanf("%d", &length);
    if (length > MAX_LEN) {
        printf("数组长度超过最大值，已设置为最大值 %d\n", MAX_LEN);
        length = MAX_LEN;
    }
}
void PrintArray() {
    printf("数组元素：");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void FillRandom(int min, int max) {
    for (int i = 0; i < length; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}
void FillKeyboard() {
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
}
void FillSameVal(int value) {
    for (int i = 0; i < length; i++) {
        array[i] = value;
    }
}
void FillArithSeq(int start, int diff) {
    for (int i = 0; i < length; i++) {
        array[i] = start + diff * i;
    }
}
void DeleteIndex(int index){
    if (index < 0 || index >= length) {
        printf("下标越界\n");
        return;
    }
    for (int i = index; i < length - 1; i++) {
        array[i] = array[i + 1];
    }
    length--;
}
void DeleteValue(int value) {
    int gap = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            gap++;
        } else {
            array[i - gap] = array[i];
        }
    }
    length -= gap;
}
void DeleteRange(int start, int end) {
    if (start < 0 || start >= length || end < 0 || end >= length || start > end) {
        printf("区间越界\n");
        return;
    }
    int gap = end - start + 1;
    for (int i = end + 1; i < length; i++) {
        array[i - gap] = array[i];
    }
    length -= gap;
}
void InsertIndex(int index, int value) {
    if (index < 0 || index > length) {
        printf("下标越界\n");
        return;
    }
    for (int i = length; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value;
    length++;
}
void InsertOrder(int value) {
    int i = 0;
    while (i < length && array[i] < value) {
        i++;
    }
    InsertIndex(i, value);
}
double Average() {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}
double Variance() {
    double avg = Average();
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += POW2(array[i] - avg);
    }
    return sum / length;
}
double StdDev() {
    return sqrt(Variance());
}
int SeqSearch(int value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}
int BiSearch(int value) {
    int left = 0, right = length - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == value) {
            return mid;
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int IsAsc() {
    for (int i = 1; i < length; i++) {
        if (array[i] < array[i - 1]) {
            return 0;
        }
    }
    return 1;
}
int IsDesc() {
    for (int i = 1; i < length; i++) {
        if (array[i] > array[i - 1]) {
            return 0;
        }
    }
    return 1;
}
int IsAllEqual() {
    for (int i = 1; i < length; i++) {
        if (array[i] != array[i - 1]) {
            return 0;
        }
    }
    return 1;
}
void BubbleSort() {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void SelectSort() {
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}
void InsertSort() {
    for (int i = 1; i < length; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}
void ExchangeSort() {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
void Reverse() {
    for (int i = 0; i < length / 2; i++) {
        int temp = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = temp;
    }
}
void RotateLeft(int n) {
    n %= length;
    int tmp[MAX_LEN];
    for (int i = 0; i < length; i++) {
        tmp[i] = array[(i + n) % length];
    }
    for (int i = 0; i < length; i++) {
        array[i] = tmp[i];
    }
}
void RotateRight(int n) {
    n %= length;
    int tmp[MAX_LEN];
    for (int i = 0; i < length; i++) {
        tmp[i] = array[(i - n + length) % length];
    }
    for (int i = 0; i < length; i++) {
        array[i] = tmp[i];
    }
}
int Max() {
    int max = array[0];
    for (int i = 1; i < length; i++) {
        max = MAX(max, array[i]);
    }
    return max;
}
int Min() {
    int min = array[0];
    for (int i = 1; i < length; i++) {
        min = MIN(min, array[i]);
    }
    return min;
}

int main() {
    int choice;
    srand(time(0));  // 初始化随机数生成

    while (1) {
        printf("\n请选择功能：\n");
        printf("1. 配置系统参数\n");
        printf("2. 显示数组\n");
        printf("3. 生成样本数据\n");
        printf("4. 删除\n");
        printf("5. 插入\n");
        printf("6. 统计\n");
        printf("7. 查找\n");
        printf("8. 判断\n");
        printf("9. 排列数组元素\n");
        printf("0. 退出程序\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Config();
                break;
            case 2:
                PrintArray();
                break;
            case 3:
                printf("生成样本数据（1: 随机数，2: 键盘输入，3: 填充同一值，4: 等差序列）：");
                int fillChoice, min, max, start, diff, val;
                scanf("%d", &fillChoice);
                switch (fillChoice) {
                    case 1:
                        printf("输入最小值和最大值：");
                        scanf("%d %d", &min, &max);
                        FillRandom(min, max);
                        break;
                    case 2:
                        FillKeyboard();
                        break;
                    case 3:
                        printf("输入填充值：");
                        scanf("%d", &val);
                        FillSameVal(val);
                        break;
                    case 4:
                        printf("输入起始值和差值：");
                        scanf("%d %d", &start, &diff);
                        FillArithSeq(start, diff);
                        break;
                }
                break;
            case 4:
                printf("删除操作（1: 指定下标，2: 指定值，3: 指定区间）：");
                int delChoice, index, value, end;
                scanf("%d", &delChoice);
                switch (delChoice) {
                    case 1:
                        printf("输入下标：");
                        scanf("%d", &index);
                        DeleteIndex(index);
                        break;
                    case 2:
                        printf("输入值：");
                        scanf("%d", &value);
                        DeleteValue(value);
                        break;
                    case 3:
                        printf("输入起始下标和结束下标：");
                        scanf("%d %d", &index, &end);
                        DeleteRange(index, end);
                        break;
                }
                break;
            case 5:
                printf("插入操作（1: 指定下标，2: 有序插入）：");
                int insChoice;
                scanf("%d", &insChoice);
                printf("输入值：");
                scanf("%d", &value);
                if (insChoice == 1) {
                    printf("输入下标：");
                    scanf("%d", &index);
                    InsertIndex(index, value);
                } else {
                    InsertOrder(value);
                }
                break;
            case 6:
                printf("统计（1: 最大值，2: 最小值，3: 平均值，4: 方差，5: 均方差）：");
                int statChoice;
                scanf("%d", &statChoice);
                switch (statChoice) {
                    case 1:
                        printf("最大值: %d\n", Max());
                        break;
                    case 2:
                        printf("最小值: %d\n", Min());
                        break;
                    case 3:
                        printf("平均值: %.2f\n", Average());
                        break;
                    case 4:
                        printf("方差: %.2f\n", Variance());
                        break;
                    case 5:
                        printf("均方差: %.2f\n", StdDev());
                        break;
                }
                break;
            case 7:
                printf("查找（1: 顺序查找，2: 二分查找）：");
                int searchChoice;
                scanf("%d", &searchChoice);
                printf("输入值：");
                scanf("%d", &value);
                if (searchChoice == 1) {
                    printf("顺序查找结果: %d\n", SeqSearch(value));
                } else {
                    printf("二分查找结果: %d\n", BiSearch(value));
                }
                break;
            case 8:
                printf("判断（1: 升序，2: 降序，3: 全部相等）：");
                int judgeChoice;
                scanf("%d", &judgeChoice);
                switch (judgeChoice) {
                    case 1:
                        printf("是否升序: %s\n", IsAsc() ? "是" : "否");
                        break;
                    case 2:
                        printf("是否降序: %s\n", IsDesc() ? "是" : "否");
                        break;
                    case 3:
                        printf("是否全部相等: %s\n", IsAllEqual() ? "是" : "否");
                        break;
                }
                break;
            case 9:
                printf("排列（1: 排序，2: 逆置，3: 左旋，4: 右旋）：");
                int arrangeChoice, n;
                scanf("%d", &arrangeChoice);
                switch (arrangeChoice) {
                    case 1:
                        printf("排序方式（1: 冒泡，2: 选择，3: 插入，4: 交换）：");
                        int sortChoice;
                        scanf("%d", &sortChoice);
                        switch (sortChoice) {
                            case 1: BubbleSort(); break;
                            case 2: SelectSort(); break;
                            case 3: InsertSort(); break;
                            case 4: ExchangeSort(); break;
                        }
                        break;
                    case 2:
                        Reverse();
                        break;
                    case 3:
                        printf("左旋几位：");
                        scanf("%d", &n);
                        RotateLeft(n);
                        break;
                    case 4:
                        printf("右旋几位：");
                        scanf("%d", &n);
                        RotateRight(n);
                        break;
                }
                break;
            case 0:
                return 0;
            default:
                printf("无效选择，请重新输入。\n");
        }
    }
    return 0;
}
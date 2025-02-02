# Lab7

## 顺序查找

### Background

Clint 最近在找衣服穿。他的衣服比较多，于是他给每件衣服编号。但是由于 Clint 比较随意，所以都是随意编号，但是他只需要找到第一个符合要求的衣服。

### Description

在 $n$ 个相同数据类型的元素中查找指定元素。可能是 `string(char*)`, `char`, `int` 类型。

### Format

#### Input

第一行 1 个正整数 $t$，表示数据组数 $t \in [1, 1000]$.

而后 $3t$ 行的每 $3$ 行中：

第 1 行一个正整数 $n$ 和一个字符串 $s$，表示接下来数据的长度和数据的类型。$n \in [1, 2048]$，$s \in \{\text{string}, \text{float}, \text{int}\}$。

第 2 行 $n$ 个元素，用**空格**分开。如果是字符串，只包含大小写字母，且字符串的长度小于等于 $10$ （可能包含**空字符串**）。如果是整数，在 int 范围内。如果是 float，在 float 范围内。

第 3 行 1 个元素，表示要查找的元素。（**注意：若元素类型为字符串，要查找的元素可能为空，即该行只有一个`\n`**）

前 $50\%$ 的测试点只有 int 类型。

#### Output

共 $n$ 行，对于每个点，如果找到了，输出下标 $i$（如有多个只要求输出第一个），找不到，输出  $-1$

### Samples

```input1
4
6 int
1 2 3 4 5 1
1
6 float
1.0 3.3 1.0 1.3 3.7 4.3
3.3
3 string
Clint apple Clint
Clint
4 string
  Langlang 
Langlang
```

```output1
0
1
-1
2
```

说明：对于第四个样例，字符串数组为：`["", "", "Langlang", ""]`，所以 `Langlang` 是 2

### Limitation

1.5s, 256MiB for each test case.

## 2. 数组合并排序

### Description

考察数组的合并排序

### Format

#### Input

第一行两个整数 $m, n$，分别表示第一个和第二个数组长度，用空格间隔开

第二行 $m$ 个整数，为第一个数组。

第三行 $n$ 个整数，为第二个数组。

以上 2 个数组均已按照从小到大的顺序排列好。

一共两个数据点：

第一个数据点：$n, m = 100, 0 \leq a[i] \leq 1000$

第二个数据点：$n, m = 5 \times 10^5, 0\leq a[i] \leq 10^7$

第二个数据点很大，你应该思考怎么利用两个数组均为有序数组的性质来完成，传统的排序算法，除了桶排序和基数排序，都会超时。

#### Output

一行 $m+n$ 个整数，为合并后的排序结果，按照从小到大排序。

### Samples

```input1
6 6
1 2 3 4 5 6
1 2 3 4 5 6
```

```output1
1 1 2 2 3 3 4 4 5 5 6 6
```

### Limitation

0.5s, 256MiB for each test case.

## 3. 二分法查找数据

### Description

给定N个奇数（1，3，5，...）存放在一维数组中num[N]，输入一个数字，编写函数用二分法查找该数，若有该数则将其删除后输出新的数组，没有则输出error

### Format

#### Input

输入一个整数（数组长度取N=10）

#### Output

见题干

### Samples

```input1
11
```

```output1
1 3 5 7 9 13 15 17 19 21
```

```input2
10
```

```output2
error
```

### Limitation

1s, 1024KiB for each test case.

## 4. 字符串长度排序

### Description

输入 $n$ 个字符串，请你按照字符串长度从小到大排序并输出，如果有两个字符串长度相等，那么按字典序输出（即在字典上的相对顺序）

### Format

#### Input

第一行一个数字 $n$，表示字符串的数量, $0 \leq n \leq 10^3$

而后 $n$ 行，每行一个字符串 $s_i$, $1 \leq \text{len}(s_i)\leq 10$，只有小写字母

#### Output

$n$ 个字符串

### Samples

```input1
2
pangpang
langlang
```

```output1
langlang
pangpang
```

### Limitation

1s, 256 MiB for each test case.

## 5. 几何图形操作

### Description

给定n个点的xy坐标，根据操作符对n个点坐标进行坐标变换（Translation，Scale，Rotation）

### Format

#### Input

n+3行：

第1行，一个整数n，$n\in[0,10^4]$

接下来n行，每行两个double型，中间空格隔开，表示第i个点的$(x,y)$坐标

第n+2行，一个整数op，$op\in\{1,2,3\}$，依次表示平移，缩放，旋转操作

第n+3行:

1. op=1 or 2时，两个float型数，中间空格隔开，表示x，y方向平移距离；或x，y方向缩放比例。
2. op=3 时，一个float型数angle，以**角度**为单位表示旋转角度

#### Output

n行，每行2个double型数（**保留4位小数**），分别为n个点经过操作后的坐标，中间用一个空格隔开

### Samples

#### Example 1

```input1
3
197.768188 916.080078
477.194824 251.407852
207.636581 24.723259
3
1308.758667
```

```output1
558.4617 -752.6191
-125.5386 -524.5578
-118.2903 -172.4285
```

#### Example 2

```input2
3
1 1
2 2
3 3
1
2 3
```

```output2
3.0000 4.0000
4.0000 5.0000
5.0000 6.0000
```

### Limitation

1s, 1024KiB for each test case.

### Note

1. PI取`3.141592657`，参照书上代码
2. 旋转矩阵a请用float型
3. 除了结构体内坐标使用double，其他都用float

## 6. 中缀（或后缀）表达式求值

### Format

#### Input

一行中缀（后缀）表达式，只包括以下字符：`0123456789.+-*/()`

如果是后缀表达式，保证数与数之间，数与符号之间有一个空格。

#### Output

一行，中缀（后缀）表达式的计算结果，保留四位小数

### Samples

```input1
(1+2)*3+4/5-6.0
```

```output1
3.8000
```

后缀表达式样例

```input2
1 2 + 3 * 4 5 / 6.0 - +
```

```output2
3.8000
```

### Limitation

1s, 1024KiB for each test case.

### Note

一半数据点为中缀，一半为后缀，只要通过一半即为满分


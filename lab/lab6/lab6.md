# Lab 6

## 1. 求完数

### Background

Abby recently found a very interesting number. He found that $6 = 1 + 2 + 3$ where $1, 2, 3$ are all factors of $6$, except $6$ itself. So he want to know whether there are other numbers having such quality. Please design a program to help him.

### Description

Given a number $n$. Please find out all numbers that are  prefect number within range $[1, n]$.

### Format

#### Input

One integer $n$, $1 \leq n \leq 32767$.

#### Output

n lines, where each line is in this format:

Please pay attention to the format! And don't output any other characters.

```output
number factor1 factor2 factor3 ...
```

The first number is the number, and then its factors, sorted in ascending order.

### Samples

```input1
6
```

```output1
6 1 2 3
```

```input2
100
```

```output2
6 1 2 3
28 1 2 4 7 14
```

### Limitation

5s, 1024MiB for each test case.



## 2. 整数反转

### Background

Shane 最近想锻炼逆向思维，为此他想了一个游戏，那就是把一个整数的每一位反过来，但是由于他数学不好，不知道该怎么反过来，所以求助于你，希望你能帮忙写一个程序，帮他实现反转。

### Description

对于一个整数，它的反转是除了负号的部分，每一个十进制位按照倒序输出。负号如果存在的话保持在最前面。

请你用递归实现。不用递归实现的同学将获得 0 分。

### Format

#### Input

第一行一个整数 $n$ 表示组数, $10 \leq n \leq 1000$

后面 $n$ 行每行一个整数 $a_i$, $- 10^8 \leq a_i \leq 10^8$

#### Output

$n$ 行，每行一个整数表示 $a_i$ 的反转

不要有其他任何无关输出，**包括 '\0'** (important!)

### Samples

```input1
17
756
4979
2229290
-6011357
-8148
-89
8819
-800139
-2283221
829
-640097
625235
48736
7220
-5253
79319
-4480188
```

```output1
657
9794
0929222
-7531106
-8418
-98
9188
-931008
-1223822
928
-790046
532526
63784
0227
-3525
91397
-8810844
```

### Limitation

1s, 256MiB for each test case.



## 3. 进制转换

### Background

漂亮国大选在即，候选人 Harris 为了拉取选票，颁布政策，小黑每天有1500 漂亮币的 0 元购额度。为此，商店老板绞尽脑汁来预防小黑 0 元购。有一天，商店老板意识到小黑算术不好，所以他打算将所有商品价格标为不同的进制，从而让小黑不知不觉中偷走了超过 1500 漂亮币的商品，以此达到制裁小黑的目的。但是老板小学没有毕业就出来创业了，所以需要你帮忙编写进制转换的程序。

### Description

给定一个十进制数，转换为二进制，八进制或十六进制

请使用递归完成，不使用递归的同学将获得 0 分

### Format

#### Input

第一行一个数字 `n` 表示要转换的组数

$1 \leq n \leq 10^4$

随后 `n` 行，每行 2 个数字 `num` 和 `base`，用空格间隔开，分别表示要转换的数和要转换到的进制

$-2147483648 \leq \text{num} \leq 2147483647$

$\text{base} \in \{2, 8, 16\}$

#### Output

`n` 行，每行一个数字，表示进制 `base` 下 `num` 的值。在 16 进制下，请用**小写字母** `a, b, c, d, e, f` 表示 `10, 11, 12, 13, 14, 15`

### Samples

```input1
2
10 2
10 16
```

```output1
1010
a
```

### Limitation

1s, 256 MiB for each test case.





## 4. 标识符判别

### Background

在漂亮国大选中，建国同志强势逆袭战胜哈哈姐，成为了白色宫殿的下一任主人。为此他的参谋长硅谷钢铁侠同志功不可没。为了致敬硅谷钢铁侠，建国同志准备学习编程，并且从最基础的 C 语言开始。现在他要学习如何判断一个字符是不是标识符。

### Description

给定一个字符串，请你判断这个字符串能不能作为 C
语言中的标识符（不必考虑 C 语言中原本存在的关键字，比如 int 在本题中也可以作为标识符）。

### Format

#### Input

第一行一个整数 `n` 表示数据组数 $1 \leq n \leq 10^4$

而后 `n` 行每行一个字符串 `str`，满足 $\text{len(str)} \leq 16, \text{ord(c)} \in [32, 126]$，`ord` 表示 `c` 的 ASCII 码

#### Output

若 `str` 可以作为标识符，输出 `True`

否则输出第一个出错的下标错误字符以及错误类型，如:

- 错误类型 1 表示 not letter or underline
- 错误类型 2 表示 not letter or underline or digit
- 下标 `0` 只能为字母或下划线，若不是字母或下划线，输出 `0 char 1`；
- 后续只能为数字或字母或下划线，输出 `index char 2`

### Samples

```input1
4
_
1
a*
a b
```

```output1
True
0 1 1
1 * 2
1   2
```

### Limitation

1s, 1024 MiB for each test case.



## 5. 变量作用域分析

### Background

Little test for variable lifetime.

### Description

Experiment Instruction Book P136 3.3.2-3.

### Format

#### Input

null

#### Output

Correct output of **the reference code on P137**.

### Samples

```input1

```

```output1
extern_num:90
...
```

Notice: Only the first line of the correct output is given as example, you should refer to the code on P137 and **complete all the output**.

### Limitation

1s, 1024KiB for each test case.

### Notice

1. All of the output should be in the format of:

```C
printf("<description>:%d\n",n1);
```

2. Note that there is **no space** before and after `%d`.
3. Remember to use English colon `:`.
4. 注意思考书上代码注释里的各个问题，区分不同变量的**作用域(scope)** 和 **生存期(lifetime)**。
5. 书上代码没有很好地体现函数中定义的`static`变量的作用，建议自己调整程序，验证`static`的效果。

## 5. 单词统计

### Background

Lang Lang has completed his report in the Politics Class, but he don't know whether the number of words in the report meets the expectations of the professor. So he asks for help to you. ^_^

### Description

The task is to write a function .You use the function in the main.c  to check the status and count the number of words in the input string.

### Format

#### Input

A string from the keyboard with `#` as the ending marker .

#### Output

The nummer of words in the string

### Samples

```input1
I love China !
I love USTC ! #
```

```output1
6
```

### Limitation

1s, 1024KiB for each test case.
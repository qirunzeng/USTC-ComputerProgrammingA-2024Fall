import random


for i in range(1, 5):
    with open(f'{i}.in', 'w') as f1:
        with open(f'{i}.out', 'w') as g:
            string = ""
            for j in range(100000):
                # 从 0~26 生成随机数
                a = random.randint(0, 26)
                if a == 26:
                    string += ' '
                else:
                    string += chr(a + ord('a'))
            f1.write(string)
            strs = string.split()
            # 输出 g 中最长的字符串
            g.write(max(strs[:200], key=len))
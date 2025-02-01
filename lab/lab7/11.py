from typing import List

# 从 ./case1/6.in 读取数据

def process_s(s: str) -> List[str]:
    ret = []
    l, r = 0, 0
    for c in s:
        if c == ' ':
            ret.append(s[l:r])
            l = r + 1
        else:
            r += 1
    ret.append(s[l:r])
    return ret


with open("case1/6.in", "r") as f:
    with open("case1/6_test.out", "w") as g:
        t = int(f.readline())
        for i in range(t):
            n, data_type = f.readline().split()
            s = f.readline().strip()
            arr = process_s(s)
            # if i == 2:
            #     g.write(str(arr) + "\n")
            target = f.readline().strip()
            # print("target:", target)
            print(n, len(arr))
            
            if target in arr:
                # print(arr.index(target))
                g.write(str(arr.index(target)) + "\n")
            else:
                # print(-1)
                g.write("-1\n")
            
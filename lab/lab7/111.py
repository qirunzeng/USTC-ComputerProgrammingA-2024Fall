from typing import List

def process_s(s: str) -> List[str]:
    ret = []
    string = ''
    for c in s:
        if c == ' ':
            ret.append(string)
            string = ''
        else:
            string += c
    ret.append(string)
    return ret

t = int(input())


for i in range(t):
    n, data_type = input().split()
    s = input()
    arr = process_s(s)
    target = input()
    if target in arr:
        print(arr.index(target))
    else:
        print(-1)
    
import random
ans = []
for i in range(10):
    s = ""
    for j in range(20):
        s += chr(random.randint(0, 25) + ord('a'))
    print(s)
    # 按字符顺序从 a 到 z 排序
    ans.append("".join(sorted(s)))
    
for s in ans:
    print(s)
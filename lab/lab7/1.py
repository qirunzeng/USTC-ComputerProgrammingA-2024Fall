import random
from random import randint

for i in range(1, 6):
    with open("case1/" + str(i) + ".in", "w") as f:
        with open("case1/" + str(i) + ".out", "w") as g:
            t = randint(1, 1000)
            f.write(str(t) + "\n")
            for _ in range(t):
                n = randint(1, 2048)
                f.write(str(n) + " int\n")
                arr = [randint(-2147483648, 2147483647) for _ in range(n)]
                f.write(" ".join(map(str, arr)) + "\n")
                toss = randint(1, 1000)
                target = randint(-2147483648, 2147483647) if toss > 800 else arr[randint(0, n - 1)]
                f.write(str(target) + "\n")
                # target 在 arr 中的下标，否则 -1
                if target in arr:
                    g.write(str(arr.index(target)) + "\n")
                else:
                    g.write("-1\n")
                    
                    
for i in range(6, 11):
    with open("case1/" + str(i) + ".in", "w") as f:
        with open("case1/" + str(i) + ".out", "w") as g:
            t = randint(1, 1000)
            f.write(str(t) + "\n")            
            for _ in range(t):
                n = randint(1, 2048)
                data_type = random.choice(["int", "float", "string"])
                f.write(str(n) + " " + data_type + "\n")
                if data_type == "int":
                    arr = [randint(-2147483648, 2147483647) for _ in range(n)]
                    f.write(" ".join(map(str, arr)) + "\n")
                    toss = randint(1, 1000)
                    target = randint(-2147483648, 2147483647) if toss > 800 else arr[randint(0, n - 1)]
                    f.write(str(target) + "\n")
                    # target 在 arr 中的下标，否则 -1
                    if target in arr:
                        g.write(str(arr.index(target)) + "\n")
                    else:
                        g.write("-1\n")
                elif data_type == "float": # 至多 2 位小数
                    arr = [round(random.uniform(-1e4, 1e4), 2) for _ in range(n)]
                    f.write(" ".join(map(str, arr)) + "\n")
                    toss = randint(1, 1000)
                    target = round(random.uniform(-1e4, 1e4), 2) if toss > 800 else arr[randint(0, n - 1)]
                    f.write(str(target) + "\n")
                    # target 在 arr 中的下标，否则 -1
                    if target in arr:
                        g.write(str(arr.index(target)) + "\n")
                    else:
                        g.write("-1\n")
                else:
                    arr = ["".join(random.choices("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", k=randint(0, 10))) for _ in range(n)]
                    f.write(" ".join(arr) + "\n")
                    toss = randint(1, 1000)
                    target = "".join(random.choices("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", k=randint(0, 10))) if toss > 800 else arr[randint(0, n - 1)]
                    f.write(target + "\n")
                    # target 在 arr 中的下标，否则 -1
                    if target in arr:
                        g.write(str(arr.index(target)) + "\n")
                    else:
                        g.write("-1\n")
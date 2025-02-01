import random

n, m = 100, 100

with open("case2/1.in", "w") as f:
    with open("case2/1.out", "w") as g:
        f.write(str(n) + " " + str(m) + "\n")
        arr1 = [random.randint(1, 1000) for _ in range(n)]
        arr1.sort()
        arr2 = [random.randint(1, 1000) for _ in range(m)]
        arr2.sort()
        f.write(" ".join(map(str, arr1)) + "\n")
        f.write(" ".join(map(str, arr2)) + "\n")
        arr = arr1 + arr2
        arr.sort()
        g.write(" ".join(map(str, arr)) + "\n")
        
            
n, m = 500000, 500000

with open("case2/2.in", "w") as f:
    with open("case2/2.out", "w") as g:
        f.write(str(n) + " " + str(m) + "\n")
        arr1 = [random.randint(1, 10000000) for _ in range(n)]
        arr1.sort()
        arr2 = [random.randint(1, 10000000) for _ in range(m)]
        arr2.sort()
        f.write(" ".join(map(str, arr1)) + "\n")
        f.write(" ".join(map(str, arr2)) + "\n")
        arr = arr1 + arr2
        arr.sort()
        g.write(" ".join(map(str, arr)) + "\n")
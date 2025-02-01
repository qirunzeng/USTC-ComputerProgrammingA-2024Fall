# Author: Qirun Zeng
# Date Created: 2024-12-03 22:19:24
# Last Modified: 2024-12-03 22:50:42
# Description:

from typing import List, Tuple, Dict, Any
import heapq
import random

t = 1000

arr = []

people = [0] * t

for _ in range(t):
    people[_] = random.randint(1, 100)
    arr.append([0] * people[_])
    for i in range(people[_]):
        # float, 2 位小数
        arr[_][i] = random.randint(-100, 100)

with open("1.in", "w") as f:
    f.write(f"{t}\n")
    for _ in range(t):
        f.write(f"{people[_]}\n")
        for i in range(people[_]):
            f.write(f"{arr[_][i]} ")
        f.write("\n")

for _ in range(t):
    arr[_].reverse()

with open("1.out", "w") as g:
    for _ in range(t):
        for i in range(people[_]):
            g.write(f"{arr[_][i]} ")
        g.write("\n")



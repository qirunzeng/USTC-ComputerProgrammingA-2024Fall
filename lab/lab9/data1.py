# Author: Qirun Zeng
# Date Created: 2024-12-03 22:19:24
# Last Modified: 2024-12-03 22:34:08
# Description:

from typing import List, Tuple, Dict, Any
import heapq
import random

t = 1000

arr = []

people = [0] * t

score = [0] * t

for _ in range(t):
    people[_] = random.randint(1, 90)
    arr.append([0] * people[_])
    for i in range(people[_]):
        # float, 2 位小数
        arr[_][i] = round(random.uniform(0, 100), 2)

with open("1.in", "w") as f:
    f.write(f"{t}\n")
    for _ in range(t):
        score[_] = arr[_][random.randint(0, people[_]-1)]
        f.write(f"{people[_]} {score[_]}\n")
        for i in range(people[_]):
            f.write(f"{arr[_][i]} ")
        f.write("\n")

for _ in range(t):
    arr[_].sort()

with open("1.out", "w") as g:
    for _ in range(t):
        mid = 0
        if people[_] & 1:
            mid = arr[_][people[_] >> 1]
        else:
            mid = (arr[_][people[_]>>1]+arr[_][(people[_]>>1)-1]) / 2
        if score[_] > mid:
            g.write("True\n")
        else:
            g.write("False\n")



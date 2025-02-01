str1 = "Qirun Zeng is very handsome! Langlang is stupid. "
str2 = "stupid is Langlang! handsome very is Zeng Qirun. "

with open("4.in", "w") as f:
    for _ in range(200):
        f.write(str1)

with open("4.out", "w") as f:
    for _ in range(200):
        f.write(str2)
n = int(input())
for _n in range(n):
    s = input()
    if s[0] == '-':
        print('-' + s[:0:-1])
    else:
        print(s[::-1])
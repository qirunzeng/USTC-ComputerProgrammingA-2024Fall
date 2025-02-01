import random

_MIN = -2147483648
_MAX = 2147483647

def generate_random():
    return random.randint(_MIN, _MAX)

for _ in range(9):
    with open('case_4/' + str(_) + '.in', 'w') as f:
        with open('case_4/' + str(_) + '.out', 'w') as g:
            n = random.randint(1, 10000)
            f.write(str(n) + '\n')
            for i in range(n):
                num = generate_random()
                base = random.choice([2, 8, 16])
                f.write(str(num) + ' ' + str(base) + '\n')
                if base == 2:
                    if num < 0:
                        g.write('-' + bin(-num)[2:] + '\n')
                    else:
                        g.write(bin(num)[2:] + '\n')
                elif base == 8:
                    if num < 0:
                        g.write('-' + oct(-num)[2:] + '\n')
                    else:
                        g.write(oct(num)[2:] + '\n')
                else:
                    if num < 0:
                        g.write('-' + hex(-num)[2:] + '\n')
                    else:
                        g.write(hex(num)[2:] + '\n')


with open('case_4/10.in', 'w') as f:
    with open('case_4/10.out', 'w') as g:
        n = 12
        f.write(str(n) + '\n')
        for num in [-31, 31, _MIN, _MAX]:
            for base in [2, 8, 16]:
                f.write(str(num) + ' ' + str(base) + '\n')
                if base == 2:
                    if num < 0:
                        g.write('-' + bin(-num)[2:] + '\n')
                    else:
                        g.write(bin(num)[2:] + '\n')
                elif base == 8:
                    if num < 0:
                        g.write('-' + oct(-num)[2:] + '\n')
                    else:
                        g.write(oct(num)[2:] + '\n')
                else:
                    if num < 0:
                        g.write('-' + hex(-num)[2:] + '\n')
                    else:
                        g.write(hex(num)[2:] + '\n')
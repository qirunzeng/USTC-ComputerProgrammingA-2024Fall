# import random


# for i in range(1, 6):
#     with open("case5/" + str(i) + '.in', 'w') as f:
#         with open("case5/" + str(i) + '.out', 'w') as g:
#             n = random.randint(1, 10000)
#             f.write(str(n) + '\n')
#             for _ in range(n):
#                 s = ''
#                 len = random.randint(1, 15)
#                 for j in range(len):
#                     s += (chr(random.randint(32, 126)))
#                 f.write(s + '\n')
#                 flag = True
#                 index = 0
#                 if not ('a' <= s[0] <= 'z' or 'A' <= s[0] <='Z' or s[0] == '_'):
#                     flag = False
#                 while index < len and flag:
#                     if not ('a' <= s[index] <= 'z' or 'A' <= s[index] <='Z' or s[index] == '_' or '0' <= s[index] <= '9'):
#                         flag = False
#                         break
#                     index += 1
                    
#                 if flag:
#                     g.write('True\n')
#                 else:
#                     if index == 0:
#                         g.write(str(0) + ' ' + s[index] + ' ' + str(1) + '\n')
#                     else:
#                         g.write(str(index) + ' ' + s[index] + ' ' + str(2) + '\n')
                    
n = int(input())

for _ in range(n):
    s = input()
    flag = True
    index = 0
    if not ('a' <= s[0] <= 'z' or 'A' <= s[0] <='Z' or s[0] == '_'):
        flag = False
    while index < len(s) and flag:
        if not ('a' <= s[index] <= 'z' or 'A' <= s[index] <='Z' or s[index] == '_' or '0' <= s[index] <= '9'):
            flag = False
            break
        index += 1
    if flag:
        print('True')
    else:
        if index == 0:
            print(str(0) + ' ' + s[index] + ' ' + str(1))
        else:
            print(str(index) + ' ' + s[index] + ' ' + str(2))
import math

for i in range(int(input())):
    n,x = map(int, input().split())
    if n%6:
        extra = 1
    else:
        extra = 0
    print((n//6 + extra)* x)


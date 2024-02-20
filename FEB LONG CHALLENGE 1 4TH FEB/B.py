import math

T=int(input())

for i in range(T):
    N=int(input())
    x=math.pow(0.143*N,N)
    if x-math.floor(x)<0.5:
        print(math.floor(x))
    else:
        print(math.floor(x)+1)
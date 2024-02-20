import math

def isPowerOfTwo(n):
    cnt = 0
    while n > 0:
        if n & 1 == 1:
            cnt = cnt + 1
        n = n >> 1
    if cnt == 1 : 
        return 1
    return 0

def gcd(x, y):
    while(y):
       x, y = y, x % y
    return abs(x)
    
    
for T in range(int(input())):
    x,y = map(int,input().split())
    if x==y:
        print(x)
    elif x==0 or y==0:
        print(-1)
    else: #check for possiblity
        hcf = gcd(x,y)
        a,b = x//hcf , y//hcf
        if isPowerOfTwo(a) and isPowerOfTwo(b): # possible
            c = int(abs(math.log2(a) - math.log2(b)))
            #print("c ->",c,math.log2(a),math.log2(b))
            print(c + max(x,y))
        else:
            print(-1)
        

def gcd(x, y):
    while(y):
       x, y = y, x % y
    return abs(x)
def sumSquare(n):
    s = []
    for i in range(n):
        if i * i > n:
            break
        s.append(i*i)
        if (n - i * i) in s:
           # print((n - i * i)**(1 / 2),"^2 +", i, "^2")
            return True
    return False

for T in range(int(input())):
    n = int(input())
    if(n>=10 and n%2 == 0 and sumSquare(n//2)):
        print(2)
    else:
        print(1)

'''
Chef has two integers X and Y. Chef wants to perform some operations to make both X and Y zero simultaneously. In one operation, Chef can either:

set X:=2⋅X
or set Y:=2⋅Y
or set X:=X−1 and Y:=Y−1
Chef is a little busy with preparing the contest. Help him find the minimum number of operations required to make both X and Y equal to 0 simultaneously. If it is impossible to do so after any number of operations, print −1.

Input Format
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space separated integers X and Y.
Output Format
For each test case, print the minimum number of operations required to make X and Y zero simultaneously. If it is impossible to do so after any number of operations, print −1 instead.

Constraints
1≤T≤3⋅105
0≤X,Y≤1018
Sample Input 1 
2
1 2
99999999999999999 99999999999999999
Sample Output 1 
3
99999999999999999
Explanation
Let (x,y) denote the values of X and Y respectively.

Test case 1: Three operations are required: (1,2)−→−−−X:=X⋅2(2,2)−→−−−−Y:=Y−1X:=X−1(1,1)−→−−−−Y:=Y−1X:=X−1(0,0)
It can be proven that it is impossible in fewer operations.
'''



import math

def powerOfTwo(n):
    return math.log2(n)

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
    
for i in range(int(input())):
    x,y = map(int, input().split())
    if x==y:
        print(x)
    elif x==0 or y==0:
        print(-1)
    else:
        t = 0
        mn,mx = min(x,y),max(x,y)
        ans = 0
        while(True):
            mn*=2
            t+=1
            if mn>=mx:
                mn//=2
                t-=1
                break
        ans+=t
        t = mn -(mx - mn)
        mn-=t
        mx-=t
        ans+=t
        ans+=1
        t = mx
        ans+=t
        print(ans)


'''
Chef has 3 hidden numbers A,B, and C such that 0≤A,B,C≤N.

Let f be a function such that f(i)=(A⊕i)+(B⊕i)+(C⊕i). Here ⊕ denotes the bitwise XOR operation.

Given the values of f(0),f(1),…,f(N), determine the values of A,B, and C.

It is guaranteed that at least one tuple exists for the given input. If there are multiple valid tuples of A,B,C, print any one.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer N denoting the upper bound on the values of A,B,C.
Next line contains N+1 space-separated integers denoting f(0),f(1),…,f(N).
Output Format
For each test case, output on a new line, three space-separated integers, the values of A,B, and C. If there are multiple valid tuples of A,B,C, print any one.

Constraints
1≤T≤2⋅104
2≤N≤105
Sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
2
0 3 6
2
4 7 2
5
9 6 11 8 13 10
Sample Output 1 
0 0 0
2 0 2
1 3 5
Explanation
Test case 1: The tuple A=0,B=0,C=0 satisfies as:

f(0)=0⊕0+0⊕0+0⊕0=0.
f(1)=0⊕1+0⊕1+0⊕1=3.
f(2)=0⊕2+0⊕2+0⊕2=6.
Test case 2: The tuple A=2,B=0,C=2 satisfies as:

f(0)=2⊕0+0⊕0+2⊕0=4.
f(1)=2⊕1+0⊕1+2⊕1=7.
f(2)=2⊕2+0⊕2+2⊕2=2.
Test case 3: The tuple A=1,B=3,C=5 satisfies as:

f(0)=1⊕0+3⊕0+5⊕0=9.
f(1)=1⊕1+3⊕1+5⊕1=6.
f(2)=1⊕2+3⊕2+5⊕2=11.
f(3)=1⊕3+3⊕3+5⊕3=8.
f(4)=1⊕4+3⊕4+5⊕4=13.
f(5)=1⊕5+3⊕5+5⊕5=10.
'''


import math

def highestPowerOf2(n):
    res = 0
    for i in range(n,0,-1):
        if (i & (i-1)) == 0:
            res = i
            break
    return res

for _ in range(int(input())):
    n = int(input())
    f = [int(i) for i in input().split()]

    ans = [0,0,0]
    i = highestPowerOf2(n)
    while(i > 0):
        diff = f[i] - f[0]
        if diff < 0:
            diff*=-1
            c = diff//i
            if c == 1:
                c = 2
                if ans[0]^i <= n:
                    ans[0]^=i
                    c-=1
                if c and (ans[1]^i) <= n:
                    ans[1]^=i
                    c-=1
                if c>0 and  ans[2]^i <= n:
                    ans[2]^=i
            elif c==3:
                ans[0]^=i
                ans[1]^=i
                ans[2]^=i
        else:
            c = diff//i
            if(c == 1):
                if ans[0]^i <= n:
                    ans[0]^=i
                elif ans[1]^i <= n:
                    ans[1]^=i
                else:
                    ans[2]^=i

        ans.sort()
        i//=2
    print(*ans)

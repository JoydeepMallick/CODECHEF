'''
Chef has two distinct positive integers A and B.

Chef wonders how many distinct values are possible for the expression gcd(A+X,B+X), where X can take any non-negative integer value.

Help Chef find this value.

Here, gcd stands for Greatest Common Divisor.

Input Format
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two distinct space separated integers A and B.
Output Format
For each testcase, output the number of distinct values of the expression gcd(A+X,B+X), where X can take any non-negative integer value.

Constraints
1≤T≤1000
1≤A,B≤109
A≠B
Sample Input 1 
2
1 2
12 8
Sample Output 1 
1
3
Explanation
Test case 1: Here gcd(1+X,2+X)=1 no matter what value of X you choose.

Test case 2:

If we take X=0, gcd(12,8)=4.
If we take X=1, gcd(13,9)=1.
If we take X=2, gcd(14,10)=2.
It can be shown that no other value of gcd is possible.
'''

'''
Expalntion

Keen observation is the key

note that count  the number of factors of abs(a-b)

its equal to the number of different gcd possible🤨 
'''

import math

for T in range(int(input())):
    a,b = map(int,input().split())
    c = 0
    n = abs(a-b)
    for i in range(1,int(math.sqrt(n))+1):
        if n%i==0:
            if n//i == i : #i*i is n
                c+=1
            else:
                c+=2 # always we find pairs ie(2,50) and (50,2)
    print(c)
'''Given two positive numbers B and C, what is the minimum positive value of A, such that A⋅B is divisible by C.

Here, A⋅B denotes the value obtained when A is multiplied by B.

Input Format
The first line will contain an integer T - number of test cases. Then the test cases follow.
The first and only line of each test case contains two integers B and C.
Output Format
For each test case, output the minimum value of A such that A⋅B is divisible by C.

Constraints
1≤T≤105
1≤B,C≤109
Sample Input 1 
2
2 4
8 12
Sample Output 1 
2
3
Explanation
Test case 1: We have B=2 and C=4. If we choose A=2, then A⋅B=4, which is divisible by 4. Note that this is minimum positive value of A, such that A⋅B is divisible by C.

Test case 2: We have B=8 and C=12. If we choose A=3, then A⋅B=24, which is divisible by 12. Note that this is minimum positive value of A, such that A⋅B is divisible by C.


'''
##logic

'''
we need to find out the minimum possible value of A for which A.B is divisible by C

🌟if B divible by C, A=1

🌟 else find gcd of (B,C) and simplify both.THe leftover value of C cant dvivde B hence A=C for C to divide above
'''
def gcd(b,c):
    div,dvnd=min(b,c),max(b,c)
    while(dvnd%div!=0):
        div,dvnd=dvnd%div,div
    return div

for i in range(int(input())):
    b,c=map(int, input().split())
    if b%c==0: # b divisible by c
        print(1) # a minimum value positive =1
    else:
        print(c//gcd(b,c))
   
'''
Given two integers A and B.

Let P denote a sequence of N prime numbers such that the sum of the sequence is A.
Let Q denote a sequence of M prime numbers such that the sum of the sequence is B.
Let X denote the maximum absolute difference between Pi and Qj among all valid pairs (i,j) such that (1≤i≤N) and (1≤j≤M). Find the minimum possible value of X over all possible sequences P and Q.

More formally, for all possible sequences P and Q, find the minimum value of max(|Pi−Qj|), where (1≤i≤N) and (1≤j≤M).

Print −1 if any one of the sequences cannot be formed.

Note that, |X| denotes the absolute value of a number X. For example, |−4|=4 and |7|=7.

Input Format
First line will contain T, the number of test cases. Then the test cases follow.
Each test case contains two integers A and B.
Output Format
For each test case, find the minimum possible value of the maximum absolute difference between Pi and Qj for (1≤i≤N) and (1≤j≤M). If any of the sequences can not be formed, print −1 instead.

Constraints
1≤T≤105
1≤A≤1018
1≤B≤1018
Sample Input 1 
2
3 6
3 2
Sample Output 1 
0
1
Explanation
Test case 1: Let P={3} and Q={3,3}.
The maximum absolute difference is 0. It can be shown that the maximum absolute difference can not be less than 0.

Test case 2: The only possible sequences are P={3} and Q={2}.
The maximum absolute difference is 1. It can be shown that the maximum absolute difference can not be less than 1.
'''


import math
'''
we can show that any number can be represented as the sum of 2 and 3 using 2 any
number of times and 3. 100 = 2*50, 25 = 2*11 + 3,......

we need to min absoulte difference of the primes used to make a and b
hence if gcd(a,b) is 1 ie 2,3 or 7,11 our min. abosulte difference will always
be 1 since they can always be represented as 2 and 3 and we are not given n and
m.

if gcd(a,b) > 1 then we have a common prime factor hence min.abosulte
difference is always 0.

not if a or b is 1 then we cannot obtain such a number with any prime factors.
hence min diff. would not be possible hence 0.
'''

for i in range(int(input())):
    a,b = map(int,input().split())
    if a == 1 or b == 1:
        print(-1)
    elif math.gcd(a,b) == 1:
        print(1)
    elif math.gcd(a,b) > 1:
        print(0) # common prime factors create sum

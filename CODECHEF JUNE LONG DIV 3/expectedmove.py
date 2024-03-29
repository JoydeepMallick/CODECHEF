'''
You are given a fair coin and two integers X and N.

You repeatedly flip the coin and perform the following operation based on the result:

If it lands on heads, then X will increase by 1. However, if X=N then X will not change.
If it lands on tails, X will decrease by 1.
You stop as soon as the value of X becomes 1.

Find the expected number of coin flips.

Note that it is guaranteed that under the given constraints, the answer is an integer and does not exceed 2⋅1018
Input Format
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space separated integers X and N.
Output Format
For each testcase, output the expected number of coin flips.

Constraints
1≤T≤105
1≤X≤N≤109
Sample Input 1 
4
1 3
2 2
12 12
568 57800
Sample Output 1 
0
2
132
65223144
Explanation
In the first test case, X is already 1. So, the expected number of coin flip in this case is 0.

In the second test case, if the coin lands on head, X will not change because X is equal to N here. Whenever the coin lands on tail, X will decrease by 1 and the game ends as X becomes 1. The expected number of coin flips to get the first tail is 2. So, the answer for the case is 2.

'''

for T in range(int(input())):
    x,n = map(int,input().split())
    print((x-1)*(2*n-x))

'''
You are given an array A containing N positive integers. Find the number of pairs (i,j) such that 1≤i<j≤N and:
Ai+Aj≥Ai⋅Aj
Input Format
The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, output on a new line the required answer.

Constraints
1≤T≤1000
2≤N≤2⋅105
1≤Ai≤106
Sum of N over all cases won't exceed 2⋅105
Sample Input 1 
2
3
1 3 4
5
2 3 4 5 6
Sample Output 1 
2
0
Explanation
Test case 1: The two pairs are (1,2) and (1,3), because:

A1+A2=4>3=A1⋅A2
A1+A3=5>4=A1⋅A3
Test case 2: No pairs satisfy the condition.
'''


for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    c = 0
    ones_ahead = a.count(1)
    for i in range(n-1):
        if a[i]==1:# in [0,1]:
            c+=(n-i-1)
            ones_ahead -=1
        else:
            c+=ones_ahead
    twos = a.count(2)
    c+=twos*(twos-1)//2 #nC2
    print(c)
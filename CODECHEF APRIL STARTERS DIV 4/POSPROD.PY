'''
You are given an array A of length N. Find the number of pairs of indices (i,j) such that

1≤i<j≤N
Ai⋅Aj>0
Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N - the size of the array A.
The second line of each test case contains N space-separated integers A1,A2,…,AN denoting the array A.
Output Format
For each test case, output the number of pairs which satisfy the above conditions.

Constraints
1≤T≤1000
2≤N≤105
−104≤Ai≤104
Sum of N over all test cases does not exceed 2⋅105
Sample Input 1 
3
5
1 -3 0 2 -1
4
-1 -1 -1 -1
4
0 1 2 3
Sample Output 1 
2
6
3
Explanation
Test case 1: The pairs which satisfy the conditions are (1,4) and (2,5).

Test case 2: The pairs which satisfy the conditions are (1,2), (1,3), (1,4), (2,3), (2,4) and (3,4).

Test case 3: The pairs which satisfy the conditions are (2,3), (2,4) and (3,4).
'''

for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    lst_neg = [i for i in a if i<0]
    lst_pos = [i for i in a if i>0]
    pair_count = 0
    s = len(lst_pos)
    if s > 1:
        pair_count+= s*(s-1)//2
    s = len(lst_neg)
    if s > 1:
        pair_count+= s*(s-1)//2
    print(pair_count)
    
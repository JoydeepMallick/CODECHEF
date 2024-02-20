'''
You are given an array A of length N.

Determine the count of subarrays of A which contain their length as an element.

Formally, count the number of pairs (L,R) (1≤L≤R≤N) such that: (R−L+1)∈{AL,AL+1,…,AR}.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
First line of each test case contains an integer N denoting the length of the array A.
Second line of each test case contains N space-separated integers A1,A2,…,AN - denoting the array A.
Output Format
For each test case, output the count of subarrays containing their lengths.

Constraints
1≤T≤1000
1≤N≤2⋅105
1≤Ai≤N
Sum of N over all test cases does not exceed 5⋅105.
Sample Input 1 
3
3
1 2 1
5
2 3 1 3 5
10
10 7 4 4 2 9 2 1 9 3
Sample Output 1 
4
6
15
Explanation
Test Case 1: There are 4 subarrays (i,j) containing their lengths. They are (1,1),(1,2),(2,3), and (3,3).

Test Case 2: There are 6 subarrays (i,j) containing their lengths. They are (1,2),(1,3),(1,5),(2,4),(3,3), and (3,5).
'''

#solution
#https://www.youtube.com/watch?v=7kPUQXNvIdE

for T in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    
    map_ = {}
    ans = 0
    for i in range(n):
        len_window = a[i]
        si = (i - len_window + 1)
        if si < 0:
            si = 0
        if (a[i] in map_ and map_[a[i]]>=si):
            si = map_[a[i]] + 1
        ei = si + len_window - 1
        if ei >= n:
            ei = n - 1
        if (ei-si+1 != len_window or si>ei):
            continue
        #print((i-si+1),(n-ei))
        ans+=min(i-si+1, n-ei)
        map_[a[i]] = i
    print(ans)



'''
You are given an array A of length N containing the elements −1 and 1 only. Determine if it is possible to rearrange the array A in such a way that Ai is not the geometric mean of Ai−1 and Ai+1, for all i such that 2≤i≤N−1.

Y is said to be the geometric mean of X and Z if Y2=X⋅Z.

Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N - the size of the array A.
The second line of each test case contains N space-separated integers A1,A2,…,AN denoting the array A.
Output Format
For each test case, output Yes if it is possible to rearrange A in such a way that Ai is not the geometric mean of Ai−1 and Ai+1, where 2≤i≤N−1. Otherwise output No.

You may print each character of Yes and No in uppercase or lowercase (for example, yes, yEs, YES will be considered identical).

Constraints
1≤T≤200
3≤N≤1000
Ai∈{−1,1}
Sample Input 1 
3
5
1 1 1 -1 -1
3
1 1 1
6
1 -1 -1 -1 -1 1
Sample Output 1 
Yes
No
Yes
Explanation
Test case 1: We can rearrange the array A to [1,1,−1,−1,1]. One can see that Ai2≠Ai−1⋅Ai+1, for any 2≤i≤N−1.

Test case 2: None of the rearrangements of A satisy the given condition.
'''

'''
https://www.youtube.com/watch?v=3wmIMusdTTo
'''

for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    pos = a.count(1)
    neg = n - pos
    if abs(pos-neg)<2:
        print("Yes")
    elif abs(pos-neg)==2 and pos%2==0 and neg%2==0:
        print("Yes")
    else:
        print("No")
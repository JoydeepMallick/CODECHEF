'''
You are given two integers N and X. Output an array A of length N such that:

−1000≤Ai≤1000 for all 1≤i≤N.
All Ai are distinct.
mean(A)=X.
If there are multiple answers, print any. It is guaranteed that under the given constraints at least one array satisfying the given conditions exists.

As a reminder, the mean of an array B of size M is defined as: mean(B)=∑Mi=1BiM.

For example, mean([3,1,4,5])=3+1+4+54=134=3.25.

Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first and only line of each test case contains two integers N and X - the size of the array A and the mean of the array A.
Output Format
For each test case, output an array A of length N which satisfies the given conditions.

Constraints
1≤T≤100
1≤N≤1000
0≤X≤100
Sample Input 1 
3
3 7
5 1
1 10
Sample Output 1 
5 10 6
1 2 3 4 -5
10
Explanation
Test case 1: mean([5,10,6])=5+10+63=213=7.

Test case 2: mean([1,2,3,4,−5])=1+2+3+4+(−5)5=55=1.

Test case 3: mean([10])=101=10.
'''


for i in range(int(input())):
    n,x = map(int,input().split())
    a = [x]*n
    k = 1
    for i in range(0,n-1,2):
        a[i] = a[i] - k
        a[i+1] = a[i+1] + k
        k+=1
    if max(a) > 1000:
        #again adjust array
        diff = max(a) - 1000
        a[a.index(min(a))] += diff # such series is always possible by question
    
    for i in a:
        print(i,end=" ")
    print()
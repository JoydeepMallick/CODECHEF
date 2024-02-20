'''
An array is called lovely if the sum of product of each adjacent pair of elements is odd.

More formally, the array S of size M is lovely if the value ∑M−1i=1 (Si.Si+1) is odd.

You are given an array A consisting of N positive integers. Find a permutation of array A which is lovely.

If multiple such permutations are possible, output any. If there is no lovely permutation, output -1.

Input Format
The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, if a lovely permutation of A is possible, print a single line containing N integers denoting the elements of any lovely permutation of A. Otherwise, print -1.

Constraints
1≤T≤1000
2≤N≤500
1≤Ai≤106
Subtasks
Subtask 1 (100 points): Original constraints.
Sample Input 1 
2
5
1 2 3 4 10
3
7 11 145
Sample Output 1 
3 1 10 2 4
-1
Explanation
Test Case 1: The sum of products of adjacent pair of elements of the given array is 1⋅2+2⋅3+3⋅4+4⋅10=2+6+12+40=60. Since this value is even, this is not a lovely permutation of the array.
A lovely permutation of the given array is [3,1,10,2,4]. The sum of products for this array would be 3⋅1+1⋅10+10⋅2+2⋅4=41, which is odd.

Test Case 2: No permutation of the given array exists where the sum of products of adjacent pair of elements is odd. Thus, answer is −1.

'''


for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()][:n]
    
    odd = [i for i in a if i%2==1]
    even = [i for i in a if i%2==0]
    count_o,count_e = len(odd), len(even)
    
    if count_o >=2:
        if count_o % 2 == 0:
            ans = odd + even # all odd then all even in list
            print(' '.join(map(str,ans)))
        else:
            if count_e == 0: # no of odd elements is odd then not possible
                print(-1)
            else:
                last = odd.pop()
                ans = odd + even # even in between all odd
                ans.append(last)
                print(' '.join(map(str,ans)))
    else:
        print(-1)
    
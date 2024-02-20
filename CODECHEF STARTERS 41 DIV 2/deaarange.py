'''

You are given a permutation P of length N. A permutation of length N is an array where every element from 1 to N occurs exactly once.

You must perform some operations on the array to make it sorted in increasing order. In one operation, you must:

Select two indices L and R (1≤L<R≤N)
Completely dearrange the subarray PL,PL+1,…PR
A dearrangement of an array A is any permutation B of A for which Bi≠Ai for all i.

For example, consider the array A=[2,1,3,4]. Some examples of dearrangements of A are [1,2,4,3], [3,2,4,1] and [4,3,2,1]. [3,5,2,1] is not a valid dearrangement since it is not a permutation of A. [1,2,3,4] is not a valid dearrangement either since B3=A3 and B4=A4.

Find the minimum number of operations required to sort the array in increasing order. It is guaranteed that the given permutation can be sorted in atmost 1000 operations.

Input Format
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N — the size of the permutation P.
The second line of each test case contains N space-separated integers P1,P2,…,PN denoting the permutation P.
Output Format
On the first line of each test case output the minimum number of operations M. The description of the M operations must follow.
Each operation must be described in two lines
On the first line of each operation output two space separated integers L and R (1≤L<R≤N) — the indices of the subarray chosen.
On the second line output N space separated integers — the permutation P after dearranging the subarray PL,PL+1,…PR. Note that you have to output the whole permutation {P1,P2,…PN}
Constraints
1≤T≤200
3≤N≤1000
P is a permutation of length N
The sum of N over all test cases does not exceed 1000
It is guaranteed that the given permutations can be sorted in atmost 1000 operations.
Sample Input 1 
2
5
1 2 3 4 5
5
2 1 3 5 4
Sample Output 1 
0
2
1 2
1 2 3 5 4
4 5
1 2 3 4 5
Explanation
Test case 1: No operations are required since the permutation is already sorted.

Test case 2: Initially, P=[2,1,3,5,4]. Consider the following sequence of operations.

Choose L=1 and R=2 and dearrange the subarray in the following manner [2,1––––,3,5,4]→[1,2,3,5,4]
Choose L=4 and R=5 and dearrange the subarray in the following manner [1,2,3,5,4––––]→[1,2,3,4,5]
It can be shown that it is not possible to sort the given permutation in less than 2 operations.

'''
import random

#within 2 operations we can make it
def solve():
    #case 0 when already sorted
    if p==srt_p:
        print(0)
        return

    #case 1
    for i in range(n):
        if(p[i] != (i + 1)):
            start = i #finds the first index where its unsorted
            break

    for i in range(n - 1 , -1 , -1):
        if(p[i] != (i + 1)):
            end = i
            #finds the index from last where p[i] position is wrong
            break

    yes = True
    for i in range(start , end):
        if(p[i] == srt_p[i]):
            yes = False 
            #if any element in this range is at sorted postion false
            break

    if(yes):
        print(1)
        print(start + 1 , end + 1)
        print(*srt_p)
        return
    
    if(p == [3 , 2 , 1]):
        print(2)
        print(2 , 3)
        print(3 , 1 , 2)
        print(1 , 3)
        print(1 , 2 , 3)
        return
    
    #case 2
    print(2)
    print(1 , n)

    x = p[:] #copy entire p to x
    while(True):
        random.shuffle(p) # shuffle all elements of p
        ok = True
        for i in range(n):
            if(p[i] == srt_p[i] or p[i] == x[i]):
                ok = False
                break
        if(ok):
            break

    print(*p)
    print(1 , n)
    print(*srt_p)     


for T in range(int(input())):
    n = int(input())
    p =  [int(i) for i in input().split()]
    srt_p = sorted(p)
    solve()


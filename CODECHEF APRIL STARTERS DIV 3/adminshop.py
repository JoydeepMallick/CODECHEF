'''
CodeChef admins went on shopping at a shopping mall.

There are N shops in the mall where the ith shop has a capacity of Ai people. In other words, at any point in time, there can be at most Ai number of people in the ith shop.

There are X admins. Each admin wants to visit each of the N shops exactly once. It is known that an admin takes exactly one hour for shopping at any particular shop. Find the minimum time (in hours) in which all the admins can complete their shopping.

Note:

An admin can visit the shops in any order.
It is possible that at some point in time, an admin sits idle and does not visit any shop while others are shopping.
Input Format
First line will contain T, the number of test cases. Then the test cases follow.
The first line of each test case contains two integers N and X - the number of shops and the number of admins.
The second line of each test case contains N integers A1,A2,…,AN - the capacity of the shops.
Output Format
For each test case, output in a single line the minimum time (in hours) in which all the admins can complete their shopping.

Constraints
1≤T≤105
1≤N≤105
1≤X,Ai≤109
Sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
2 3
3 3
4 2
1 2 3 4
1 6
2
Sample Output 1 
2
4
3
Explanation
Test case 1: Minimum time required to complete the shopping is two hours. A possible way to complete shopping in 2 hours is :

1st hour: All 3 admins visit shop 1. This is possible as the capacity of the shop is 3≥3.
2nd hour: All 3 admins visit shop 2. This is possible as the capacity of the shop is 3≥3.
Test case 2: Minimum time required to complete the shopping is 4 hours. A possible way to complete shopping in 4 hours is :

1st hour: Admin 1 visits shop 1 and admin 2 visits shop 4.
2nd hour: Admin 1 visits shop 2 and admin 2 visits shop 3.
3rd hour: Admin 1 visits shop 3 and admin 2 visits shop 2.
4th hour: Admin 1 visits shop 4 and admin 2 visits shop 1.
Test case 3: Minimum time required to complete the shopping is 3 hours. A possible way to complete shopping in 3 hours is :

1st hour: Admins 1 and 2 visits shop 1. All other admins sit idle.
2nd hour: Admins 3 and 4 visits shop 1. All other admins sit idle.
3rd hour: Admins 5 and 6 visits shop 1. All other admins sit idle.
Note that, since the capacity of shop is 2, maximum 2 admins visit the shop at once.
'''


for i in range(int(input())):
    n,x = map(int,input().split())
    a = [int(i) for i in input().split()]
    mn = min(a)
    ans = x//mn + (x%mn!=0)
    print(max(n,ans))
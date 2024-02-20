'''
Chef has an array A of length N.

An index i is called strong if we can change the gcd of the whole array just by changing the value of Ai.

Determine the number of strong indices in the array.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
First line of each test case contains an integer N denoting the size of the array A.
Second line contains N space separated integers A1,A2,…,AN - denoting the array A.
Output Format
For each test case, output the number of strong indices in the array.

Constraints
1≤T≤5⋅104
2≤N≤3⋅105
1≤Ai≤109
Sum of N over all test cases do not exceed 3⋅105.
Sample Input 1 
3
3
5 10 20
4
3 5 7 11
4
2 2 2 2
Sample Output 1 
3
0
4
Explanation
Test Case 1: All the indices are strong.

For index 1 you can change the element to 10 which changes the gcd of the array to 10.
For index 2 you can change the element to 12 which changes the gcd of the array to 1.
For index 3 you can change the element to 12 which changes the gcd of the array to 1.
Test Case 2: No index is strong. If you change any single element, gcd still remains the same.

Test Case 3: All the indices are strong. You can change any element to 3. This changes the gcd of the array to 1.
'''
import math

'''
def powerOfTwo(n):
    return math.log2(n)

def isPowerOfTwo(n):
    cnt = 0
    while n > 0:
        if n & 1 == 1:
            cnt = cnt + 1
        n = n >> 1
    if cnt == 1 : 
        return 1
    return 0
'''
def gcd(x, y):
    while(y):
       x, y = y, x % y
    return abs(x)

def fill(pre,arr,suf,n):
    pre[0] = arr[0];
    for i in range(1,n):
        pre[i] = gcd(pre[i-1], arr[i])
    suf[n-1] = arr[n-1]
    for i in range(n-2,-1,-1):
        suf[i] = gcd(suf[i+1], arr[i])

def gcd_outofrange(l,r,pre,suf,n):
    if l==0:
        return suf[r+1]
    if r == n-1:
        return pre[l-1]
    return gcd(pre[l-1], suf[r+1])

for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    prefix = [0]*n
    suffix = [0]*n
    fill(prefix,a,suffix,n)
    ans = 0
    for i in range(0,n):
        if(gcd_outofrange(i,i,prefix,suffix,n) > 1):
            ans += 1
    print(ans)
    


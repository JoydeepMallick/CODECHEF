'''
You are given an array A consisting of 2⋅N integers.

You can perform the following operation any number of times.

Choose any i (1≤i≤2⋅N) such that Ai is even and divide Ai by 2.
Or choose any i (1≤i≤2⋅N) and multiply Ai by 2.
Find the minimum number of operations required to make the number of even elements and number of odd elements in the array equal.

Input Format
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N — the size of the array A is 2⋅N.
The second line of each test case contains 2⋅N space-separated integers A1,A2,…,A2⋅N denoting the array A.
Output Format
For each test case, output on a new line the minimum number of operations required to make the number of even elements and number of odd elements in the array equal.

Constraints
1≤T≤105
1≤N≤105
1≤Ai≤109
The sum of N over all test cases is at most 105.
Sample Input 1 
3
3
1 2 3 4 5 6
3
1 3 4 8 2 6
3
1 5 3 5 6 7
Sample Output 1 
0
1
2
Explanation
Test case 1: No operations are required since there are already an equal number of odd elements and even elements.

Test case 2: One operation is enough. It can be seen that the number of odd and even elements in the resulting array are equal.

[1,3,4,8,2–,6]−→−÷2i=5[1,3,4,8,1,6]
Test case 3: Here two operations are enough to make the number of odd and even elements in the resulting array equal.

1st operation: [1,5,3,5–,6,7]−→−×2i=4[1,5,3,10,6,7]
2nd operation: [1,5,3,10,6,7–]−→−×2i=6[1,5,3,10,6,14]
'''
import math

def isPowerOfTwo(n):#checks if a number is a power of 2
    cnt = 0
    while n > 0:
        if n & 1 == 1:
            cnt = cnt + 1
        n = n >> 1
    if cnt == 1 : 
        return 1
    return 0


for T in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    #d = {} 
    odd,even = 0,0
    a_even = []
    for i in a:
        if(i%2):
            odd+=1
        else:
            even+=1
            if isPowerOfTwo(i):
                a_even.append(int(math.log2(i)))
            else:
                a_even.append(1)
            #d[i] = i//2;
    a_even.sort()
    ans = 0        
    while(odd!=even):
        if odd > even:
            ans = (odd - even)//2
            break
        else:#need odd
            ans += a_even[0]
            odd += 1
            even -= 1
            a_even.remove(a_even[0])
        
                
    print(ans)
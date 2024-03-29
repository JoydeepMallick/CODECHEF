'''
Stack likes the number 3 a lot.

He has two non-negative integers A and B.
In one operation, Stack can do either of the following:

A:=|A−B| (change A to |A−B|)
B:=|A−B| (change B to |A−B|)
Note that |X| denotes absolute value of X. For example |−7|=7 and |4|=4.

Find the minimum number of operations after which at least one integer out of A and B becomes divisible by 3.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The only line of each test case contains two integers A and B.
Output Format
For each test case, output in a single line the minimum number of operations after which at least one integer out of A and B becomes divisible by 3.

Constraints
1≤T≤105
0≤A,B≤109
Sample Input 1 
2
0 343
1 1
Sample Output 1 
0
1
Explanation
Test case 1: A=0 is already divisible by 3.

Test case 2: In the only operation, Stack can change A=1 to A=|A−B|=|1−1|=0. Now A=0 is divisible by 3.
'''


for T in range(int(input())):
    a,b = map(int,input().split())
    c = 0
    #print(a,b)
    while(abs(a-b)!=3 and a%3 and b%3):
        a,b = abs(a-b), min(a,b)
        #print("values  now",a,b)
        c+=1
    if(a%3==0 or b%3==0):
        print(c)
    else:
        print(c+1)#another ste
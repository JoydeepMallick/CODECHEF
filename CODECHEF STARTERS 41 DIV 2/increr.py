'''
Chef has two integers X and Y. Chef wants to perform some operations to make X and Y equal. In one operation, Chef can either:

set X:=X+1
or set Y:=Y+2
Find the minimum number of operations required to make X and Y equal.

Input Format
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space separated integers X and Y.
Output Format
For each test case, print the minimum number of operations required to make X and Y equal.

Constraints
1≤T≤104
1≤X,Y≤109
Sample Input 1 
5
3 4
5 5
7 3
5 2
7 12
Sample Output 1 
1
0
2
3
5
Explanation
Let (x,y) denote the values of X and Y respectively.

Test case 1: Only one operation is required: (3,4)−→−−−−X:=X+1(4,4)
Test case 2: No operations are required since X and Y are already equal.

Test case 3: Two operations are required: (7,3)−→−−−−Y:=Y+2(7,5)−→−−−−Y:=Y+2(7,7)
Test case 4: Three operations are required. One such sequence of operations is: (5,2)−→−−−−Y:=Y+2(5,4)−→−−−−X:=X+1(6,4)−→−−−−Y:=Y+2(6,6)
'''
import math

for i in range(int(input())):
    x,y = map(int, input().split())
    if(x<y):
        print(y-x)
    elif (x>y):
        if((x-y)%2):
            print((x-y+1)//2 + 1)
        else:
            print((x-y)//2)
    else:
        print(0)
        

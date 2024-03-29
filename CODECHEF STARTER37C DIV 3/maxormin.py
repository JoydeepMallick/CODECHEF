'''
Alice and Bob are ready to play a new game. Both the players take alternate turns. Alice starts first.

There are N binary numbers written on a blackboard.

Alice, in her turn, erases any 2 numbers from the blackboard and writes the bitwise OR of those 2 numbers on the blackboard.
Bob, in his turn, erases any 2 numbers from the blackboard and writes the bitwise AND of those 2 numbers on the blackboard.
Note that, after each move, the count of numbers written on the blackboard reduces by 1.

Both players play until a single number remains on the blackboard. Alice wants to maximise the remaining number while Bob wants to minimise the remaining number. Find the remaining number if both the players play optimally.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
First line of each test case contains of a single integer N - the count of numbers written on the blackboard initially.
Second line of each test case contains N space-separated integers A1,A2,…AN - the numbers written on the blackboard.
Output Format
For each test case, output in a single line, the remaining number, if both the players play optimally.

Constraints
1≤T≤1000
2≤N≤105
0≤Ai≤1
Sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
5
1 1 1 1 0
3
0 1 0
4
0 0 0 0
Sample Output 1 
1
0
0
Explanation
Test case 1: Alice starts first.

In the first move, Alice erases 1 and 0 and writes 1|0=1 on the blackboard. Thus, after this move, the numbers written are {1,1,1,1}.
In the second move, Bob erases 1 and 1 and writes 1&1=1 on the blackboard. Thus, after this move, the numbers written are {1,1,1}.
In the third move, Alice erases 1 and 1 and writes 1|1=1 on the blackboard. Thus, after this move, the numbers written are {1,1}.
In the fourth move, Bob erases 1 and 1 and writes 1&1=1 on the blackboard. Thus, after this move, the numbers written are {1}.
Thus, the remaining number is 1.

Test case 2: It does not matter which two numbers Alice chooses. After the first move, the numbers on the blackboard would be {1,0}. Thus, Bob erases these two numbers and writes 1&0=0.

Test case 3: In all the moves, both players erase two 0s and write a single 0. Thus, the remaining element is 0.

'''

for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    
    c1,c0 = a.count(1),a.count(0)
    if c0 == -1:
        c0 =0
    if c1 == -1:
        c1 = 0
    
    if c1>=c0:
        print(1)
    elif abs(c0-c1) == 1:
        if n%2 == 0:
            print(1)
        else:
            print(0)
    else:
        print(0)
    
        
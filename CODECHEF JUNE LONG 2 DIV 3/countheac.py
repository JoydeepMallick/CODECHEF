'''
There are 10 problems in a contest. You know that the score of each problem is either 1 or 100 points.

Chef came to know the total score of a participant and he is wondering how many problems were actually solved by that participant.

Given the total score P of the participant, determine the number of problems solved by the participant. Print −1 in case the score is invalid.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
Each test case contains of a single line containing a single integer P - denoting the number of points scored by the participant.
Output Format
For each testcase, output the number of problems solved by the participant or −1 if the score is invalid.

Constraints
1≤T≤1000
0≤P≤1000
Sample Input 1 
5
103
0
6
142
1000
Sample Output 1 
4
0
6
-1
10
Explanation
Test Case 1: The participant has solved 4 problems out of which 3 problems are worth 1 point each while 1 problem is worth 100 points.

Test Case 2: Since participant's score is 0, he solved 0 problems.

Test Case 3: The participant has solved 6 problems out of which all the problems are worth 1 point.

Test Case 4: It is not possible to get a score of 142.

Test Case 5: The participant solved all the 10 problems and score of all the problems is 100.
'''


for T in range(int(input())):
    p = int(input())
    solved100 = p//100
    max1mark = 10 - solved100
    if(p%100 > max1mark):
        print(-1)
    else:
        print(solved100 + p%100)
'''
There are N students in a class. Recently, an exam on Advanced Algorithms was conducted with maximum score M and minimum score 0. The average score of the class was found out to be exactly X.

Given that a student having score strictly greater than the average receives an A grade, find the maximum number of students that can receive an A grade.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
The only line of each test case consists of three integers N,M,X - the number of students, the maximum score and the average score respectively.
Output Format
For each test case, output in a single line, the maximum number of students who can receive A grade.

Constraints
1≤T≤1000
2≤N≤107
1≤X≤M≤100
Sample Input 1 
4
2 100 50
3 100 50
5 40 40
10 50 49
Sample Output 1 
1
2
0
9
Explanation
Test case 1: There are 2 students in the class. One of the possible values of scores is [99,1]. Here, the average score is 99+12=1002=50. Only the first student receives an A grade. It can be shown that the maximum number of students receiving an A grade is not more than 1.

Test case 2: There are 3 students in the class. One of the possible values of the scores is [60,20,70]. Here, the average score is 60+20+703=1503=50. The students receiving an A grade are students 1 and 3. It can be shown that the maximum number of students receiving an A grade is not more than 2.

Test case 3: There are 5 students in the class. The average score and the maximum score is 40. Thus, the scores of all the students is 40. Since the score of all the students is equal to the average, none of them receive an A grade.

Test case 4: It can be shown that the maximum number of students receiving an A grade does not exceed 9.
'''

for i in range(int(input())):
    n,m,x = map(int,input().split())
    if m==x:
        print(0)
    else:
        print((n*x)//(x+1)) # total class score//(avg score+1)
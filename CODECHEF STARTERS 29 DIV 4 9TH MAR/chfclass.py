import math
'''
Akash loves going to school, but not on weekends.

A week consists of 7 days (Monday to Sunday). Akash takes a leave every Saturday.

If a month consists of N days and the first-day of the month is Monday, find the number of days Akash would take a leave in the whole month.

Input Format
First line will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, one integer N - the number of days in the month.
Output Format
For each test case, output in a single line, the number of days Akash would take a leave in the whole month.

Constraints
1≤T≤100
1≤N≤109
Subtasks
Subtask 1 (30 points) : 1≤N≤100
Subtask 2 (70 points) : Original Constraints
Sample Input 1 
4
5
6
8
22
Sample Output 1 
0
1
1
3
Explanation
Test case 1: The month consists of 5 days (Monday, Tuesday, Wednesday, Thursday, and Friday). Since there are no Saturdays, Akash would go to school every day. Thus, he takes a leave for 0 days.

Test case 2: The month consists of 6 days (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday). Akash takes a leave only on Saturday. Thus, he takes a leave for 1 day.

Test case 3: The month consists of 8 days (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday, Monday). Akash takes a leave only on Saturday. Thus, he takes a leave for 1 day.
'''


for i in range(int(input())):
	n=int(input())
	if n<6:
		print(0)
	else:
	    incomplete_days = n % 7
	    if incomplete_days == 6:
	        print(n // 7 + 1) # complete weeks + sat of incompelte week
	    else:
	        print(n//7) # only complete weeks

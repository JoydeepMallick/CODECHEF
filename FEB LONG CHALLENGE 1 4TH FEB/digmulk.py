'''

The game starts with N white balls, the i-th of which has a power of Si. It is known that 0≤Si≤9. On each level, a black ball with power K hits each of the white balls. After the collision, the power of each white ball is multiplied by K.

However, white balls are only allowed to have single-digit power. In order to maintain this, a white ball whose power contains multiple digits splits into several white balls with single-digit power, one per digit.

For example, consider a white ball with a power of 4.

If K=2, its resulting power is 8 and it remains a single ball.
If K=13, its resulting power is 52, so it splits into two white balls with power 5 and 2 respectively.
If K=27, its resulting power is 108, so it splits into three white balls with power 1, 0, and 8 respectively.
The aim of the game is to determine the number of white balls after M levels. Note that K remains the same for every level.

Please help Chef win the game. Since the answer can be large, print it modulo 109+7.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, K, and M.
The second line of each test case contains a string S of length N, where Si is the initial power of i-th ball.
Output Format
For each test case, output in a single line the number of white balls at the end of the game, modulo 109+7.

Constraints
1≤T≤100
1≤N≤1000
0≤K,M≤109
Subtasks
Subtask #1 (100 points): Original constraints

Sample Input 1 
3
4 9 2
5418
5 63 3
40514
1 100000 100000
0
Sample Output 1 
14
88
1
Explanation
Test case 1:

Initially S=5418
After the 1st, level S=4536972
After the 2nd level, S=36452754816318
There are 14 white balls, so the answer is 14.

Test case 3: After each level, S=0. So, the answer is 1.
'''

##logic
'''
M<=10^9  hence highly unlikely to store all the numbers in S
rather we wll jusr count the frequency


'''
'''
Ved started playing a new mobile game called Fighting Clans. An army of N enemies is approaching his base. The ith enemy has Hi health points. An enemy gets killed if his health points become 0.
Ved defends his base using a weapon named Inferno. He can set the Inferno to one of the following two modes:

Single-Target Mode: In one second, the Inferno can target exactly one living enemy and cause damage of at most X health points.
Multi-Target Mode: In one second, the Inferno can target all living enemies and cause damage of 1 health point to each of them.
Find the minimum time required to kill all the enemies.

Note: Ved is not allowed to change the mode of the weapon once it is set initially.

Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first line of each test case contains two integers N and X - the number of enemies and the damage caused by the single-target mode of Inferno in one second respectively.
The second line of each test case contains N space-separated integers H1,H2,…,HN where Hi denotes the initial health points of ith enemy.
Output Format
For each test case, output in a single line, the minimum time required to kill all the enemies.

Constraints
1≤T≤1000
1≤N≤200
1≤X≤100
1≤Ai≤100
Sample Input 1 
4
5 4
2 2 4 1 1
3 5
5 4 5
4 4
4 4 4 4
3 10
7 8 9
Sample Output 1 
4
3
4
3
Explanation
Test case 1: In single-target mode, all enemies can be killed in 1 second each. Thus, in single-target mode, the total time required is 5 seconds.
In multi-target mode:

After one second, the health points of the enemies are: [1,1,3,0,0]. Enemies 4 and 5 are dead after one second.
After two seconds, the health points of the enemies are: [0,0,2,0,0].
After three seconds, the health points of the enemies are: [0,0,1,0,0].
After four seconds, the health points of the enemies are: [0,0,0,0,0].
Thus, 4 seconds are required to kill enemies using multi-target mode. The minimum time required to kill all the enemies is 4 seconds.

Test case 2: In single-target mode, all enemies can be killed in 1 second each. Thus, in single-target mode, the total time required is 3 seconds.
In multi-target mode:

After one second, the health points of the enemies are: [4,3,4].
After two seconds, the health points of the enemies are: [3,2,3].
After three seconds, the health points of the enemies are: [2,1,2].
After four seconds, the health points of the enemies are: [1,0,1].
After five seconds, the health points of the enemies are: [0,0,0].
Thus, 5 seconds are required to kill enemies using multi-target mode. The minimum time required to kill all the enemies is 3 seconds.

Test case 3: Here, single-target mode will take 4 seconds and multi-target mode will also take 4 seconds. Therefore, the minimum time required is 4 seconds.

Test case 4: Here, single-target mode will take 3 seconds, while multi-target mode will take 9 seconds. Therefore, the minimum time required is 3 seconds.
'''



for i in range(int(input())):
    n,x = map(int,input().split())
    h = [int(i) for i in input().split()]
    
    st_mode_time = max(h) # 1 health point reuduced  in 1s
    mt_mode_time = 0 # best case  is n when all get killed in 1s each
    for i in h:
        if i<=x:
            mt_mode_time+=1
        else:
            mt_mode_time+= i//x
            if i%x:
                mt_mode_time+=1 # 1s consumed for remaining health
                
    print(min(st_mode_time,mt_mode_time))
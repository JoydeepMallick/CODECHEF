'''
There are N piles where the ith pile consists of Ai stones.

Chef and Chefina are playing a game taking alternate turns with Chef starting first.
In his/her turn, a player can choose any non-empty pile and remove exactly 1 stone from it.

The game ends when exactly 1 pile becomes empty. The player who made the last move wins.
Determine the winner if both players play optimally.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer N denoting the number of piles.
Next line contains N space-separated integers A1,A2,…,AN - denoting the number of stones in each pile.
Output Format
For each test case, output CHEF if Chef wins the game, otherwise output CHEFINA.

Note that the output is case-insensitive i.e. CHEF, Chef, cHeF, and chef are all considered the same.

Constraints
1≤T≤1000
1≤N≤105
1≤Ai≤109
Sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
2
2 2
1
10
3
1 5 6
Sample Output 1 
CHEFINA
CHEFINA
CHEF
Explanation
Test Case 1: No matter which stone Chef removes, Chefina will remove the remaining stone from the same pile and make it empty.

Test Case 2: Since there is only 1 pile containing 10 stones, the game will last exactly 10 moves with last move made by Chefina.

Test Case 3: Chef can remove 1 stone from the first pile and thus make it empty.
'''


for T in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    target = sum(a) #both play optimally no one wants oppoent to win  easily
    if 1 in a or target%2:
        print("Chef")
    else:
        print("Chefina")
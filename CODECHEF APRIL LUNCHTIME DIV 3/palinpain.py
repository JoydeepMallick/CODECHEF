'''
You are given two integers X and Y. You need to construct two different strings S1 and S2 consisting of only the characters ‘a′ and ‘b′, such that the following conditions are satisfied:

Both S1 and S2 are palindromes.
Both S1 and S2 should contain exactly X occurrences of a and Y occurrences of b.
If there are multiple possible answers, you may print any of them. If it is not possible to construct two distinct strings satisfying the conditions, print −1 instead.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases. Then the test cases follow.
Each test case consists of a single line of input containing two space-separated integers X,Y.
Output Format
For each test case:

If it is not possible to construct two distinct strings satisfying the conditions, print −1
Otherwise, print two lines — the first should contain the string S1 and the second should contain S2
If there are multiple possible answers, you may print any of them.
Constraints
1≤T≤1000
1≤X,Y≤103
Sample Input 1 
2
2 4
3 3
Sample Output 1 
abbbba
babbab
-1
Explanation
Test case 1: The three palindromes containing 2 a-s and 4 b-s are abbbba,babbab, and bbaabb. Printing any two of these is a valid answer.

Test case 2: There are no palindromes containing 3 each of a and b.
'''


for i in range(int(input())):
    x,y = map(int,input().split())
    if (x%2==1 and y%2==1) or (x==1 or y==1):
        print(-1)

    elif x%2 == 0 and y%2==0: # possible
        print('a'*(x//2) + 'b'*y + 'a'*(x//2))
        print('b'*(y//2) + 'a'*x + 'b'*(y//2))
    #any one even
    elif x%2==0:
        print('a'*(x//2) + 'b'*y + 'a'*(x//2))
        print('b'*(y//2) + 'a'*(x//2) + 'b'+'a'*(x//2)+'b'*(y//2))
    elif y%2==0:
        print('b'*(y//2) + 'a'*x + 'b'*(y//2))
        print('a'*(x//2) + 'b'*(y//2) + 'a'+'b'*(y//2)+'a'*(x//2))
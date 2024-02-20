'''
Construct an N×M matrix with entries having positive integers such that:

If M>1, ith row is strictly increasing from left to right with a fixed common difference di for all 1≤i≤N.
If N>1, jth column is strictly increasing from top to bottom with a fixed common difference cj for all 1≤j≤M.
All the common differences should be distinct.
In the case of multiple answers, find an arrangement that minimizes the maximum element of the matrix.
Input Format
First line will contain T, number of test cases. Then the test cases follow.
Each test case contains a single line of input, two space-separated integers N and M - the dimensions of the matrix.
Output Format
For each test case, output N lines with each line having M space-separated integers representing the answer.

Constraints
1≤T≤10
1≤N,M≤105
Sum N⋅M over all cases is atmost 105.
Sample Input 1 
3
3 3
1 2
1 1
Sample Output 1 
1 2 3
3 6 9
5 10 15
1 2
1
Explanation
Test case 1: The values d1,d2, and d3 are 1,3, and 5 respectively. The values c1,c2, and c3 are 2,4, and 6 respectively. Note that all these common differences {d1,d2,d3,c1,c2,c3} are distinct. Moreover, it can be shown that over all valid matrices, 15 is the minimal value of the maximum element of the matrix one can achieve.

Test case 2: The values d1 is 1. It can be shown that over all valid matrices, 2 is the minimal value of the maximum element of the matrix one can achieve.
'''
for T in range(int(input())):
    n,m = map(int, input().split())
    if n < m:
        # row 1 printed seperately fixed 1 2 3 ....
        for i in range(m):
            print(i+1, end = " ")
        print()
        
        #printing rest of the rows(optimal since max number mustbe minimum)
        f = 1 + (n+1)
        for i in range(1,n):
            s = f
            print(s, end = " ")
            for j in range(1,m):
                print(s+i+1, end=" ")
                s+=(i+1)
            f += n+1
            print()
    else:
        i = 0
        d = m+1
        while(i < n):
            s = i+1
            print(s, end=" ")
            for j in range(1,m):
                print(s+d, end = " ")
                s+=d
            print()
            i+=1
            d+=1

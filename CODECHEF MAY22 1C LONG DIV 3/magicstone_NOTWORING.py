'''
Initially, there is a magical stone of mass 2N lying at the origin of the number line. For the next N seconds, the following event happens:

Let us define the decomposition of a magical stone as follows: If there is a magical stone of mass M>1 lying at coordinate X, then it decomposes into two magical stones, each of mass M2 lying at the coordinates X−1 and X+1 respectively. The original stone of mass M gets destroyed in the process.
Each second, all the magical stones undergo decomposition simultaneously.
Note that there can be more than one stone at any coordinate X.

Given a range [L,R], find out the number of stones present at each of the coordinates in the range [L,R]. As the number of stones can be very large, output them modulo (109+7).

Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first and only line of each test case contains three integers N, L and R, as described in the problem statement.
Output Format
For each testcase, output in a single line a total of (R−L+1) space-separated integers. The ith integer will denote the number of stones present at X=(L+i−1) coordinate. As the number of stones can be very large, output them modulo (109+7).

Constraints
1≤T≤100
1≤N≤106
−N≤L≤R≤N
Sum of (R−L+1) over all the test cases doesn't exceed 105.
Sample Input 1 
3
2 -2 2
2 0 2
150000 48 48
Sample Output 1 
1 0 2 0 1
2 0 1
122830846
Explanation
Test case 1: Let us look at the number of stones for x=−2 to x=2 as the time progresses:

t=0: {0,0,1,0,0}
t=1: {0,1,0,1,0}
t=2: {1,0,2,0,1}
We have to output the number of stones at x=−2 to x=2, which is {1,0,2,0,1}.

Test case 2: Similar to first test case, We have to output the number of stones at x=0 to x=2, which is {2,0,1}.


'''

'''
explanation

pattern found : 
1
1 1
1 2 1
1 3 3 1
..........
..........


we need 
1
1 0 1
1 0 2 0 1
1 0 3 0 3 0 1
.............
.............

0 represents empty postions...

now we need to work on range l to r

eg. 
           [1 0 3 0 3 0 1]   n=3 [note : n = 0(no decomp)represents 1]
index       0 1 2 3 4 5 6
given       l ..........r

we do not know the value of x.
 but constraint tell us -N <= l,r<= N
 
 means that :-
                1
              1 0 1
            1 0 2 0 1

actual    -2 -1 0 1 2
index       
'''


'''
def nth_row_Pascal(n,arr,l,r):
    # nC0 = 1
    before = 1
    if(0 in range(l+n,r+n + 1)): # 1st element
        #arr.append(before) #1st row = 1 0  then 1 added via loop
        print(before,end =" ")
    if(1 in range(l+n,r+n + 1)): # 1st element
        #arr.append(0) # 1 0 2 0 1  denoting spaces
        print(0,end=" ")
        
    for i in range(1, n + 1):
        # nCr = (nCr-1 * (n - r + 1))/r
        ele = (before * (n - i + 1)) // i
        if((2*i-2) in range(l+n,r + n+ 1)): # primary concern index 0,2,4,....
            #arr.append(ele%(10**9+7))
            print(ele%(10**9+7),end= " ")
            if i < n: # to avoid space after last element else 1 0 2 0 1 0 when n=3
                #arr.append(0) # 0 represents spaces 
                print(0,end = ' ')
        before = ele
    print()
        
for i in range(int(input())):
    n,l,r = map(int,input().split())
    arr = [] #stores nth row of pascals triangle
    nth_row_Pascal(n,arr,l,r) # arr now has nth row
    #print(arr)
   '''

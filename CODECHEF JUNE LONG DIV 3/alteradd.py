'''
Chef has 2 numbers A and B (A<B).

Chef will perform some operations on A.

In the ith operation:

Chef will add 1 to A if i is odd.
Chef will add 2 to A if i is even.
Chef can stop at any instant. Can Chef make A equal to B?

Input Format
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space separated integers A and B.
Output Format
For each test case, output YES if Chef can make A and B equal, NO otherwise.

Note that the checker is case-insensitive. So, YES, Yes, yEs are all considered same.

Constraints
1≤T≤1000
1≤A<B≤109
Sample Input 1 
4
1 2
3 6
4 9
10 20
Sample Output 1 
YES
YES
NO
YES
Explanation
Test case 1: Chef may perform one operation to make A equal to B: 1−→+12
Test case 2: 3−→+14−→+26
Test case 3: It can be shown that it is impossible to make A and B equal.

Test case 4: 10−→+111−→+213−→+114−→+216−→+117−→+219−→+120
'''


'''Explanation

+1,+2,+1,+2,......

prefix sum of above

1,3,4,6,7,9,10,12,.....

see the missing numbers

2,5,8,11,.....

see that all differ by 3

hence if (b-a)//3 * 3 + 2 == b-a

its no
'''


for T in range(int(input())):
    a,b = map(int,input().split())
    if ((b-a)//3 *3) + 2 == (b-a): #constraint b>a already given
        print("no")
    else:
        print("yes")
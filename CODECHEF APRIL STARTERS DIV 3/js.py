'''
Lav has an array A of size N. He noticed that Chef is initially standing at the first index of the array.

While standing at the ith index (1≤i<N) of the array, Chef can perform the following types of jumps:

Jump 1: Jump to the immediate next index j such that Ai and Aj have the same parity.
Jump 2: Jump to the immediate next index j such that Ai and Aj have different parity.
Given that Chef can perform Jump 2 at most once, Lav wants to find the minimum number of jumps required by the Chef to reach the last index of the array.

Input Format
First line will contain T, the number of test cases. Then the test cases follow.
The first line of each test case contains a single integer N - the size of the array A.
The second line of each test case contains N integers A1,A2,…,AN - the elements of the array A.
Output Format
For each test case, output the minimum number of jumps required by the Chef to reach the last index of the array.

Constraints
1≤T≤100
2≤N≤104
1≤Ai≤109
Sample Input 1 
2
4
1 2 3 4
4
2 1 3 4
Sample Output 1 
2
1
Explanation
Test Case 1: The minimum number of jumps required by the Chef to reach the last index is 2. Chef is initially standing at index 1.

Chef chooses Jump 2 and jumps to index 2 as it is the immediate next element with different parity.
Chef chooses Jump 1 and jumps to index 4 as it is the immediate next element with the same parity.
Test Case 2: The minimum number of jumps required by the Chef to reach the last index is 1. Chef is currently standing at index 1.

Chef chooses Jump 1 and jumps to index 4 as it is the immediate next element with the same parity.

'''

'''
Explanation: -

J1 event of same parity
J2 be event of different parity(at max once)

that means if

case 1 :

[e,..............................,e] or [o,..............,o]
never do J2 else we can never again come back to even and land in ast element.
similarly for odd start and end.

In the above case minnimum no. of jumps = 
(no. of odd/even terms depending on start and end element) - 1

since jumps between 3 elements will be 2 times and so on.


case 2:

[o,...............................,e]
J2 can be done once to jump to end even

[e,................................,o]
J2 can be done once to jump to end odd

for example [e,o,o,e,o,e,o,o,o]
             1 2 3 4 5 6 7 8 9
3 possible jumps
1.  1 to 2(J2) - 3 - 5 - 7 - 8 - 9  === 6 jumps(0+ 6)
2.  1 - 4 to 5(J2) - 7 - 8 - 9  ====5 jumps(1+4)
3.  1 - 4 - 6 to 7(J2)-8 - 9  === 5 jumps(2+3)

Since we started from even our possible parity change will be odd since ending
is odd.

hence here we fix the element where we do the parity change(ie the even
element) then we count the number of even elements before parity change and no
of odd elements after parity change. then we compare all the possible such
jumps and find the minimum among them.


Hence of:-
1.p(first) == p(last)--> count the no. of elements with parity -1

2..p(first) != p(last)--> jumps to be considered(see below)

We are least cared of the numbers but theirr parity
hence convert all numbers to 0 and 1 by ele%2

[e,o,o,e,o] == [0,1,1,0,1]



'''

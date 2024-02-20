'''Chef loves bitwise operations. So, he creates the following problem but needs your help to solve it.

Chef calls a sequence of integers A1,A2,…,AN tasty if it satisfies the following condition:

parity(Ai&Ai+1)≠parity(Ai|Ai+1) for 1≤i<N.
Chef gives you a sequence A1,A2,…,AN. You may perform the following operation on the sequence any number of times (possibly 0):

Choose 2 indices i and j (1≤i,j≤n ; i≠j) and change Ai to Ai⊕Aj.
Chef is asking you to make the sequence tasty using the minimum number of operations, or report that it is impossible.

As a friendly reminder,

parity(x) denotes the remainder of dividing x by 2
& denotes the bitwise AND operation
| denotes the bitwise OR operation
⊕ denotes the bitwise XOR operation.
Input Format
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case:

If it is impossible to convert the given sequence into a tasty sequence using the given operations, print a single line containing the integer −1.
Otherwise, first, print a line containing a single integer M ― the minimum number of operations you have to perform.
Then, print M lines describing these operations in the order in which you want to perform them. For each k (1≤k≤M), the k-th of these lines should contain two space-separated integers i and j (1≤i,j≤n ; i≠j) ― the indices on which the k-th operation is performed.
If there are multiple solutions, you may find any one of them.

Constraints
1≤T≤3⋅103
2≤N≤105
0≤Ai<230 for each valid i
The sum of N over all test cases does not exceed 2⋅105
Subtasks
Subtask #1 (100 points): Original constraints

Sample Input 1 
2
2
0 0
3
6 16 69
Sample Output 1 
-1
1
1 3
Explanation
Test case 1: It is impossible to make A tasty using the given operations.

Test case 2: We can choose i=1 and j=3 and apply the operation which converts A into [67,16,69] which is tasty.

'''


 ###LOGIC BELOW:-


'''
for even number always last bit is zero
for odd number last bit will always be 1

NOW, CONSIDERING LASTBIT OF ANY NUMBER

EVEN ^ ODD = ODD      <--needed
EVEN ^ EVEN = EVEN     
ODD ^ EVEN = ODD       <--needed
ODD ^ ODD = EVEN      <--needed

hence for parity condition to be not equal(meaning one even and one odd ) 

now forAi & Ai+1:-
		0 & 1      
		0 & 0   ----> 3 cases when number will be even
		1 & 0  

so Ai & Ai+1 ---not equals--- Ai | Ai+1
	1 & 0                      1 | 0
	  0-->even                   1-->odd

Hence we can conclude that the possible array for this tasty condtion to be possible is
[....,odd,even, odd, even,......]

🌟Now when all the elements are EVEN return -1 since XOR can't make it ODD anymore

🌟 when series has an even, odd or odd,even series its possible

🌟 when series full of ODD  then we can XOR 2 odds to amke a EVEN

now when even, odd, even,.....
4, 5, 5  we know that psoition 3's 5 has to be changed
hence 5 xor 5=0(even)

4, 4, 5, 2
here even, even, odd, even----->convert to ODD, even, odd, even
4 xor 5=(odd number)

🌟🌟🌟comsider below example :-

10  2   3  5  6  9  10

considering [even, odd, even, odd,.....] to be new sequence
-->no, of operations = 2 (2,3)
output:
2
2 4 (2nd and 3rd element xor,replacing 2nd)
3 4	(4th and 3rd element xor,replacing 3rd)

considering [odd, even, odd,.....] to be new sequence
-->no, of operations = 5 (10,5,6,9,10)

hence 1st consideration was less and better.

'''

for i in range(input()):
	n=int(input())
	a=[int(ele) for ele in input().split()]

	
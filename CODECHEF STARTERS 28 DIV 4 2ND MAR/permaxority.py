import math
import random
import string
import os
import time
import sys
import metrics

#import pickle
#import numpy
#import pandas
#import sklearn
#import matplotlib

'''
You are given an integer N. Construct a permutation A of length N which is attractive.

A permutation is called attractive if the bitwise XOR of all absolute differences of adjacent pairs of elements is equal to 0.

Formally, a permutation A=[A1,A2,…,AN] of length N is said to be attractive if:

|A1−A2|⊕|A2−A3|⊕…⊕|AN−1−AN|=0
where ⊕ denotes the bitwise XOR operation.

Output any attractive permutation of length N. If no attractive permutation exists, print −1 instead.

Note: A permutation of length N is an array A=[A1,A2,…,AN] such that every integer from 1 to N occurs exactly once in A. For example, [1,2,3] and [2,3,1] are permutations of length 3, but [1,2,1], [4,1,2], and [2,3,1,4] are not.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line of input, containing one integer N.
Output Format
For each test case, output on a single line an attractive permutation of N integers, or −1 if no attractive permutation exists.

Constraints
1≤T≤1000
2≤N≤105
Sum of N over all cases won't exceed 2⋅105.
Sample Input 1 
2
3
6
Sample Output 1 
3 2 1
5 2 3 6 4 1 
Explanation
Test Case 1: |3−2|⊕|2−1|=1⊕1=0
Note that there are other correct answers — for example, [1,2,3] would also be accepted as correct.

Test Case 2: |5−2|⊕|2−3|⊕|3−6|⊕|6−4|⊕|4−1|=3⊕1⊕3⊕2⊕3=0
'''

'''
logic:-

see the arrangement

its a[i]+a[n-i-1]==n provided n not in [n//2 or n//2-1]
'''

for i in range(int(input())):
	n=int(input())
	
	if n%2!=0 and n!=1: # odd length permutation meaning even no of diff hence always possible
		for i in range(n,0,-1):
		    print(i,end=" ")
	else:
		if n in [1,2]:
			print(-1)
		else: # possible now need to print it
			lst=[None]*n
			lst[n//2-1]=n//2
			lst[n//2]=n
			ele=n-1
			for i in range(len(lst)//2-1):
				if i%2==0:
					lst[i]=ele
					lst[n-i-1]=n-ele
				else:
				    lst[i]=n-ele
				    lst[n-i-1]=ele
				ele-=1
			for i in lst:
				print(i,end=" ")
	print()


'''
Chef has an array A of length N. He defines the alternating sum of the array as:

S=|A1|−|A2|+|A3|−|A4|+…(−1)N−1⋅|AN|
Chef is allowed to perform the following operation on the array at most once:

Choose two indices i and j (1≤i<j≤N) and swap the elements Ai and Aj.
Find the maximum alternating sum Chef can achieve by performing the operation at most once.

Note: |X| denotes the absolute value of X. For example, |−4|=4 and |7|=7.

Input Format
The first line will contain T - the number of test cases. Then the test cases follow.
First line of each test case contains a single integer N - size of the array A.
Second line of each test case contains N space separated integers - denoting the elements of array A.
Output Format
For each testcase, output in a single line, the maximum alternating sum Chef can obtain by performing the operation at most once.

Constraints
1≤T≤105
2≤N≤105
−109≤Ai≤109
Sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
2
2
10 -10
7
-3 -2 -1 0 1 2 3
Sample Output 1 
0
6
Explanation
Test Case 1: One optimal way is to perform no operations. Thus the alternating sum is |10|−|−10|=10−10=0.

Test Case 2: One optimal way is to choose i=2 and j=5. After swapping, the array is [−3,1,−1,0,−2,2,3]. The alternating sum in this case is |−3|−|1|+|−1|−|0|+|−2|−|2|+|3|=6.
'''

import math
import random
import string
import os
import time
import sys

#import metrics

#import pickle
#import numpy
#import pandas
#import sklearn
#import matplotlib


for i in range(int(input())):
	n=int(input())
	a=[abs(int(i)) for i in input().split()] # abs values only

	odd_ind=set([a[i] for i in range(1,n,2)]) # needs to be reduced
	even_ind=set([a[i] for i in range(0,n,2)]) # needs to be added
	odd_ind.sort(reverse=True)
	even_ind.sort()
	i,j=0,0
	while(a.index(odd_ind[j]) <= a.index(even_ind[i])):
		j+=1
		


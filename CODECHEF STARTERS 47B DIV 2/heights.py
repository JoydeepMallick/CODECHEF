'''
Chef is teaching his class of N students at Hogwarts. He groups students with the same height together for an activity. Some of the students end up in a groups with only themselves and are saddened by this.

With the help of his magic wand, Chef can increase the height of any student to any value he likes. Now Chef wonders, what is the minimum number of students whose height needs to be increased so that there are no sad students?

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains one integer N — the number of students.
The second line consists of N space-separated integers H1,H2,…,HN denoting the heights of the students.
Output Format
For each test case, output on a single line the minimum number of students whose heights must to be increased.

Constraints
1≤T≤5⋅104
2≤N≤105
1≤Hi≤109
The sum of N over all test cases won't exceed 3⋅105.
Sample Input 1 
4
4
1 2 1 2
4
1 2 2 2
3
1 1 1
5
1 2 3 4 5
Sample Output 1 
0
1
0
3
Explanation
Test case 1: The students form 2 groups each having 2 students so no change of heights is required.

Test case 2: Initially the student with height 1 cannot be paired with anyone else. Chef can increase his height to 2 and now there is only 1 group with all the 4 students in it.

Test case 3: All students have same height and hence no change of heights is required.

Test case 4: One possible way is to increase the height of the first student to 5 and the heights of the second and third students to 4, hence forming one group of 2 students and one of 3 students. In total, the heights of 3 students need to be changed.
'''

import math

def isPowerOfTwo(x):#checks if a number is a power of 2
    return (x and not(x & x-1))

def sumSquare(n):#checks if a number is sum of squres of 2 natural numbers
    s = []
    for i in range(n):
        if i * i > n:
            break
        s.append(i*i)
        if (n - i * i) in s:
           # print((n - i * i)**(1 / 2),"^2 +", i, "^2")
            return True
    return False

def sieveOfEratosthenes(n):#finds all prime numbers from 2 till n
    primes = [0,0] + [1]*(n-2)
    # 0 and 1 not prime
    p = 2
    while(p**2 <= n):
        if primes[p]:#if true
            for i in range(p**2, n+1, p):#update all multiples of p to 0
                primes[i] = 0;
        p+=1
    return primes

if __name__ == '__main__':
    for T in range(int(input())):
        n = int(input())
        h = [int(i) for i in input().split()]
        c = 0
        d = {}
        for i in h:
            if i not in d:
                d[i] = 1
            else:
                d[i]+=1
        for i in d.keys():
            if d[i] == 1:
                c+=1
	#note that chef can always increase a student's height
        if(c%2):
            mx_ele = max(d.keys())
            mx_count = max(d.values())
            if d[mx_ele] == 1 and mx_count == 2:
                print((c+1)//2 + 1)#max element has to be adjusted ie increase all other smaller elements to max value
            else:
                print((c+1)//2)
        else:
            print(c//2)
        
        
        
        
        
        
        
        
        
        
        
        
        

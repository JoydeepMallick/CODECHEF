'''
Chef considers a permutation P of {1,2,3,…,N} End Sorted if and only if P1=1 and PN=N.

Chef is given a permutation P.

In one operation Chef can choose any index i (1≤i≤N−1) and swap Pi and Pi+1. Determine the minimum number of operations required by Chef to make the permutation P End Sorted.

Note: An array P is said to be a permutation of {1,2,3,…,N} if P contains each element of {1,2,3,…,N} exactly once.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer N, denoting the length of the permutation P.
The second line contains N space-separated integers P1,P2,P3,…,PN, denoting the permutation P.
Output Format
For each test case, output minimum number of operations required by Chef to make the permutation P End Sorted.

Constraints
1≤T≤1000
2≤N≤105
P is a permutation of {1,2,3,…N}
The sum of N over all test cases does not exceed 3⋅105.
Sample Input 1 
4
4
1 3 2 4
3
3 2 1
2
2 1
3
2 1 3
Sample Output 1 
0
3
1
1
Explanation
Test case 1: P is already End Sorted.

Test case 2: P can be made End Sorted using 3 operations as follows: [3,2,1]→[2,3,1]→[2,1,3]→[1,2,3]. It can be shown that achieving this in fewer than 3 moves is impossible.

Test case 3: P can be made End Sorted using one operation, by swapping 1 and 2.

Test case 4: P can be made End Sorted using one operation, by swapping 1 and 2.
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
        a = [int(i) for i in input().split()]
        #chek if 1 and n are adjecent then moves are always n-1
        for i in range(n-1):
            if a[i]==1 and a[i+1]==n:
                print(n-2)
                break
            if a[i] == n and a[i+1] == 1:
                print(n-1)
                break
        else:
            ind1, indn = -1,-1
            for i in range(n):
                if a[i] == 1: ind1 = i
                if a[i] == n : indn = i
                if ind1!=-1 and indn!=-1:
                    break
            if ind1 < indn:
                print(ind1 + n-1 - indn)
            else:
                print(ind1 + n-1 - indn - 1) # extra -1 for a swap of 1 and n
            
            
        
        
        
        
        
        
        
        
        
        
        
        
        

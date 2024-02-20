'''
You have a grid with N rows and M columns. You have two types of tiles — one of dimensions 2×2 and the other of dimensions 1×1. You want to cover the grid using these two types of tiles in such a way that:

Each cell of the grid is covered by exactly one tile; and
The number of 1×1 tiles used is minimized.
Find the minimum number of 1×1 tiles you have to use to fill the grid.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of a single line containing two space-separated integers N,M.
Output Format
For each test case, print on a new line the minimum number of 1×1 tiles needed to fill the grid.

Constraints
1≤T≤104
1≤N,M≤104
Sample Input 1 
4
1 1
4 5
6 8
3 2
Sample Output 1 
1
4
0
2
Explanation
Test case 1: There is only one square in the grid, and it must be filled with a single 1×1 tile.

Test case 2: One way of tiling the grid using 1×1 tiles exactly 4 times is as follows:

sample 2

Test case 3: One way of tiling the grid using no 1×1 tiles is as follows:

sample 3

Test case 4: One way of tiling the grid using 1×1 tiles exactly twice is:

sample 4


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
        n,m = map(int , input().split())
        if(n%2 or m%2):
            if n%2 and m%2:
                print(n+m-1)#one overlapping so -1
            elif n%2:
                print(m)
            elif m%2:
                print(n)
        else:#only 2x2 needed
            print(0)
        
        
        
        
        
        
        
        
        
        
        
        
        

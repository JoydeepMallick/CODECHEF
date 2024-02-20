'''
Anton loves creating strings!

Anton now wants to create a string S following some specific rules. They are as follows:

Initially, S is empty. Then, Anton can perform two types of operations on S:

Choose a lowercase Latin character (an element of {a,b,c,…,z}) and append it to S. For example, if currently S=clap, Anton can turn it into one of {clapa,clapb,…,clapz}.
Append a copy of S to itself. For example, if currently S=clap, Anton can turn it into clapclap.
However, Anton doesn't want to perform operation 1 twice in a row.

You are given a string A consisting of the lowercase Latin alphabet. Is it possible for Anton to create A using his operations any number of times?

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer N, the length of the string A.
The second line of each test case contains a string A of length N.
Output Format
For each test case, output on a new line the answer — YES if Anton can create A using his operations, and NO otherwise.

Each character of the output may be printed in either uppercase or lowercase. For example, the strings YES, yes, and YeS will all be treated as identical.

Constraints
1≤T≤105
1≤N≤106
A consists of only lowercase Latin characters
The sum of N across all test cases won't exceed 106
Sample Input 1 
4
2
ab
3
oof
6
aabaab
5
eevee
Sample Output 1 
NO
YES
YES
NO
Explanation
Test case 1: Anton can create a by starting from the empty string and appending a using operation 1. However, there is no way to create ab — the only way to do so is to use operation 1 again and append b; but this is not allowed.

Test case 2: Anton can create oof from the empty string as follows:

Use operation 1 to append o. The current string is o.
Use operation 2 to append the string to itself. The current string is oo.
Use operation 1 to append f. The string is now oof, as required.
Test case 3: aabaab can be created as follows:

Append a to the empty string. The current string is a.
Use operation 2. The current string is aa.
Append b with operation 1. The current string is aab.
Use operation 2. The current string is aabaab, and we are done.
Test case 4: It can be shown that no sequence of operations will allow Anton to create the string eevee.
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

def break_check(a):
    if len(a) in [0,1]:
        return True
    elif len(a)%2:# odd no of elements
        return break_check(a[:-1]) # remove last element and recheck
    elif a[:len(a)//2] == a[len(a)//2 : ] : # if even no of elements check if halves are equal
        return break_check(a[:len(a)//2])
    else:
        return False
        

if __name__ == '__main__':
    for T in range(int(input())):
        n = int(input())
        a = input()
        #if distinct letter more than 2 not possible
        # continuus repeatation of same element must of count 2,4,8,16,....
        # if one element only always possible
        #hence always break into half after creating even no of elements
        if break_check(a):
            print("YES")
        else:
            print("NO")
            
        
            
        
        
        
        
        
        
        
        
        
        
        
        
        

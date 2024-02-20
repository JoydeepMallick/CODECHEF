
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
        freq = {}
        for i in a:
            if i not in freq:
                freq[i] = 1
            else:
                freq[i]+=1
    
        tmp = list(freq.keys())
        tmp.sort()
        tmp2 = tmp
        c = 0
        while(len(tmp)>0):
            ind = 1
            arr = []
            for ele in tmp2:
                while(freq[ele] > 0 and ele >= ind):
                    arr.append(ele)
                    ind+=1
                    freq[ele]-=1
                
                if freq[ele] == 0:
                    tmp.remove(ele)
            tmp2 = tmp
            c+=1
            print(arr,end="")
        print(c)
            
        
        
        
        
        
        
        
        
        
        
        
        
        
        

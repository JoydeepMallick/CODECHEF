import math

def sieveOfEratosthenes(n):#finds all prime numbers from 2 till n
    primes = [0,0] + [1]*(n-1)
    # 0 and 1 not prime
    p = 2
    while(p**2 <= n):
        if primes[p]:#if true
            for i in range(p**2, n+1, p):#update all multiples of p to 0
                primes[i] = 0;
        p+=1
    return primes

def precompute():
    MAX = 10**6
    ans = {}
    primes = sieveOfEratosthenes(MAX)
    c = 0
    for i in range(2,MAX+1):
        if primes[i] and primes[i-2]:#if n = i then ans[i] 
            c+=1
        ans[i] = c
    return ans



if __name__ == '__main__':
    ans = precompute()
    for T in range(int(input())):
        n = int(input())
       #a,b,c will always be distinct and as a+b = c and all prime numbers except
    #for 2 are are odd hence a has to be 2 always and b always a odd prime and
    # rheir sum will always be distinct odd.
        print(ans[n])


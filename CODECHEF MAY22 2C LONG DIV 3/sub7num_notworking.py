#not working but same concept

M = 10**9 + 7

for T in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    dp = [[0]*7]*(n+1)
    dp[0][0] = 1
    for i in range(n):
        ln = len(str(a[i]))
        p = 1
        while(ln):
            p*=10
            ln-=1
        for j in range(7):
            use = (j*p+a[i]) % 7
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % M
            dp[i+1][use] = (dp[i+1][use] + dp[i][j]) % M
    print((dp[n][0]-1+M) % M)

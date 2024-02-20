import math

def powerOfTwo(n):
    return math.log2(n)

def isPowerOfTwo(n):
    cnt = 0
    while n > 0:
        if n & 1 == 1:
            cnt = cnt + 1
        n = n >> 1
    if cnt == 1 : 
        return 1
    return 0

def gcd(x, y):
    while(y):
       x, y = y, x % y
    return abs(x)

def dfs(ind,par,dics,arr,inter,final):
    counts = arr[ind]
    s = 0
    for i in dics[ind]:
        if i!=par:
            curr = dfs(i,ind,dics,arr,inter,final)
            s += curr
            counts = gcd(counts,curr)
    inter[ind] = counts
    final[ind] = s
    return counts

def find(ind,par,su,dics,arr,inter,final,count):
    count = max(count,su)
    for i in dics[ind]:
        if i!=par:
            count = find(i,ind,su-inter[i]+final[i],dics,arr,inter,final,count)
    return count

for i in range(int(input())):
    n = int(input())  
    a = [int(i) for i in input().split()]
    dics = {}
    inter = [0]*n
    final = [0]*n
    count = 0
    for j in range(n-1):
        u,v = map(int,input().split())
        u-=1
        v-=1
        if u in dics.keys():
            dics[u].append(v)
        else:
            dics[u] = [v]
        if v in dics.keys():
            dics[v].append(u)
        else:
            dics[v] = [u]
    ok = dfs(0,-1,dics,a,inter,final)
    count = find(0,-1,final[0],dics,a,inter,final,count)
    print(count)



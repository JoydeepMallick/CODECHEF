n = int(input())
a = [int(i) for i in input().split()]
rep_ind = []
for i in range(1,n+1):
    if(i == a[i-1]):
        rep_ind.append(i-1)



    

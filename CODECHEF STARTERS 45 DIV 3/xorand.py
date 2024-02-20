'''

'''

for T in range(int(input())):
    n,a,b = map(int, input().split())
    x = 0
    pref = -1
    for i in range(n-1, -1, -1):
        if(((1 << i) & a) > 0 and ((1 << i) & b) > 0):
            continue
        elif(((1 << i) & a) == 0 and ((1 << i) & b) == 0):
            x |= (1 << i)
        else:
            if(pref == -1):
                if(((1 << i) & a) == 0 and ((1 << i) & b) > 0):
                    pref = 0
                else:
                    pref = 0
                    x |= (1 << i)
            else:
                if(((1 << i) & a) == 0 and ((1 << i) & b) > 0):
                    x |= (1 << i)
    print(x)
            

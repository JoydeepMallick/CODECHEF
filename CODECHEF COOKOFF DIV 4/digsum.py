def dsum(n):
    return sum([int(i) for i in list(str(n))])

for i in range(int(input())):
    n = input()
    
    num = int(n)
    if dsum(num) % 2 == 0: # even , need odd pair
        while(True):
            num = num + 1 
            if dsum(num) % 2 == 1:
                break
        print(num)
    else: # odd , need even pair
        while(True):
            num = num + 1
            if dsum(num) % 2 == 0:
                break
        print(num)

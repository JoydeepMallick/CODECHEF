import math

if __name__ == '__main__':
    for T in range(int(input())):
        n = int(input())
        a = [int(i) for i in input().split()]
        u,v,w,x,y = 0,0,0,0,0
        for i in range(0,n):
            if a[i] == 1:
                w+=1
            else:
                if a[i] == 2:
                    v+=1
                x += a[i]
                y+=1
                if a[i] % 2:# odd value
                    u+=1;
        if w == 1:
            if not(u % 2):# same as u%2 == 0
                print("CHEF")
                continue
            if v == 0:
                print("CHEFINA")
                continue
            x-=2
            y-=1
            if (x-y) % 2:
                 print("CHEFINA")
                 continue
            else:
                print("CHEF")
                continue
        elif w > 1:
            if (x-y) % 2:
                print("CHEF")
                continue
            else:
                print("CHEFINA")
                continue
        if u % 2:
            print("CHEF")
            continue
        else:
            print("CHEFINA")
            continue


import math
    
for T in range(int(input())):
    n = int(input())
    f = [int(i) for i in input().split()]#(n+1) terms
    ## generalised formula
    ## let g(n) =  2^(n-1) 
    ## f(n) = (A +- g + B +- g + C +- g)  when n > 0
    ## f (0) = (A + B + C)

    '''
    Here we notice that the when n > 1 the bitness of nth bit(FROM LAST) is
    reversed. that is for n = 2 the bitness of 2nd last bit of each A,B,C is
    reversed.
    4 cases for values of +-g for A,B,C and their sum respectively :-
    
    1. 3  3  3  --> 9
    2. 3  -3  3(other permutations also) --> 3
    3. 3  -3  -3(other permutations also) --> -3
    4. -3  -3  -3 (other permutations also) --> -9

    Hence we can say that if f(n) - f(0) == 9 the nth bit from last was turned on(1).
    i.e. it was off(0) intially in all A,B,C.
    
    Hence we can say that if f(n) - f(0) == -9 the nth bit from last was turned off(0).
    i.e. it was on(1) intially in all A,B,C.

    For other two cases we need to determine their values by repeated checking
    from other values of a[i].


    Hence we can find each bit as 0 and 1 of each A,B,C just by looking and
    repeated testing at the difference between f(n) - f(0) for n > 0.

    '''
    

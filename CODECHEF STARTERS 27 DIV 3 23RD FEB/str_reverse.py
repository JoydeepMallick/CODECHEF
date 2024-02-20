'''
Chef has a string S consisting only of English lowercase letters (a - z). However, Hitesh does not like it and wants it to be reversed.

Hitesh wonders what is the minimum number of operations required to reverse the string S using the following operation:

Select any i such that 1≤i≤|S| and remove Si from its original position and append it to the end of the string (i.e. shift any character to the end of the string).
For e.g. if S= abcde and we apply operation on i=2, then S becomes acdeb.

Help Hitesh find the minimum number of operations required to reverse S.

It is guaranteed that it is possible to reverse the string in a finite number of operations.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line containing the string S.
Output Format
For each test case, output the minimum number of operations required to reverse the string S.

Constraints
1≤T≤103
1≤|S|≤105
Sum of |S| over all testcases does not exceed 2⋅105.
Sample Input 1 
2
abdeba
codechef
Sample Output 1 
3
7
Explanation
Test case-1: Following steps can be performed:
abdeba→abebad
abebad→abeadb
abeadb→abedba
Test case-2: following steps can be performed:
codechef→codechfe
codechfe→codecfeh
codecfeh→codefehc
codefehc→codfehce
codfehce→cofehced
cofehced→cfehcedo
cfehcedo→fehcedoc
'''

##solution

'''
note: no need to work on string simply count
whenever a mismatch ofs and rev_s encountered meaning shift
same elements go untouched
uncommon elements will be shifted such thatthey get placed in reverse order in count steps



simply check elementwise if string and reverse string have same elements

when an unequalelement is encountered increase the count by 1 and the index of string by 1

continue the same till again string and reverse string encounter same element

then only increment counter of reverse element
'''

for i in range(int(input())):
	s=input()
	rev_s=s[::-1]
	i,j=0,0
	count=0
	while(i!=len(s) and j!=(len(rev_s))): # till both reach end
		if s[i]!=rev_s[j]:
			count+=1
			i+=1
		else:
			i+=1
			j+=1
	print(count)
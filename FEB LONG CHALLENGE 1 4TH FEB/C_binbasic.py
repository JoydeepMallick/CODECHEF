
T=int(input())
for i in range(T):
	n,k=map(int, input().split())
	s=input()
	unequal_count=0
	if len(s)==n:
		for i in range(len(s)//2): ## go till half(even length) or mid -1(odd length,its same hence needs no checking)
			if s[i]!=s[-(i+1)]:## checking equality of opposite elements
				unequal_count+=1
		if unequal_count>k:
			print("no")
		elif unequal_count<k:
			if ((k-unequal_count)%2==0 and len(s)%2==0) or len(s)%2==1:
				print("yes")
				'''if either left swaps is even and length of string is even since 2 elements need to be swapped
				or
				if length of s is odd then mid element can be swapped any no of times'''
			else:
				print("no")

		elif unequal_count==k:
			print("yes")


			
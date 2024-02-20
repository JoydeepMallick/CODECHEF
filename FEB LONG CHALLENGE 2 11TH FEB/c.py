
for i in range(int(input())):
	n=int(input())
	a=[int(i) for i in input().split()]
	min_op,i=0,0
	while(i<len(a)):
		if a[i]==i+1:
			a.insert(i,len(a)+10)##at pos i insert any k
			min_op+=1
		##print(a)
		i+=1

	print(min_op)
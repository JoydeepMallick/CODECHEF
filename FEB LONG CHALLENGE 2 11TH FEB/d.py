

# for i in range(int(input())):
# 	n=int(input())
# 	s=[int(i) for i in input()]
# 	print(s)
# 	if len(s)%2==0:#even no of elements
# 		part1,part2=s[:len(s)//2],s[len(s)//2:]
	
# 		print(part1, part2)
# 		if part1==part2 or (part1+part2)==[1 for i in range(len(s)//2)]:#2nd condition for xor value 1
# 			print("yes")
			
# 		else:
# 			p1_0,p1_1=part1.count(0),part1.count(1)
# 			p2_0,p2_1=part2.count(0),part2.count(1)
# 			if (p1_0==p2_0 and p1_1==p2_1) or (p1_0==p2_1 and p1_1==p2_0):
# 				##rearrangemt possible for xor palindrome
# 				print("yes")
				
# 			else:
# 				print("no")#not possible
				
# 	else:#odd no of elements ,in this case always xor value is 0 or false since mid element is the same
# 		part1,part2=s[:len(s)//2],s[(len(s)//2)+1:]
# 		mid=s[len(s)//2]
# 		if part1==part2:##xor value always 0
# 			print("yes")
			
# 		else:
# 			p1_0,p1_1=part1.count(0),part1.count(1)
# 			p2_0,p2_1=part2.count(0),part2.count(1)
# 			#equla no of 1 and 0 prsent in both sides of mid,
# 			#or if only one change needed mid helps--->abs(p1_0-p2_0)==1
# 			#or if total no of zeros on both halfs equals total no of ones on both halves--->(p1_0+p2_0==p1_1+p2_1)
# 			#or if total no of zeros on both halfs and total no of ones on both halves have difference 1 which can be balanced by mid
# 				##rearrangemt possible for xor palindrome

# 			'''if diffreence for last case is 2 , then two possiblities
# 				1. either ele if 1 from any one list goes to mid 0
# 				2. ele 1 from mid goes to any one list with 0 ele
# 				3.an ele from each list is intrchanged in terms of 0 and 1'''
				
# 			if (p1_0==p2_0 and p1_1==p2_1) or abs((p1_0+p2_0)-(p1_1+p2_1)) in [0,1,2]:
# 				print("yes")
				
# 			else:
# 				print("no")#not possible





for i in range(int(input())):
	n=int(input())
	s=[int(i) for i in input()]
	if len(s)==n:
		count0,count1=s.count(0),s.count(1)
		if len(s)%2==0:#even length
			if count0%2==0:#even no of 0 and 1 then ok
				print("yes")
			else:
				print("no")
		else:#odd length
			print("yes")#always xor plain foor any conditon

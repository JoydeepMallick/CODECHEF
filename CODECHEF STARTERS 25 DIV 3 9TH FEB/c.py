
for i in range(int(input())):
	coordinates=[]
	x_count,y_count=0,0##refresh list again for new case
	for i in range(int(input())):
		x,y=map(int, input().split())
		coordinates.append((x,y))
		
	x_count=len(set([p[0] for p in coordinates]))
	y_count=len(set([p[1] for p in coordinates]))
	
	print(x_count+y_count)
import math
import random
import string
import os
import time
import sys
##import metrics wrong name

#import pickle
#import numpy
#import pandas
#import sklearn
#import matplotlib


for i in range(int(input())):
	n,k=map(int, input().split())
	s=input()
	#k guarnteed to  be less than or equal to n

	if k==1: # one single possible combination
		print(s)
	elif k>25: 
		''' 26 alphabets in english hence if 26 or more pieces
		then its obvious that those pices when lexicographially arranged will always be in alphabetical order'''
		lst_s=list(s)
		lst_s.sort()
		s_prime="".join(lst_s)
		print(s_prime)
	else: # if k>1 and k<=25

		#creating the sorted string, might use sorted list also
		sorted_s=list(s)
		sorted_s.sort()
		#temp_compare="".join(lst_s) # sorted string

		s_lst=list(s) # list of s for editing
		j=0
		while(k > 2):
			for i in range(n):
				if s_lst[i]==sorted_s[j]:
					print(s_lst[i],end="")
					j+=1
					s_lst[i]='{' # ascii value -> 125
			k-=1 ## redcuing k

		c,x='z','{'
		bool_values01_for_each_element=[0]*n
		# noting all postions with element smaller than varible c, meaning all the indexex of elemtns not yet printed are noted for further work
		for i in range(n-1, -1, -1):
			if s_lst[i]<=c:
				c=s_lst[i]
				bool_values01_for_each_element[i]=1
		for i in range(n):
			if s_lst[i]=='{' or bool_values01_for_each_element[i]:
				continue # skipping 
				# already used elemnts or elements not yet printed are skipped
			if x=='{':
				x=s_lst[i]
			elif x!=s_lst[i]:
				break
		if s_lst[i] < x:
			x=chr(ord(x)-1) 
		for i in range(n):
			if bool_values01_for_each_element[i] and s_lst[i]<=x:
				print(s_lst[i],end="")
				s_lst[i]='{'
		for ele in s_lst:
			if ele!='{':
				print(ele,end="")

		print() # newline after completing new word



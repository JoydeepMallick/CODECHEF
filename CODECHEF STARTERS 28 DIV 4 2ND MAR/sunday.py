import math
import random
import string
import os
import time
import sys
import metrics

#import pickle
#import numpy
#import pandas
#import sklearn
#import matplotlib


for i in range(int(input())):
	n=int(input())
	a=[int(i) for i in input().split()]

	holidays=8 # fixed holiday
	add_holiday=0
	holiday_list=[i for i in range(1,31) if i%7==0 or (i+1)%7==0]
	
	for i in a:
		if i not in holiday_list:
			add_holiday+=1
	print(holidays+add_holiday)
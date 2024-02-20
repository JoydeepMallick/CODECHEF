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
	c=0
	for i in a:
		if i in range(10,61):
			c+=1
	print(c)
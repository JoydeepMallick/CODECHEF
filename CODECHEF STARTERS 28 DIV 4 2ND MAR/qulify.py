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
	x,a,b=map(int, input().split())
	if (a+2*b)>=x:
		print("Qualify")
	else:
		print("NotQualify")
	
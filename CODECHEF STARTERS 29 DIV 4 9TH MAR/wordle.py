import math
import random
import string
import os
import time
import sys

#import metrics

#import pickle
#import numpy
#import pandas
#import sklearn
#import matplotlib


for i in range(int(input())):
	s=input()
	t=input()

	m=['G' if s[i]==t[i] else "B" for i in range(len(s))]
	print("".join(m))

	
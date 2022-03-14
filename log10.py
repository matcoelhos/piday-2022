from mpmath import *

mp.dps = 20
mp.pretty = False
print(mp)

n = log(mpf(10),b=mpf(2))
nprint(n,20)
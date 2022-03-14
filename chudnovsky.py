from mpmath import *
from time import perf_counter
prec = 31416
maxrounds = int(prec/14)+1

mp.dps = prec
mp.pretty = False
print(mp)

t0 = perf_counter()

C = mpf(426880)*(mpf(10005)**mpf(0.50))

summ = mpf(0)
Lq = mpf(13591409)
Xq = mpf(1)
Mq = mpf(1)
Kq = mpf(-6)

summ += (Mq*Lq)/Xq

const1 = mpf(545140134)
const2 = mpf(-262537412640768000)
const3 = mpf(12)
const4 = mpf(16)
q = mpf(0)

for i in range(1,maxrounds+1):
	q+=1
	Lq += const1
	Xq *= const2
	Kq += const3
	Mq *= (power(Kq,3) - (const4*Kq))/(power(q,3))
	summ += (Mq*Lq)/Xq
	print('Round %d/%d done'%(q,maxrounds),end = '\r')

print()
t = perf_counter() - t0
print('Elapsed time: %.3f seconds'%(t))

pi = C/summ

string = nstr(pi,prec)

file = open('solution.txt','w')
file.write(string)
file.close()

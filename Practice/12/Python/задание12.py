import os
n=int(input())
x=int(1)
y=int(2)
while (n>1):
    x=x*y
    y=y+1
    n=n-1
if (n>=1):
    print (x)
else:
    print ("!! 1 <= n <= 10^9 !!",'\n')
os.system ("pause")

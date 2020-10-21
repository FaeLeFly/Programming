import os
a=int(input())
b=int(input())
c=int(1)
if (b>=0):
    while (b>0):
        c*=a
        b=b-1
else:
    while(b<0):
        c*=a
        b=b+1
    c=1/c
print (c)
os.system ("pause")
     

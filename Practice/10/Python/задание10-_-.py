import os
s,l1,l2,r1,r2=map(int,input().split())
x1=int(l1)
x2=int(0)
if (x1+r2<s):
    x2=r2
    if (s-x2>r1):
        print ("-1")
    else:
        x1=s-r2
else:
    if (l1+l2>s):
        print ("-1")
    else:
        x2=s-x1
if (x1+x2==s):
    print (x1,'\t',x2)
os.system ("pause")

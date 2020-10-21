import os
n=int(input())
y=int(1)
x=int(0)
if (n==0):
    print (x)
else:
    while(y<=n):
        y*=2
        x=x+1
    if (n==y):
        print(x)
    else:
        print (x)
os.system("pause")

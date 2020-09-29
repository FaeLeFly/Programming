import os
a,b,c = map (str,input().split())
if (b=='+'):
    s=float(a)+float(c)
if (b=='-'):
    s=float(a)-float(c)
if (b=='/'):
    s=float(a)/float(c)
if (b=='*'):
    s=float(a)*float(c)
print (s)
os.system ("pause")

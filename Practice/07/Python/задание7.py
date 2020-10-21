import math
import os
num=int(input())
if(num==1):
    a=float(input())
    b=float(input())
    c=float(input())
    p=(a+b+c)/2
    S=math.sqrt(p*(p-a)*(p-b)*(p-c))
    print ("S=",S)
else:
    x1,y1=map(float,input().split())
    x2,y2=map(float,input().split())
    x3,y3=map(float,input().split())
    S = (((x1 - x3) * (y2 - y3)) - ((x2 - x3) * (y1 - y3)))*1/2
    if (S < 0):
        S=S*-1
    print ("S=",S)
os.system ("PAUSE")
        
     
		

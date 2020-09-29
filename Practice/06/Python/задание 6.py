import math
import os
a=(float(input()))
b=(float(input()))
c=(float(input()))
d = b*b-4*a*c;
if d>0 and a!=0 :
    x1=(-b+ math.sqrt(d))/2*a
    x2=(-b- math.sqrt(d))/2*a
    print ("x1=",x1,'\n',"x2=",x2)
else:
        if (a==0 and d>0):
            x1=-1*c/b
            print ("x=",x1)
        else:
         if(d==0):
            x1=-b/(2*a)
            print ("x1=",x1)
         else:
                if(d<0):
                    print ("нет действительных корней")
os.system ("PAUSE")
                    

import os
h1,m1=map(int,input().split(':'))
h2,m2=map(int,input().split(':'))
M1=60*h1+m1
M2=60*h2+m2
if (abs(M1-M2)<16):
    print ("Встреча состоится")
else:
    print ("Встреча не состоится")
os.system("PAUSE")

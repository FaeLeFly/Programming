a=9.8
o=int(0)
x0=int(input("введите x0="))
v0=int(input("введите v0="))
t=int(input("введите t="))
x=x0+v0*t-a*t*t/2
o=abs(x-x0)
print("расстояние=",o)

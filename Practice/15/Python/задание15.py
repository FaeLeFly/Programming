import random
import os
i=int(1)
a=int(1)
count=int(6)
print ("{ГПСЧ}\n")
while (i>0):
    for i in range(a,count):
       magic=random.randint(1,100)
       guess=int(input())
       if (magic==guess):
        print ("Поздравляю! Вы угадали\n Было загадано\t",magic)
        print ("Хотите начать сначала? {1-ДА}")
        da=int(input())
        if (da==1):
            i=1
        else:
              break
       if (magic<guess):
        print ("Загаданное число меньше\n")
       else:
        print("Загаданное число больше\n")
       if (i==5):
        i=0
        print ("Вы проиграли.Было загадано:\t",magic)
        print ("Хотите начать сначала? {1-ДА}")
        da=int(input())
        if (da==1):
            i=1
        else:
            break
os.system ("pause")

        
        
    


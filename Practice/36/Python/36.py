import math
import copy
  
class Point:
    def __init__(self,a1=0,a2=0,coord_system="Cartesian"):
        self.coord_system=coord_system
        self.a2=a2
        self.a1=a1
    def __eq__(self,other):
        x1=self.get_x()
        y1=self.get_y()
        if(math.fabs(x1-self.a1)<10**-10 and math.fabs(y1-self.a2)<10**-10): return True
        return False
    def __ne__(self,other):
        if (__eq__()):return False
        return True
    def __str__(self):
        if type(self.a1) == str:
            return self.a1
        else:
            prrint="("+str(self.a1)+','+str(self.a2)+')'
            return prrint
    def __repr__(self):
        return  self.a1
    def get_x(self):
        if(self.coord_system=="Cartesian"):
            if (type(self.a1)==str):
                texts=self.a1
                left=str.find(texts,'(')
                right=str.find(texts,',')
                self.a1=float(texts[left+1:right])
                left=str.find(texts,',')
                right=str.find(texts,')')
                self.a2=float(texts[left+1:right])
                return self.a1
        return (self.get_r()*math.cos(self.get_phi()))
    def get_y(self):
        if(self.coord_system=="Cartesian"):return self.a2
        return (self.get_r()*math.sin(self.get_phi()))
    def get_r(self):
        if (self.coord_system =="Polar"):return self.a1
        return math.hypot(self.a1, self.a2)
    def get_phi(self):
        if (self.coord_system =="Polar"):return self.a2
        return math.atan2(self.a2, self.a1)
    def set_x(self,x):
        if (self.coord_system =="Cartesian"):
            return
        y = self.get_y()
        self.a1 = x
        self.a2 = y
        self.coord_system ="Cartesian"
    def set_y(self,y):
        if (self.coord_system == 'Cartesian'):
            self.a2 = y
            return
        x = self.get_x()
        self.a1 = x
        self.a2 = y
        self.coord_system ="Cartesian"
    def set_r(self,r):
            if coord_system == Polar:
                self.a1 = r
    def set_phi(self,phi):
        r = self.get_r()
        self.a1 = r
        self.a2 = phi
        self.coord_system ="Polar"

        
        
    
with open('data.txt') as fin:
    original = [Point(p) for p in fin.readline().split(', ')]
simulacrum = copy.deepcopy(original)
for p in simulacrum:
    print (p,end='')
    p.set_x(p.get_x() + 10)
    p.set_phi(p.get_phi() + 180*math.pi/180)
    p.set_y(-p.get_y())
    p.set_x(-p.get_x() - 10)
    print(p)
print('\nIt works!\n' if simulacrum == original else '\nIt not works!\n')
    

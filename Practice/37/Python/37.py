import math
  
def equal(a, b, e=1E-10):
    if -e < a - b < e: return True
    else: return False
  
  
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
  
class Vector:
    def __init__(self,begin=0,end=0):
        
        self.begin=begin
        self.end=end

        self.V=[1,0]
        if (type(end)==int and type(begin)!=int):
            self.V[0]=begin.get_x()
            self.V[1]=begin.get_y()
        elif (type(begin)!=int):
            self.V[0]=end.get_x()-begin.get_x()
            self.V[1]=end.get_y()-begin.get_y()


    def __eq__(self,other):
        return(self.V[0]-other.V[0]<10**-10 and self.V[1]-other.V[1]<10**-10)
    def __neg__(self):
        a=Vector()
        a.V[0]=-self.V[0]
        a.V[1]=-self.V[1]
        return a
    def __add__(self,other):
        b=Vector()
        b.V[0]=self.V[0]+other.V[0]
        b.V[1]=self.V[1]+other.V[1]
        return b
    def __sub__(self,other):
        c=Vector()
        c.V[0]=self.V[0]-other.V[0]
        c.V[1]=self.V[1]-other.V[1]
        return c
    def __mul__(self,other):
        if type(other)!= int:
            H=math.hypot(self.V[0],self.V[1])*math.hypot(other.V[0],other.V[1])*((self.V[0]*other.V[0]+self.V[1]*other.V[1])/(math.hypot(self.V[0],self.V[1])*math.hypot(other.V[0],other.V[1])));
            return H
        else:
            d=Vector()
            d.V[0]=self.V[0]*other
            d.V[1]=self.V[1]*other
            return d
    def length(self):
        H=math.hypot(self.V[0],self.V[1])
        
        return H
  
a = Vector(Point(1, 2))
b = Vector(Point(-2, 0), Point(-1, 2))

if a == b and b == a: print('Equality test passed')
else: print('Equality test failed')

na  = Vector(Point(-1, -2))
ox  = Vector(Point( 1,  0))
nox = Vector(Point(-1,  0))
oy  = Vector(Point( 0,  1))
noy = Vector(Point( 0, -1))
if a == -na and na == -a and -ox == nox and -oy == noy: print('Invert test passed')
else: print('Invert test failed')

if ox + oy + oy == a and -ox == -a + oy + oy: print('Summation test passed')
else: print('Summation test failed')
if -ox + oy == oy - ox and -oy + ox == ox - oy: print('Subtraction test passed')
else: print('Subtraction test failed')
  
if (ox * 3 == ox + ox + ox and
    oy * 3 == oy + oy + oy and
    ox * (-3) == -ox - ox - ox and
    oy * (-3) == -oy - oy - oy): print('Multiplication by number test passed')
else: print('Multiplication by number test failed')
  
if (equal(ox.length(), 1) and
    equal(oy.length(), 1) and
    equal((ox * 3 + oy * 4).length(), 5)): print('Length test passed')
else: print('Length test failed')
  
if (equal(ox*ox, ox.length()**2) and
    equal(oy*oy, oy.length()**2) and
    equal((ox*3 + oy*4)*(ox*3 + oy*4), (ox*3 + oy*4).length()**2)): print('Multiplication by Vector test passed')
else: print('Multiplication by Vector test failed')


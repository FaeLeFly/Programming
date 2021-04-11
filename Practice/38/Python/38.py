import math
  
class Rational:

    def __init__(self,numerator=None,denominator=None):
        if denominator==None and numerator==None:
            self.numerator=0
            self.denominator=0
        if denominator==None:
            self.numerator=numerator
            self.denominator=1
        self.numerator=numerator
        self.denominator=denominator
        if self.numerator <0:
            self.R = -math.inf
        else:
            self.R = math.inf
        if self.denominator !=0:
            self.R=self.numerator/self.denominator
        if self.numerator==0 and self.denominator==0:
            self.R=math.nan

    @staticmethod
    def gcd(numerator,denominator):
        a,b=abs(numerator),abs(denominator)
        num1,num2=max(a,b),min(a,b)
        count,buf=0,0
        while True:
            count=count+1
            if num1%count==0 and num2%count==0: buf=count
            if num1==count: break
            if num2==count: break
        return buf

    def __eq__(self,other):
        if (self.R==other.R):return True
        if (math.fabs(self.R-other.R)<1E-15):return True
        return False

    def isNaN(self):
        if (math.isnan(self.R)): return True
        return False

    def __add__(self,other):
        RR1=Rational(self.R,other.R)
        RR1.R=self.R+other.R
        return RR1

    def __sub__(self,other):
        RR2=Rational(self.R,other.R)
        RR2.R=self.R-other.R
        return RR2

    def __mul__(self,other):
        RR3=Rational(self.R,other.R)
        RR3.R=self.R*other.R
        return RR3

    def __truediv__(self,other):
        RR4=Rational(self.R,other.R)
        RR4cop=Rational(RR4.numerator,RR4.denominator)
        return RR4cop

    def __float__(self):
        return self.R

    def __bool__(self):
        if(self.R==0):return False
        return True
    
    def numerator(self):
        return self.numerator

    def denominator(self):
        return self.denominator

def equal(a, b, e=1E-10):
    if -e < a - b < e: return True
    else: return False

if (Rational.gcd(91, 65) == 13 and
    Rational.gcd(10, 3) == 1 and
    Rational.gcd(-10, 3) == 1 and
    Rational.gcd(10, -3) == 1 and
    Rational.gcd(-10, -3) == 1 and
    Rational.gcd(30, 10) == 10 and
    Rational.gcd(10, 30) == 10 and
    Rational.gcd(0, 10) == 10 and
    Rational.gcd(10, 0) == 10
    ): print('gcd test passed')
else: print('gcd test failed')

if (not Rational(22, 0).isNaN() and
    not Rational(22, 9).isNaN() and
    not Rational(0, 9).isNaN() and
    not Rational(-22, 9).isNaN() and
    not Rational(-22, 0).isNaN() and
    Rational(0, 0).isNaN()
    ): print('isNaN test passed')
else: print('isNaN test failed')

if (Rational(22, 0) == Rational(22, 0) and
    Rational(22, 0) == Rational(9, 0) and
    not(Rational(22, 0) == Rational(22, 9)) and
    not(Rational(22, 0) == Rational(-22, 9)) and
    not(Rational(22, 0) == Rational(-22, 0)) and
    not(Rational(22, 0) == Rational(0, 9)) and
    not(Rational(22, 0) == Rational(0, 0)) and
  
    Rational(22, 9) == Rational(22, 9) and
    Rational(22, 9) == Rational(-22, -9) and
    Rational(22, 9) == Rational(110, 45) and
    Rational(22, 9) == Rational(-110, -45) and
    not(Rational(22, 9) == Rational(-22, 9)) and
    not(Rational(22, 9) == Rational(22, -9)) and
    not(Rational(22, 9) == Rational(9, 22)) and
    not(Rational(22, 9) == Rational(22, 0)) and
    not(Rational(22, 9) == Rational(-22, 0)) and
    not(Rational(22, 9) == Rational(0, 9)) and
    not(Rational(22, 9) == Rational(0, 0)) and
  
    Rational(0, 1) == Rational(0, 1) and
    Rational(0, 1) == Rational(0, 9)  and
    Rational(0, 1) == Rational(0, -9)  and
    not(Rational(0, 1) == Rational(22, 9))  and
    not(Rational(0, 1) == Rational(-22, 9))  and
    not(Rational(0, 1) == Rational(22, 0)) and
    not(Rational(0, 1) == Rational(-22, 0)) and
    not(Rational(0, 1) == Rational(0, 0)) and
  
    Rational(-22, 9) == Rational(-22, 9) and
    Rational(-22, 9) == Rational(22, -9) and
    Rational(-22, 9) == Rational(-110, 45) and
    Rational(-22, 9) == Rational(110, -45) and
    not(Rational(-22, 9) == Rational(-22, -9)) and
    not(Rational(-22, 9) == Rational(22, 9)) and
    not(Rational(-22, 9) == Rational(9, -22)) and
    not(Rational(-22, 9) == Rational(22, 0)) and
    not(Rational(-22, 9) == Rational(-22, 0)) and
    not(Rational(-22, 9) == Rational(0, 9)) and
    not(Rational(-22, 9) == Rational(0, 0)) and
  
    Rational(-22, 0) == Rational(-22, 0) and
    Rational(-22, 0) == Rational(-9, 0) and
    not(Rational(-22, 0) == Rational(22, 9)) and
    not(Rational(-22, 0) == Rational(-22, 9)) and
    not(Rational(-22, 0) == Rational(22, 0)) and
    not(Rational(-22, 0) == Rational(0, 9)) and
    not(Rational(-22, 0) == Rational(0, 0)) and
  
    not(Rational(0, 0) == Rational(0, 0))
    ): print('Equality test passed')
else: print('Equality test failed')

if (Rational(22, 0) + Rational(22, 0) == Rational(22, 0) and
    Rational(22, 9) + Rational(22, 0) == Rational(22, 0) and
    Rational(0, 9) + Rational(22, 0) == Rational(22, 0) and
    Rational(-22, 9) + Rational(22, 0) == Rational(22, 0) and
    (Rational(-22, 0) + Rational(22, 0)).isNaN() and
  
    Rational(22, 0) + Rational(22, 9) == Rational(22, 0) and
    Rational(22, 9) + Rational(22, 9) == Rational(44, 9) and
    Rational(0, 9) + Rational(22, 9) == Rational(22, 9) and
    Rational(-22, 9) + Rational(22, 9) == Rational(0, 9) and
    Rational(-22, 0) + Rational(22, 9) == Rational(-22, 0) and
  
    Rational(22, 0) + Rational(0, 1) == Rational(22, 0) and
    Rational(22, 9) + Rational(0, 1) == Rational(22, 9) and
    Rational(0, 9) + Rational(0, 1) == Rational(0, 9) and
    Rational(-22, 9) + Rational(0, 1) == Rational(-22, 9) and
    Rational(-22, 0) + Rational(0, 1) == Rational(-22, 0) and
  
    Rational(22, 0) + Rational(-22, 9) == Rational(22, 0) and
    Rational(22, 9) + Rational(-22, 9) == Rational(0, 9) and
    Rational(0, 9) + Rational(-22, 9) == Rational(-22, 9) and
    Rational(-22, 9) + Rational(-22, 9) == Rational(-44, 9) and
    Rational(-22, 0) + Rational(-22, 9) == Rational(-22, 0) and
  
    (Rational(22, 0) + Rational(-22, 0)).isNaN() and
    Rational(22, 9) + Rational(-22, 0) == Rational(-22, 0) and
    Rational(0, 9) + Rational(-22, 0) == Rational(-22, 0) and
    Rational(-22, 9) + Rational(-22, 0) == Rational(-22, 0) and
    Rational(-22, 0) + Rational(-22, 0) == Rational(-22, 0) and
  
    (Rational(22, 0) + Rational(0, 0)).isNaN() and
    (Rational(22, 9) + Rational(0, 0)).isNaN() and
    (Rational(0, 9) + Rational(0, 0)).isNaN() and
    (Rational(-22, 9) + Rational(0, 0)).isNaN() and
    (Rational(-22, 0) + Rational(0, 0)).isNaN()
    ): print('Summation test passed')
else: print('Summation test failed')

if ((Rational(22, 0) - Rational(22, 0)).isNaN() and
    Rational(22, 9) - Rational(22, 0) == Rational(-22, 0) and
    Rational(0, 9) - Rational(22, 0) == Rational(-22, 0) and
    Rational(-22, 9) - Rational(22, 0) == Rational(-22, 0) and
    Rational(-22, 0) - Rational(22, 0) == Rational(-22, 0) and
  
    Rational(22, 0) - Rational(22, 9) == Rational(22, 0) and
    Rational(22, 9) - Rational(22, 9) == Rational(0, 9) and
    Rational(0, 9) - Rational(22, 9) == Rational(-22, 9) and
    Rational(-22, 9) - Rational(22, 9) == Rational(-44, 9) and
    Rational(-22, 0) - Rational(22, 9) == Rational(-22, 0) and
  
    Rational(22, 0) - Rational(0, 1) == Rational(22, 0) and
    Rational(22, 9) - Rational(0, 1) == Rational(22, 9) and
    Rational(0, 9) - Rational(0, 1) == Rational(0, 9) and
    Rational(-22, 9) - Rational(0, 1) == Rational(-22, 9) and
    Rational(-22, 0) - Rational(0, 1) == Rational(-22, 0) and
  
    Rational(22, 0) - Rational(-22, 9) == Rational(22, 0) and
    Rational(22, 9) - Rational(-22, 9) == Rational(44, 9) and
    Rational(0, 9) - Rational(-22, 9) == Rational(22, 9) and
    Rational(-22, 9) - Rational(-22, 9) == Rational(0, 9) and
    Rational(-22, 0) - Rational(-22, 9) == Rational(-22, 0) and
  
    Rational(22, 0) - Rational(-22, 0) == Rational(22, 0) and
    Rational(22, 9) - Rational(-22, 0) == Rational(22, 0) and
    Rational(0, 9) - Rational(-22, 0) == Rational(22, 0) and
    Rational(-22, 9) - Rational(-22, 0) == Rational(22, 0) and
    (Rational(-22, 0) - Rational(-22, 0)).isNaN() and
  
    (Rational(22, 0) - Rational(0, 0)).isNaN() and
    (Rational(22, 9) - Rational(0, 0)).isNaN() and
    (Rational(0, 9) - Rational(0, 0)).isNaN() and
    (Rational(-22, 9) - Rational(0, 0)).isNaN() and
    (Rational(-22, 0) - Rational(0, 0)).isNaN()
    ): print('Subtraction test passed')
else: print('Subtraction test failed')

if (Rational(22, 0) * Rational(22, 0) == Rational(22, 0) and
    Rational(22, 9) * Rational(22, 0) == Rational(22, 0) and
    (Rational(0, 9) * Rational(22, 0)).isNaN() and
    Rational(-22, 9) * Rational(22, 0) == Rational(-22, 0) and
    Rational(-22, 0) * Rational(22, 0) == Rational(-22, 0) and
  
    Rational(22, 0) * Rational(22, 9) == Rational(22, 0) and
    Rational(22, 9) * Rational(22, 9) == Rational(22*22, 9*9) and
    Rational(0, 9) * Rational(22, 9) == Rational(0, 9) and
    Rational(-22, 9) * Rational(22, 9) == Rational(-22*22, 9*9) and
    Rational(-22, 0) * Rational(22, 9) == Rational(-22, 0) and
  
    (Rational(22, 0) * Rational(0, 1)).isNaN() and
    Rational(22, 9) * Rational(0, 1) == Rational(0, 9) and
    Rational(0, 9) * Rational(0, 1) == Rational(0, 9) and
    Rational(-22, 9) * Rational(0, 1) == Rational(0, 9) and
    (Rational(-22, 0) * Rational(0, 1)).isNaN() and
  
    Rational(22, 0) * Rational(-22, 9) == Rational(-22, 0) and
    Rational(22, 9) * Rational(-22, 9) == Rational(-22*22, 9*9) and
    Rational(0, 9) * Rational(-22, 9) == Rational(0, 9) and
    Rational(-22, 9) * Rational(-22, 9) == Rational(22*22, 9*9) and
    Rational(-22, 0) * Rational(-22, 9) == Rational(22, 0) and
  
    Rational(22, 0) * Rational(-22, 0) == Rational(-22, 0) and
    Rational(22, 9) * Rational(-22, 0) == Rational(-22, 0) and
    (Rational(0, 9) * Rational(-22, 0)).isNaN() and
    Rational(-22, 9) * Rational(-22, 0) == Rational(22, 0) and
    Rational(-22, 0) * Rational(-22, 0) == Rational(22, 0) and
  
    (Rational(22, 0) * Rational(0, 0)).isNaN() and
    (Rational(22, 9) * Rational(0, 0)).isNaN() and
    (Rational(0, 9) * Rational(0, 0)).isNaN() and
    (Rational(-22, 9) * Rational(0, 0)).isNaN() and
    (Rational(-22, 0) * Rational(0, 0)).isNaN()
    ): print('Multiplication test passed')
else: print('Multiplication test failed')

if ((Rational(22, 0) / Rational(22, 0)).isNaN() and
    Rational(22, 9) / Rational(22, 0) == Rational(0, 9) and
    Rational(0, 9) / Rational(22, 0) == Rational(0, 9) and
    Rational(-22, 9) / Rational(22, 0) == Rational(0, 9) and
    (Rational(-22, 0) / Rational(22, 0)).isNaN() and
  
    Rational(22, 0) / Rational(22, 9) == Rational(22, 0) and
    Rational(22, 9) / Rational(22, 9) == Rational(9, 9) and
    Rational(0, 9) / Rational(22, 9) == Rational(0, 9) and
    Rational(-22, 9) / Rational(22, 9) == Rational(-9, 9) and
    Rational(-22, 0) / Rational(22, 9) == Rational(-22, 0) and
  
    Rational(22, 0) / Rational(0, 1) == Rational(22, 0) and
    Rational(22, 9) / Rational(0, 1) == Rational(22, 0) and
    (Rational(0, 9) / Rational(0, 1)).isNaN() and
    Rational(-22, 9) / Rational(0, 1) == Rational(-22, 0) and
    Rational(-22, 0) / Rational(0, 1) == Rational(-22, 0) and
  
    Rational(22, 0) / Rational(-22, 9) == Rational(-22, 0) and
    Rational(22, 9) / Rational(-22, 9) == Rational(-9, 9) and
    Rational(0, 9) / Rational(-22, 9) == Rational(0, 9) and
    Rational(-22, 9) / Rational(-22, 9) == Rational(9, 9) and
    Rational(-22, 0) / Rational(-22, 9) == Rational(22, 0) and
  
    (Rational(22, 0) / Rational(-22, 0)).isNaN() and
    Rational(22, 9) / Rational(-22, 0) == Rational(0, 9) and
    Rational(0, 9) / Rational(-22, 0) == Rational(0, 9) and
    Rational(-22, 9) / Rational(-22, 0) == Rational(0, 9) and
    (Rational(-22, 0) / Rational(-22, 0)).isNaN() and
  
    (Rational(22, 0) / Rational(0, 0)).isNaN() and
    (Rational(22, 9) / Rational(0, 0)).isNaN() and
    (Rational(0, 9) / Rational(0, 0)).isNaN() and
    (Rational(-22, 9) / Rational(0, 0)).isNaN() and
    (Rational(-22, 0) / Rational(0, 0)).isNaN()
    ): print('Division test passed')
else: print('Division test failed')
  
if (equal(float(Rational(-22, -9)), 22/9.0) and
    equal(float(Rational(-9, -9)), 1) and
    equal(float(Rational(-6, -9)), 6/9.0) and
    equal(float(Rational(0, -9)), 0) and
    equal(float(Rational(6, -9)), -6/9.0) and
    equal(float(Rational(9, -9)), -1) and
    equal(float(Rational(22, -9)), -22/9.0) and
    math.isinf(float(Rational(-9, 0))) and
    math.isnan(float(Rational(0, 0))) and
    math.isinf(float(Rational(9, 0))) and
    equal(float(Rational(-22, 9)), -22/9.0) and
    equal(float(Rational(-9, 9)), -1) and
    equal(float(Rational(-6, 9)), -6/9.0) and
    equal(float(Rational(0, 9)), 0) and
    equal(float(Rational(6, 9)), 6/9.0) and
    equal(float(Rational(9, 9)), 1) and
    equal(float(Rational(22, 9)), 22/9.0)
    ): print('Conversion to double test passed')
else: print('Conversion to double test failed')
  
if (bool(Rational(-22, -9)) and
    bool(Rational(-9, -9)) and
    bool(Rational(-6, -9)) and
    not bool(Rational(0, -9)) and
    bool(Rational(6, -9)) and
    bool(Rational(9, -9)) and
    bool(Rational(22, -9)) and
    bool(Rational(-9, 0)) and
    bool(Rational(0, 0)) and
    bool(Rational(9, 0)) and
    bool(Rational(-22, 9)) and
    bool(Rational(-9, 9)) and
    bool(Rational(-6, 9)) and
    not bool(Rational(0, 9)) and
    bool(Rational(6, 9)) and
    bool(Rational(9, 9)) and
    bool(Rational(22, 9))
    ): print('Conversion to bool test passed')
else: print('Conversion to bool test failed')


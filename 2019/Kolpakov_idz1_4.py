from math import gcd 


class Fraction:
    """ Fraction class """
    def __init__(self, nominator=0, denominator=1):
        self.nom = nominator
        self.den = denominator
    
    def negative(self):
        self.nom *= -1

    def add_int(self, n):
        self.nom += n * self.den
    
    def add(self, second_Fract):
        lcm = self.den * second_Fract.den // gcd(self.den, second_Fract.den)
        self.nom *= lcm // self.den
        self.nom += lcm // second_Fract.den * second_Fract.nom
        self.den = lcm 

    def flip(self):
        self.den, self.nom = self.nom, self.den

    def op(self):
        return Fraction(self.den, self.nom)

    def show(self):
        print("{}/{}".format(self.nom, self.den))
    
    def value(self):
        return self.nom / self.den 


class FractRad:
    """ chain fraction class """
    def __init__(self, list):
        self.reg = list

    def value(self, i):
        return self.reg[i % len(self.reg)]

    def approx(self,n ):
        sum = Fraction(nominator=self.value(n-1)).op()
        for i in range(n-2, -1, -1):
            sum.add_int(self.value(i))
            sum.flip()
        return sum


def main():
    rad_chain = FractRad(list(map(int, input('Enter numbers seq:\n').split())))
    n = int(input('Enter approx number:\n'))
    prev = Fraction()
    for i in range(1,n):
        print('p{}/q{}:\t'.format(i, i), end='')
        next = rad_chain.approx(i)
        next.show()
        #print('delta:\t', end='')
        #prev.negative()
        #prev.add(next)
        #print(prev.value(),'\n')
        

main()

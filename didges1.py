def main():
    inp = float(input())
    
    sign = str(0 if inp>= 0 else 1)
    inp = inp if inp>= 0 else -inp
    
    int_p = bin(int(inp))[3:]
    order_1 = bin(len(int_p) + 127)[2:]
    order_2 = bin(len(int_p) + 1023)[2:]
    
    inp -= int(inp)
    mantissa = int_p
    for _ in range(44):
        inp *= 2
        mantissa += str(int(inp))
        inp -= int(inp)
    
    print(sign + '|' + order_1 + '|' + mantissa[:23]) 
    print(sign + '|' + order_2 + '|' + mantissa[:52]) 


main()

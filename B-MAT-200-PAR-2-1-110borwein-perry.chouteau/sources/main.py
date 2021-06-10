#!/usr/bin/env python3

import math as m
import string as t
import sys as s

def borweinIntegral(indexN, valueX): #(a+b)/2 = X:a = 0 -> 5000: b = (a + 0.5):
    res = 1.0
    if valueX == 0:
        s.exit(84)
    for k in range(indexN + 1):
        if k == -0.5:
            s.exit(84)
        res *= (m.sin(valueX / (2 * k + 1)) / (valueX / (2 * k + 1)))
    return res

def diff(value):
    return abs(value - (m.pi / 2))

#----------------------------------- 3 PARTS OF BORWEIN -----------------------------------

def midpoint(n):
    print("Midpoint:")
    res = 0.0
    for i in range(0, 10000):
        a = (i / 2)
        b = (a + 0.5)
        res += (b - a) * borweinIntegral(n, (a + b) / 2)
    print("I" "%i" % n, "=", "%.10f" % res)
    print("diff =", "%.10f" % diff(res))
    return 0

def trapezoidal(n):
    print("\nTrapezoidal:")
    res = 0.0
    
    for i in range(0, 10000):
        if i == 0:
            a = (i / 2) + 0.00000000001
        else:
            a = (i / 2)
        b = (a + 0.5)
        res += ((b - a) / 2) * (borweinIntegral(n, a) + borweinIntegral(n, b))
    print("I" "%i" % n, "=", "%.10f" % res)
    print("diff =", "%.10f" % diff(res))
    return 0

def simpson(n):
    print("\nSimpson:")
    res = 0
    for i in range(0, 10000):
        if i == 0:
            a = (i / 2) + 0.00000000001
        else:
            a = (i / 2)
        b = a + 0.5
        res += ((b - a) / 6) * (borweinIntegral(n, a) + (4 * borweinIntegral(n, (a + b) / 2)) + borweinIntegral(n, b))

    print("I" "%i" % n, "=", "%.10f" % res)
    print("diff =", "%.10f" % diff(res))
    return 0

#----------------------------------- BORWEIN -----------------------------------

def borwein(n):
    midpoint(int(n))
    trapezoidal(int(n))
    simpson(int(n))
    s.exit(0)

#----------------------------------- ERROR -----------------------------------

def error(ac, av):
    if "-h" in av:
        print("USAGE")
        print("\t./110borwein n")
        print("DESCRIPTION")
        print("\tn\tconstant defining the integral to be computed")
        s.exit(1)
    if (ac) != 2:
        s.exit(84)
    try:
        int(av[1])
    except ValueError:
        s.exit(84)
    if int(av[1]) < 0:
        s.exit(84)

#------------------------------------ MAIN -----------------------------------

def main():
    error(len(s.argv), s.argv)
    borwein(s.argv[1])

if __name__ == "__main__":
    main()

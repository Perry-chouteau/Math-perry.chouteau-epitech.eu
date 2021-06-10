#!/usr/bin/env python3

import math as m
import string as t
import sys as s

#----------------------------------- EQUIVALENT POINT -----------------------------------

def f_ep(derivOne):
    tmp = derivOne[0]
    ep = 0
    for x in range(0, len(derivOne)):
        if tmp[1] < derivOne[x][1]:
            tmp = derivOne[x]
            ep = x
    return ep

def f_invep(derivateTwoEstimate):
    tmp = derivateTwoEstimate[0]
    inv_ep = 0
    for x in range(0, len(derivateTwoEstimate)):
        if abs(tmp[1]) >  abs(derivateTwoEstimate[x][1]):
            tmp = derivateTwoEstimate[x]
            inv_ep = x
    return inv_ep

#----------------------------------- RATE OF CHANGE -----------------------------------

def f_roc(vol0, vol1, ph0, ph1):
    top = (ph0 - ph1)
    bottom = (vol0 - vol1)
    if (vol0 - vol1) == 0:
        s.exit(0)
    return ((ph0 - ph1) / (vol0 - vol1))

#----------------------------------- CALC 1.0 -----------------------------------

def derivate(values):
    derivOne = [[0 for x in range(0, 2)] for y in range(0, len(values) -2)]
    for x in range(1, len(values) -1):
        backward = f_roc(values[x][0], values[x - 1][0], values[x][1], \
values[x - 1][1])
        forward = f_roc(values[x + 1][0], values[x][0], values[x + 1][1], \
values[x][1])
        top = ((forward * (values[x][0] - values[x - 1][0])) + \
(backward * (values[x + 1][0] - values[x][0])))
        bottom = ((values[x][0] - values[x -1][0]) + \
(values[x + 1][0] - values[x][0]))
        derivOne[x - 1][0] = values[x][0]
        if bottom == 0:
            s.exit(0)
        derivOne[x - 1][1] = (top / bottom)
    return derivOne

def derivateTwoEstimated(derivTwo, ep):
    previous = derivTwo[ep - 1]
    actual = derivTwo[ep]
    subsequent = derivTwo[ep + 1]
    pre_bottom = 0
    sub_bottom = 0
    for x in range(int(previous[0] * 10), int(actual[0] * 10)):
        pre_bottom += 1
    for x in range(int(actual[0] * 10), int(subsequent[0] * 10)):
        sub_bottom += 1
    bottom = pre_bottom + sub_bottom
    derivTwoEstimate = [[0 for x in range(0, 2)] for y in range(0, bottom + 1)]
    pre_estimated = ( actual[1] - previous[1]) / (pre_bottom)
    sub_estimated = ( subsequent[1] - actual[1]) / (sub_bottom)
    derivTwoEstimate[0] =  derivTwo[ep - 1]
    for x in range(1, pre_bottom):
        derivTwoEstimate[x][0] = derivTwoEstimate[x -1][0] + 0.1
        derivTwoEstimate[x][1] = derivTwoEstimate[x -1][1] + pre_estimated
    derivTwoEstimate[ep] =  derivTwo[ep]
    for x in range(pre_bottom +1, pre_bottom + sub_bottom):
        derivTwoEstimate[x][0] = derivTwoEstimate[x -1][0] + 0.1
        derivTwoEstimate[x][1] = derivTwoEstimate[x -1][1] + sub_estimated
    derivTwoEstimate[bottom] =  derivTwo[ep + 1]
    return derivTwoEstimate


def print_derivOneEp(derivOne, ep):
    print("Derivative:")
    for x in range(0, len(derivOne) - 1):
        print("%.1f" % derivOne[x][0], "ml ->" ,"%.2f" % derivOne[x][1])
    print(end='\n')
    print("Equivalence point at", "%.1f" % derivOne[ep][0], "ml")

def print_derivTwo(derivTwo):
    print(end='\n')
    print("Second derivative:")
    for x in range(0, len(derivTwo) - 1):
        print("%.1f" % derivTwo[x][0], "ml ->", "%.2f" % derivTwo[x][1])

def print_derivTwoEstimateInvep(derivTwoEstimate, inv_ep):
    print(end='\n')
    print("Second derivative estimated:")
    for x in range(0, len(derivTwoEstimate)):
        print("%.1f" % derivTwoEstimate[x][0], "ml ->", "%.2f" % derivTwoEstimate[x][1])
    print(end='\n')
    print("Equivalence point at", "%.1f" % derivTwoEstimate[inv_ep][0], "ml")

#----------------------------------- TITRATION -----------------------------------

def init(av):
    tab = open(av[1], "r").read().split("\n")
    size = len(tab)
    values = [[0 for x in range(0, 2)] for y in range(0, size)]
    for x in range(0, size -1):
        tab2 = tab[x].split(";")
        if len(tab2) != 2:
            if x < size:
                s.exit(84)
        try:
            values[x][0] = float(tab2[0])
            values[x][1] = float(tab2[1])
        except ValueError:
            s.exit(84)
    for x in range(0, len(values)):
        if values[x][0] < 0 or values[x][1] < 0:
            s.exit(84)
    
    for x in range(0, len(values)):
        for y in range(0, len(values)):
            if x != y and values[x][0] == values[y][0]:
                s.exit(84)
    return values

def titration(av):
    values = init(av)
    if len(values) < 7:
        s.exit(84)
    derivOne = derivate(values)
    ep = f_ep(derivOne)
    print_derivOneEp(derivOne, ep)
    if ep <= 1 or ep >= len(derivOne) - 1:
        s.exit(0)
    derivTwo = derivate(derivOne)
    print_derivTwo(derivTwo)
    if ep == 0 or ep == len(derivTwo):
        s.exit(0)
    derivTwoEstimate = derivateTwoEstimated(derivTwo, ep - 1)
    inv_ep = f_invep(derivTwoEstimate)
    print_derivTwoEstimateInvep(derivTwoEstimate, inv_ep)
    s.exit(0)

#----------------------------------- ERROR -----------------------------------

def error(ac, av):
    if "-h" in av:
        print("USAGE")
        print("\t./109titration file")
        print("DESCRIPTION")
        print("\tfile\ta csv file containing \"vol;ph\" lines")
        s.exit(1)
    if (ac) != 2:
        s.exit(84)

#------------------------------------ MAIN -----------------------------------

def main():
    error(len(s.argv), s.argv)
    titration(s.argv)
    return 0

if __name__ == "__main__":
    main()
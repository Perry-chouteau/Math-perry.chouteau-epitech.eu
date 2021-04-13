#!/usr/bin/env python3

import math as m
import string as t
import sys as s

#----------------------------------- MATRIX CALC 1.0 -----------------------------------

def matrixAdd(matrixOne, matrixTwo):
    size = len(matrixOne)
    result = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            result[i][j] = 0
    for i in range(0, size):
        for j in range(0, size):
            result[i][j] = matrixOne[i][j] + matrixTwo[i][j]
    return result;

def matrixSub(matrixOne, matrixTwo):
    size = len(matrixOne)
    result = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            result[i][j] = 0
    for i in range(0, size):
        for j in range(0, size):
            result[i][j] = matrixOne[i][j] - matrixTwo[i][j]
    return result;

def matrixMult(matrixOne, matrixTwo):
    size = len(matrixOne)
    result = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            result[i][j] = 0
    for i in range(0, size):
        for j in range(0, size):
            for l in range(0, size):
                result[i][j] += matrixOne[i][l] * matrixTwo[l][j]
    return result;

def matrixDiv(matrixOne, matrixTwo):
    size = len(matrixOne)
    result = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            result[i][j] = 0
    for i in range(0, size):
        for j in range(0, size):
                result[i][j] += matrixOne[i][j] / matrixTwo[i][j]
    return result;

#----------------------------------- MATRIX CALC 2.0 -----------------------------------

def matrixPow(matrix, n):
    size = len(matrix)
    result = matrix

    for i in range(1, n):
        result = matrixMult(result, matrix)
    return result;

#----------------------------------- FUNC -----------------------------------

def myExp(matrixSave):
    size = len(matrixSave)
    result = [[0 for x in range(0, size)] for y in range(0, size)]
    factorial = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            if j == i:
                result[i][j] = 1
            else:
                result[i][j] = 0
    for i in range(1, 50):
        for j in range(0, size):
            for k in range(0, size):
                factorial[j][k] = m.factorial(i)
        result = matrixAdd(result, matrixDiv(matrixPow(matrixSave, i), factorial))
    return result;

def myCos(matrixSave):
    size = len(matrixSave)
    result = [[0 for x in range(0, size)] for y in range(0, size)]
    factorial = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            if j == i:
                result[i][j] = 1
            else:
                result[i][j] = 0

    for i in range(1, 40):
            if i % 2 == 0:
                for j in range(0, size):
                    for k in range(0, size):
                        factorial[j][k] = m.factorial(2 * i)
                result = matrixAdd(result, matrixDiv(matrixPow(matrixSave, 2 * i), factorial))
            else:
                for j in range(0, size):
                    for k in range(0, size):
                        factorial[j][k] = m.factorial(2 * i)
                result = matrixSub(result, matrixDiv(matrixPow(matrixSave, 2 * i), factorial))
    return result;

def mySin(matrixSave):
    size = len(matrixSave)
    result = [[0 for x in range(0, size)] for y in range(0, size)]
    factorial = [[0 for x in range(0, size)] for y in range(0, size)]
    result = matrixSave

    for i in range(1, 40):
            if i % 2 == 0:
                for j in range(0, size):
                    for k in range(0, size):
                        factorial[j][k] = m.factorial(2 * i + 1)
                result = matrixAdd(result, matrixDiv(matrixPow(matrixSave, 2 * i + 1), factorial))
            else:
                for j in range(0, size):
                    for k in range(0, size):
                        factorial[j][k] = m.factorial(2 * i + 1)
                result = matrixSub(result, matrixDiv(matrixPow(matrixSave, 2 * i + 1), factorial))
    return result;

def myCosh(matrixSave):
    size = len(matrixSave)
    result = [[0 for x in range(0, size)] for y in range(0, size)]
    factorial = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            if j == i:
                result[i][j] = 1
            else:
                result[i][j] = 0
    for i in range(1, 40):
        for j in range(0, size):
            for k in range(0, size):
                factorial[j][k] = m.factorial(2 * i)
        result = matrixAdd(result, matrixDiv(matrixPow(matrixSave, 2 * i), factorial))
    return result;

def mySinh(matrixSave):
    size = len(matrixSave)
    result = [[0 for x in range(0, size)] for y in range(0, size)]
    factorial = [[0 for x in range(0, size)] for y in range(0, size)]
    result = matrixSave
    
    for i in range(1, 40):
        for j in range(0, size):
            for k in range(0, size):
                factorial[j][k] = m.factorial(2 * i + 1)
        result = matrixAdd(result, matrixDiv(matrixPow(matrixSave, 2 * i + 1), factorial))
    return result;

#----------------------------------- TRIGO -----------------------------------

def trigo(ac, av):
    size = int(m.sqrt(ac - 2))
    matrixSave = [[0 for x in range(0, size)] for y in range(0, size)]
    matrix = [[0 for x in range(0, size)] for y in range(0, size)]

    for i in range(0, size):
        for j in range(0, size):
            matrixSave[i][j] = int(av[(i * size) + j + 2])
            matrix[i][j] = 0

    if "SIN" == av[1] or "SINH" == av[1]:
        if "SIN" == av[1]:
            matrix = mySin(matrixSave)
        else:
            matrix = mySinh(matrixSave)
    elif "COS" == av[1] or "COSH" == av[1]:
        if "COS" == av[1]:
            matrix = myCos(matrixSave)
        else:
            matrix = myCosh(matrixSave)
    else:
        if "EXP" == av[1]:
            matrix = myExp(matrixSave)
        else:
            s.exit(84);
    for i in range(0, size):
        for j in range(0, size - 1):
            print("%.2f" % matrix[i][j], end='\t')
        print("%.2f" % matrix[i][size - 1])
    s.exit(0);

#----------------------------------- ERROR -----------------------------------

def error(ac, av):
    if "-h" in av:
        print("USAGE")
        print("\t./108trigo fun a0 a1 a2 ...")
        print("DESCRIPTION")
        print("\tfun\tfunction to be applied, among at least “EXP”, “COS”, “SIN”, “COSH”\n\t\tand “SINH”")
        print("\tai\tcoeficients of the matrix")
        s.exit(1)
    if (ac) < 3:
        s.exit(84)
    if int(m.sqrt(ac - 2)) * int(m.sqrt(ac - 2)) != (ac - 2):
        s.exit(84)
    try:
        for i in range(2, ac):
            int(av[i])
    except ValueError:
        s.exit(84)

#------------------------------------ MAIN -----------------------------------

def main():
    error(len(s.argv), s.argv)
    trigo(len(s.argv), s.argv)
    return 0

if __name__ == "__main__":
    main()
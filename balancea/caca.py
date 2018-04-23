'''
Created on 23/04/2018

@author: ernesto
'''
import sys
import os

lines = None
lee_linea_g = None


def lee_linea_gen():
    global lines
    if not lines:
        lines = os.read(0, 10 ** 6).strip().splitlines() 
#    return input()
#    return sys.stdin.readline()
    for x in lines:
        line = x.decode('utf-8')  # convert bytes-like object to string
        yield line


def lee_linea():
    global lee_linea_g
    if not lee_linea_g:
        lee_linea_g = lee_linea_gen()
    return next(lee_linea_g)


def balance(a):
    a_len = len(a)
    c = [0] * a_len
    a_sum = sum(a)
    r = -1
    if not(a_sum % a_len):
        r = 0
        avg = a_sum // a_len
        a = list(map(lambda x:x - avg, a))
#        print("a {} avg {}".format(a, avg))
        for i in range(a_len - 1):
            c[i + 1] = c[i] + a[i] 
#        print("c {}".format(c))
        
        r = max(map(lambda x:abs(x), c))
    return r


tmp = lee_linea().strip()
while not tmp:
    tmp = lee_linea().strip()
n = int(tmp)
while n != -1:
    tmp = lee_linea().strip()
    while not tmp:
        tmp = lee_linea().strip()
        
    a = [int(x) for x in " ".join(tmp.split()).strip().split(" ")]
#    print(a)
    r = balance(a)
    print(r)
    tmp = lee_linea().strip()
    while not tmp:
        tmp = lee_linea().strip()
    n = int(tmp)

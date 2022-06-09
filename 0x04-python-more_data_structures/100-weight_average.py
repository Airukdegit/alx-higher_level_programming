#!/usr/bin/python3
def weight_average(my_list=[]):
    if not my_list:
        return 0
    avrge = 0
    dvsr = 0
    for i in my_list:
        avrge += i[0] * i[1]
        dvsr += i[1]
    return float(avrge / dvsr)


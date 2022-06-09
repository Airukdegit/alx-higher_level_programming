#!/usr/bin/python3
if __name__ == "__main__":
    from hidden_4 import *
    arr = dir()
    for num in range(0, len(arr)):
        if arr[num][0:2] != "__":
            print("{}".format(arr[num]))


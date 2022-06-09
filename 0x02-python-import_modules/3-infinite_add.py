#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    rslt = 0
    for i in range(1, len(sys.argv)):
        rslt += int(sys.argv[i])
    print("{}".format(rslt))


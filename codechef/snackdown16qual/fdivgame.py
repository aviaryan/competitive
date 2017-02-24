ls = [10, 9]
nm = 0
m = 0


def turn(lis, move):
    global nm, m

    if len(lis) == 0:
        if not move:
            nm += 1
        else:
            m += 1

    for i in range(len(lis)):
        b = lis[i]
        for j in [2, 3, 4, 5, 6]:
            lisc = lis[:]
            lisc[i] = b / j
            if lisc[i] == 0:
                del lisc[i]
            turn(lisc, not move)


def turn_master(lis):
    global nm, m
    for i in range(len(lis)):
        for j in [2, 3, 4, 5, 6]:
            nm = m = 0
            lisc = lis[:]
            lisc[i] = lisc[i] / j
            if lisc[i] == 0:
                del lisc[i]
            turn(lisc, False)
            print nm, m


turn_master(ls)

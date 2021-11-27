from matplotlib import pyplot as PLT

PLT.clf()

f_1 = PLT.figure(1)

x1 = []
y1 = []
z1 = []
f = open("random_output.txt", "r")
with open('random_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x1.append(int(coordinates[0]))
        y1.append(float(coordinates[1]))
        z1.append(int(coordinates[2]))
PLT.plot(x1, y1)
PLT.title('Random Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_1.savefig('random.png')

PLT.clf()
f_2 = PLT.figure(1)

x2 = []
y2 = []
z2 = []
f = open("optimal_output.txt", "r")
with open('optimal_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x2.append(int(coordinates[0]))
        y2.append(float(coordinates[1]))
        z2.append(int(coordinates[2]))
PLT.plot(x1, y2,label="optimal")
PLT.title('Optimal Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_2.savefig('optimal.png')


PLT.clf()
f_3 = PLT.figure(1)

x3 = []
y3 = []
z3 = []
f = open("nru_output.txt", "r")
with open('nru_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x3.append(int(coordinates[0]))
        y3.append(float(coordinates[1]))
        z3.append(int(coordinates[2]))
PLT.plot(x3, y3,label="nru")

PLT.title('NRU Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_3.savefig('nru.png')


PLT.clf()
f_4 = PLT.figure(1)

x4 = []
y4 = []
z4 = []
f = open("fifo_output.txt", "r")
with open('fifo_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x4.append(int(coordinates[0]))
        y4.append(float(coordinates[1]))
        z4.append(int(coordinates[2]))
PLT.plot(x4, y4,label="fifo")

PLT.title('FIFO Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_4.savefig('fifo.png')

PLT.clf()
f_5 = PLT.figure(1)

x5 = []
y5 = []
z5 = []
f = open("fifo2nd_output.txt", "r")
with open('fifo2nd_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x5.append(int(coordinates[0]))
        y5.append(float(coordinates[1]))
        z5.append(int(coordinates[2]))
PLT.plot(x5, y5,label="fifo_2nd")

PLT.title('FIFO 2nd Chance Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_5.savefig('fifo_2nd.png')


PLT.clf()
f_6 = PLT.figure(1)

x6 = []
y6 = []
z6 = []
f = open("clock_output.txt", "r")
with open('clock_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x6.append(int(coordinates[0]))
        y6.append(float(coordinates[1]))
        z6.append(int(coordinates[2]))
PLT.plot(x6, y6,label="clock")

PLT.title('Clock Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_5.savefig('clock.png')

PLT.clf()
f_7 = PLT.figure(1)

x7 = []
y7 = []
z7 = []
f = open("lru_output.txt", "r")
with open('lru_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x7.append(int(coordinates[0]))
        y7.append(float(coordinates[1]))
        z7.append(int(coordinates[2]))
PLT.plot(x7, y7,label="lru")

PLT.title('LRU Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_7.savefig('lru.png')

PLT.clf()
f_8 = PLT.figure(1)

x8 = []
y8 = []
z8 = []
f = open("nfu_output.txt", "r")
with open('nfu_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x8.append(int(coordinates[0]))
        y8.append(float(coordinates[1]))
        z8.append(int(coordinates[2]))
PLT.plot(x8, y8,label="nfu")

PLT.title('NFU Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_8.savefig('nfu.png')

PLT.clf()
f_9 = PLT.figure(1)

x9 = []
y9 = []
z9 = []
f = open("workingset_output.txt", "r")
with open('workingset_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x9.append(int(coordinates[0]))
        y9.append(float(coordinates[1]))
        z9.append(int(coordinates[2]))
PLT.plot(x9, y9,label="workingset")

PLT.title('Working Set Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_9.savefig('workingset.png')

PLT.clf()
f_10 = PLT.figure(1)

x10 = []
y10 = []
z10 = []
f = open("aging_output.txt", "r")
with open('aging_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x10.append(int(coordinates[0]))
        y10.append(float(coordinates[1]))
        z10.append(int(coordinates[2]))
PLT.plot(x10, y10,label="aging")

PLT.title('Aging Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_10.savefig('aging.png')

PLT.clf()
f_11 = PLT.figure(1)

x11 = []
y11 = []
z11 = []
f = open("wsclock_output.txt", "r")
with open('wsclock_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x11.append(int(coordinates[0]))
        y11.append(float(coordinates[1]))
        z11.append(int(coordinates[2]))
PLT.plot(x11, y11,label="wsclock")

PLT.title('WSClock Page Replacement Algorithm',fontsize=16)
PLT.xlabel('No. of frames',fontsize=14)
PLT.ylabel('Miss Ratio',fontsize=14)

f_11.savefig('wsclock.png')

PLT.clf()
f_12 = PLT.figure(1)

PLT.plot(x1, y1, label="random")
PLT.plot(x2, y2,  label="optimal")
PLT.plot(x3, y3,  label="nru")
PLT.plot(x4, y4,  label="fifo")
PLT.plot(x5, y5,  label="fifo_2nd")
PLT.plot(x6, y6,  label="clock")
PLT.plot(x7, y7, label="lru")
PLT.plot(x8, y8,  label="nfu")
PLT.plot(x9, y9,  label="workingset")
PLT.plot(x10, y10,  label="aging")
PLT.plot(x11, y11,  label="wsclock")
PLT.ylabel('Miss Ratio')

PLT.xlabel('No. of frames')

PLT.title('Page Replacement Simulation')

PLT.legend(loc='best')


PLT.savefig('graph_all.png')

PLT.clf()
f_12 = PLT.figure(1)

PLT.plot(x1, z1, label="random")
PLT.plot(x2, z2,  label="optimal")
PLT.plot(x3, z3,  label="nru")
PLT.plot(x4, z4,  label="fifo")
PLT.plot(x5, z5,  label="fifo_2nd")
PLT.plot(x6, z6,  label="clock")
PLT.plot(x7, z7, label="lru")
PLT.plot(x8, z8,  label="nfu")
PLT.plot(x9, z9,  label="workingset")
PLT.plot(x10, z10,  label="aging")
PLT.plot(x11, z11,  label="wsclock")
PLT.ylabel('No. of swaps')

PLT.xlabel('No. of frames')

PLT.title('Page Replacement Simulation (Swaps Vs Frames)')

PLT.legend(loc='best')

PLT.savefig('graph_swaps.png')
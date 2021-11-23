from matplotlib import pyplot as PLT

fig = PLT.figure()

plt = fig.add_subplot(211)

plt1 = fig.add_subplot(212)

x = []
y = []
z = []
f = open("random_output.txt", "r")
with open('random_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y)
plt1.plot(x, z, label="random")

x = []
y = []
z = []
f = open("optimal_output.txt", "r")
with open('optimal_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="optimal")
plt1.plot(x, z,label="optimal")

x = []
y = []
z = []
f = open("nru_output.txt", "r")
with open('nru_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="nru")
plt1.plot(x, z,label="nru")

x = []
y = []
z = []
f = open("fifo_output.txt", "r")
with open('fifo_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="fifo")
plt1.plot(x, z,label="fifo")

x = []
y = []
z = []
f = open("fifo2nd_output.txt", "r")
with open('fifo2nd_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="fifo_2nd")
plt1.plot(x, z,label="fifo_2nd")

x = []
y = []
z = []
f = open("clock_output.txt", "r")
with open('clock_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="clock")
plt1.plot(x, z,label="clock")

x = []
y = []
z = []
f = open("lru_output.txt", "r")
with open('lru_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="lru")
plt1.plot(x, z,label="lru")

x = []
y = []
z = []
f = open("nfu_output.txt", "r")
with open('nfu_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="nfu")
plt1.plot(x, z,label="nfu")

x = []
y = []
z = []
f = open("workingset_output.txt", "r")
with open('workingset_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
        z.append(int(coordinates[2]))
plt.plot(x, y,label="workingset")
plt1.plot(x, z,label="workingset")


plt.set_ylabel('Miss Ratio')

plt1.set_xlabel('No. of frames')
plt1.set_ylabel('No. of swaps')



plt.set_title('Page Replacement Simulation')
'''PLT.xlabel('No. of frames')
PLT.ylabel('Miss Ratio')
#PLT.title('Page Replacement Simulation')'''
PLT.legend(loc='best')

'''plt1.xlabel('No. of frames')
plt1.ylabel('No. of swaps')
plt1.legend(loc='best')'''

#plt.show()
#plt1.show()

PLT.savefig('graph1.png')

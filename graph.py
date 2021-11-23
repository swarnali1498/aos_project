import matplotlib.pyplot as plt
x = []
y = []
f = open("random_output.txt", "r")
with open('random_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="random")

x = []
y = []
f = open("optimal_output.txt", "r")
with open('optimal_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="optimal")

x = []
y = []
f = open("nru_output.txt", "r")
with open('nru_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="nru")

x = []
y = []
f = open("fifo_output.txt", "r")
with open('fifo_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="fifo")

x = []
y = []
f = open("fifo2nd_output.txt", "r")
with open('fifo2nd_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="fifo_2nd")

x = []
y = []
f = open("lru_output.txt", "r")
with open('lru_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="lru")

x = []
y = []
f = open("nfu_output.txt", "r")
with open('nfu_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="nfu")

x = []
y = []
f = open("workingset_output.txt", "r")
with open('workingset_output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y,label="workingset")


plt.xlabel('No. of frames')
plt.ylabel('Miss Ratio')
plt.title('Page Replacement Simulation')
plt.show()
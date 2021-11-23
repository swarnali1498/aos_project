import matplotlib.pyplot as plt
x = []
y = []
f = open("output.txt", "r")
with open('output.txt') as f:
    lines = f.readlines()
    for line in lines:
        coordinates = line.split(',')
        x.append(int(coordinates[0]))
        y.append(float(coordinates[1]))
plt.plot(x, y)
plt.xlabel('No. of frames')
plt.ylabel('Miss Ratio')
plt.title('My first graph!')
plt.show()
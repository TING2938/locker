from matplotlib import pyplot as plt

xdata = list(range(10))
ydata = [_*2 for _ in xdata]

plt.plot(xdata, ydata, 'b')

plt.hlines(y=5, xmin=0, xmax=10)
plt.vlines(x=5, ymin=0, ymax=20)
plt.axvline()
plt.grid()
plt.show()

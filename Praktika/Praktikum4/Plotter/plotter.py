import numpy as np
import matplotlib.pyplot as plt

for fname in ('quicksort.txt', 'heapsort.txt', 'mergesort.txt.txt', 'shellsort.txt' ):
    data=np.loadtxt(fname)
    X=data[:,1]
    Y=data[:,2]
    plt.plot(X,Y,':ro')
plt.ylim((0,55000))
plt.show()
import random as rn
import statistics as stat
import math
import itertools
import numpy as np

Nvariant = 115
ymax = (30-Nvariant)*10
ymin = (20-Nvariant)*10
x1min = 10
x1max = 50
x2min = -20
x2max = 60

def normalized_x(x):
    x0 = [0.5*(max(x[i])+min(x[i])) for i in range(len(x))]
    dx = [x0[i]-min(x[i]) for i in range(len(x))]
    return [[round((x[i][j]-x0[i])/dx[i],2) for j in range(len(x[i]))] \
    for i in range(len(x))]

def F(sigmas):
    return sigmas[0]/sigmas[1] if sigmas[0] >= sigmas[1] else \
    sigmas[1]/sigmas[0]

def romanovskiy_criteria(yy):
    ymean = [stat.mean(yy[i]) for i in range(len(yy))]
    print("y_mean_i =",*ymean)
    ysigma = [stat.pstdev(yy[i]) for i in range(len(yy))]
    m = len(yy[0])
    sigmaTheta = math.sqrt(2*(2*m-2)/m/(m-4))
    thetas = [(1-2/m)*F(sigmas) for sigmas in \
    list(itertools.combinations(ysigma,2))]
    R = [math.fabs(theta-1)/sigmaTheta for theta in thetas]
    return R

def b(x1,x2,y):
    meanY = [stat.mean(y[i]) for i in range(len(y))]
    mx1 = stat.mean(x1)
    mx2 = stat.mean(x2)
    my = (stat.mean(y[0])+stat.mean(y[1])+stat.mean(y[2]))/3.
    a1 = np.dot(x1,x1)/len(x1)
    a2 = np.dot(x1,x2)/len(x1)
    a3 = np.dot(x2,x2)/len(x2)
    a11 = np.dot(x1,meanY)/len(x1)
    a22 = np.dot(x2,meanY)/len(x2)

    b0 = np.linalg.det([[my,mx1,mx2], [a11,a1,a2], [a22,a2,a3]])/ \
    np.linalg.det([[1,mx1,mx2], [mx1,a1,a2], [mx2,a2,a3]])
    b1 = np.linalg.det([[1,my,mx2], [mx1,a11,a2], [mx2,a22,a3]])/ \
    np.linalg.det([[1,mx1,mx2], [mx1,a1,a2], [mx2,a2,a3]])
    b2 = np.linalg.det([[1,mx1,my], [mx1,a1,a11], [mx2,a2,a22]])/ \
    np.linalg.det([[1,mx1,mx2], [mx1,a1,a2], [mx2,a2,a3]])
    return [b0,b1,b2]

def a(B):
    deltaX1 = math.fabs(x1max-x1min)/2.
    deltaX2 = math.fabs(x2max-x2min)/2.
    x01 = (x1min+x1max)/2.
    x02 = (x2min+x2max)/2.
    a0 = B[0]-B[1]*x01/deltaX1-B[2]*x02/deltaX2
    a1 = B[1]/deltaX1
    a2 = B[2]/deltaX2
    return [a0,a1,a2]

if __name__ == '__main__':
    rn.seed(228)    
    m = 5
    Rcr = 2
    heterogeneous_dispersion = True
    while heterogeneous_dispersion:
        Yy = []
        for i in range(m): 
            Yy.append([rn.choice(range(ymin,ymax)) for k in range(3)])
        if all(r is r<Rcr for r in romanovskiy_criteria([*zip(*Yy)])):
            break
        m+=1

    print("Ruv_i =", *romanovskiy_criteria([*zip(*Yy)]))

    X1 = [rn.choice(range(x1min,x1max)) for i in range(3)]
    X2 = [rn.choice(range(x2min,x2max)) for i in range(3)]
    XN = normalized_x([X1,X2])

    print("b_i =",*b(XN[0],XN[1],[*zip(*Yy)]))
    print("a_i =",*a(b(XN[0],XN[1],[*zip(*Yy)])))

    for row in zip(*(XN+Yy)):
        print(' & '.join(map(str,row)), end='\\\\\n')

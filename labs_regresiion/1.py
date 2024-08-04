import random as rn

def normalized_x(x):
    x0 = [0.5*(max(x[i])+min(x[i])) for i in range(len(x))]
    dx = [x0[i]-min(x[i]) for i in range(len(x))]
    return [[round((x[i][j]-x0[i])/dx[i],2) for j in range(len(x[i]))] \
    for i in range(len(x))]

def Yet(x,a):
    x0 = [0.5*(max(x[i])+min(x[i])) for i in range(len(x))]
    return a[0] + a[1]*x0[0] + a[2]*x0[1] + a[3]*x0[2] 

def criteria(y):
    mean = sum(y)/len(y)
    y = [y[i]-mean for i in range(len(y))]
    return max([n for n in y if n<0])+mean

if __name__ == '__main__':
    rn.seed(228)
    N = 8
    a0 = 1
    a1 = 2
    a2 = 3
    a3 = 4
    X1 = [rn.choice(range(20)) for i in range(N)]
    X2 = [rn.choice(range(20)) for i in range(N)]
    X3 = [rn.choice(range(20)) for i in range(N)]
    
    Y = [a0 + a1*X1[i] + a2*X2[i] + a3*X3[i] for i in range(N)]

    XN = normalized_x([X1,X2,X3])

    print("XN1 = ", *XN[0])
    print("XN2 = ", *XN[0])
    print("XN3 = ", *XN[0])

    print("Yet = "+str(Yet([X1,X2,X3],[a0,a1,a2,a3])))
    print()
    print(Y)
    n = Y.index(criteria(Y))
    print("Point which satisfies plan")
    print("("+str(XN[0][Y.index(criteria(Y))])+", "+ \
    str(XN[1][Y.index(criteria(Y))])+ \
    ", "+str(XN[0][Y.index(criteria(Y))])+")")
    print("Value at this point = "+str(criteria(Y)))
    
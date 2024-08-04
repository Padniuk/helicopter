import time, random
import numpy as np
import matplotlib.pyplot as plt

def oil_checker(map_,mod):
    result = []
    sum_ = 0
    if mod == 0:
        for i in range(len(map_)):
            for j in range(len(map_[i])):
                for l in range(len(map_[i][j])):
                    if map_[i][j][l] == 4:
                        sum_+=1
            result.append(sum_)
            sum_ = 0
        
        return result  

    elif mod == 1:
        for j in range(len(map_[0])):
            for i in range(len(map_)):
                for l in range(len(map_[i][j])):
                    if map_[i][j][l] == 4:
                        sum_+=1
            result.append(sum_)
            sum_ = 0
        
        return result  

    elif mod == 2:
        for l in range(len(map_[0][0])):
            for i in range(len(map_)):
                for j in range(len(map_[0])):
                    if map_[i][j][l] == 4:
                        sum_+=1
            result.append(sum_)
            sum_ = 0

        return result  

    else:
        print('Wrong mod')
        return

def check_feasibility(profit):
    count_inc = 0
    count_dec = 0
    for i in range(len(profit)-1):
        if profit[i+1] > profit[i]:
            count_inc+=1
        elif profit[i+1] < profit[i]:
            count_dec+=1
    try:
        if (count_inc-count_dec)/(count_inc+count_dec)>0.1:
            return 1
        elif (count_inc-count_dec)/(count_inc+count_dec)<-0.1:
            return -1 
        else:
            return 0
    except ZeroDivisionError:
        return 0

def decoder(res):
    if res==1:
        return "amount of oil increase"
    elif res==-1:
        return "amount of oil decrease"
    elif res==0:
        return "amount of oil approximately stable"
    else:
        return "wrong function input"

def initial_data(add_oil=False):
    m = int(input('m = '))
    n = int(input('n = '))
    k = int(input('k = '))
    if any(i<3 for i in [m,n,k]): 
        print("m,n,k should be larger than 2")
        initial_data()

    map_ = [[[random.randint(0,7) for l in range(k)] for j in range(n)] for i in range(m)]
              
    if add_oil:
        for i in range(int(m*n*k/2)):
            map_[random.randint(0,m-1)][random.randint(0,n-1)][random.randint(0,k-1)] = 4

    plt.plot()
    plt.hist([map_[i][j][l] for i in range(m) for j in range(n) for l in range(k)],bins=8)
    plt.xlabel('mineral')
    plt.ylabel('Amount')
    # plt.show()

    return map_

if __name__ == '__main__':
    print("###########general###########")
    map_ = initial_data()
    time_start = time.time()
    along_x = oil_checker(map_,0) 
    along_y = oil_checker(map_,1)
    along_z = oil_checker(map_,2)
    res_x = check_feasibility(along_x)
    res_y = check_feasibility(along_y)
    res_z = check_feasibility(along_z)
    fig, axs = plt.subplots(1,3)
    fig.suptitle('Oil distribution along each direction')
    axs[0].plot([i for i in range(len(along_x))],along_x)
    axs[1].plot([i for i in range(len(along_y))],along_y)
    axs[2].plot([i for i in range(len(along_z))],along_z)
    axs[0].set_xlabel('W-E')
    axs[1].set_xlabel('S-N')
    axs[2].set_xlabel('Depth')
    axs[0].set_xlabel('Amount')
    axs[1].set_xlabel('Amount')
    axs[2].set_xlabel('Amount')
    # plt.show()
    time_finish = time.time()
    # print(map_)
    # print("From E to W",along_x)
    # print("From S to N",along_y)
    # print("Into the depth",along_z)
    
    # print("From E to W",decoder(res_x))
    # print("From S to N",decoder(res_y))
    # print("Into the depth",decoder(res_z))
    
    general_time = time_finish-time_start 
    print("t = ",general_time)

    print("###########numpy###########")
    m = len(map_)
    n = len(map_[0])
    k = len(map_[0][0]) 
    map_np = np.zeros((m,n,k))
    for i in range(m):
        for j in range(n):
            for l in range(k):
                map_np[i][j][l] = map_[i][j][l]
    time_start = time.time()
    arr_np = np.zeros((m, n, k)).astype(int)
    arr_np[(map_np == 4)] = 1

    along_x = np.sum(np.sum(arr_np,axis=2),axis=1) 
    along_y = np.sum(np.sum(arr_np.transpose(1,0,2),axis=2),axis=1)
    along_z = np.sum(np.sum(arr_np.transpose(2,0,1),axis=2),axis=1)

    res_x = check_feasibility(along_x)
    res_y = check_feasibility(along_y)
    res_z = check_feasibility(along_z)
    
    time_finish = time.time()

    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    x = np.array([])
    y = np.array([])
    depth_columns = np.sum(arr_np,axis=2)
    for i in range(len(depth_columns)):
        for j in range(len(depth_columns[0])):
            for l in range(depth_columns[i][j]):
                x = np.append(x,i)
                y = np.append(y,j)
    hist, xedges, yedges = np.histogram2d(x, y, range=[[0, len(depth_columns)], [0, len(depth_columns[0])]])

    xpos, ypos = np.meshgrid(xedges[:-1] + 0.25, yedges[:-1] + 0.25, indexing="ij")
    xpos = xpos.ravel()
    ypos = ypos.ravel()
    zpos = 0

    dx = dy = 0.5 * np.ones_like(zpos)
    dz = hist.ravel()

    ax.bar3d(xpos, ypos, zpos, dx, dy, dz, zsort='average')
    plt.title('Amount of oil')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.show()

    #print(map_)
    # print("From E to W",along_x)
    # print("From S to N",along_y)
    # print("Into the depth",along_z)
    
    # print("From E to W",decoder(res_x))
    # print("From S to N",decoder(res_y))
    # print("Into the depth",decoder(res_z))
 
    print("t = ",time_finish-time_start)
    
    print("N = ",(general_time/(time_finish-time_start)))
 
 

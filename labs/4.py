import time, random
import numpy as np
import matplotlib.pyplot as plt
import ROOT
import array as arr

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
    c = ROOT.TCanvas("c"," ")
    h = ROOT.TH1F("h","",7,0,7)
    for i in range(m):
        for j in range(n):
            for l in range(k):
                h.Fill(map_[i][j][l])
    h.SetTitle("Amount")
    h.GetXaxis().SetTitle("Minerals")
    h.Draw()
    c.Update()
    input("Press enter")
    

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
    time_finish = time.time()
    c = ROOT.TCanvas("c"," ")
    c.Divide(3,1)
    c.cd(1)
    g1 = ROOT.TGraph(len(along_x),arr.array('d',[i for i in range(len(along_x))]),arr.array('d',along_x))
    g1.SetTitle("E-W")
    g1.SetMarkerStyle(20)
    g1.SetMarkerSize(0.5)
    g1.GetYaxis().SetTitle("Amount")
    g1.GetXaxis().SetTitle("X")
    g1.Draw("APL")
    c.cd(2)
    g2 = ROOT.TGraph(len(along_y),arr.array('d',[i for i in range(len(along_y))]),arr.array('d',along_y))
    g2.SetTitle("S-N")
    g2.SetMarkerStyle(20)
    g2.SetMarkerSize(0.5)
    g2.GetYaxis().SetTitle("Amount")
    g2.GetXaxis().SetTitle("Y")
    g2.Draw("APL")
    c.cd(3)
    g3 = ROOT.TGraph(len(along_z),arr.array('d',[i for i in range(len(along_z))]),arr.array('d',along_z))
    g3.SetTitle("Into depth")
    g3.SetMarkerStyle(20)
    g3.SetMarkerSize(0.5)
    g3.GetYaxis().SetTitle("Amount")
    g3.GetXaxis().SetTitle("Z")
    g3.Draw("APL")
    c.Update()
    input("Press enter")

    # plt.show()
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

    depth_columns = np.sum(arr_np,axis=2)
    c = ROOT.TCanvas("c","")
    a = ROOT.THStack("a","")
    h2 = ROOT.TH2F("h","",len(depth_columns),0,len(depth_columns),len(depth_columns[0]),0,len(depth_columns[0]))
    for i in range(len(depth_columns)):
        for j in range(len(depth_columns[0])):
            for l in range(depth_columns[i][j]):
                h2.Fill(i,j)
    h2.SetFillColor(46)
    a.Add(h2)
    a.SetTitle("Amount of oil")
    a.Draw()
    c.Update()
    input("Press enter")

    #print(map_)
    # print("From E to W",along_x)
    # print("From S to N",along_y)
    # print("Into the depth",along_z)
    
    # print("From E to W",decoder(res_x))
    # print("From S to N",decoder(res_y))
    # print("Into the depth",decoder(res_z))
 
    print("t = ",time_finish-time_start)
    
    print("N = ",(general_time/(time_finish-time_start)))
 
 

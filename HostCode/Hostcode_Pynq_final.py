#!/usr/bin/env python
# coding: utf-8




# import pynq,numpy and time libraries
from pynq import Overlay
from pynq import allocate
import time
import numpy as np





TEST_NUM = 100
DATA_SIZE = 16000
MB_CONV = 1000000
MICRO_CONV = 1000000





# carico il bitstream
overlay = Overlay("./ddrbench_golden_wrapper.xsa")



ddrbench_ip =  overlay.ddrbenchmark2_0




# multiple tests 
def multipleTests(buffer_in,buffer_out,repetition):
    sum =0.0
    rep=0
    
    print("***************************************")
    print(" Executing read&write bandwidth tests")
    print("***************************************")
    
    for i in range(repetition):
        input=np.random.randint(low=0,high=8192,size=(DATA_SIZE),dtype=np.int64)
        buffer_in[:]=input.ravel()[:]
        buffer_out[:]=0
        ddrbench_ip.write(0x10,buffer_in.physical_address)
        ddrbench_ip.write(0x1c,buffer_out.physical_address)
        ddrbench_ip.write(0x28,0)
        start = time.time();
        ddrbench_ip.write(0x00,1)
        while(ddrbench_ip.read(0x00) & 0x04 !=0x04):pass
        end = time.time()
        buf_out.invalidate()
        if(np.all(input == buffer_out)):
            if(i==0 or (end-start)*MICRO_CONV<best):best=(end-start)*MICRO_CONV;
            if(i==0 or (end-start)*MICRO_CONV>worst):worst=(end-start)*MICRO_CONV;
            print("test ",i,": ","time:",(end-start)*MICRO_CONV,"µs","  Bandwidth:",(DATA_SIZE*64/8)/((end-start)*MB_CONV),"MB/s")
            sum = sum + end-start
            rep = rep+1
    print(" ")
    print("Executed",rep,"tests","Average_time:", sum/rep*MICRO_CONV,"µs")
    print("Best_time:", best,"µs","  Worst_time:",worst,"µs" ,"  Avg_Bandwidth: ",(DATA_SIZE*64/8)/((sum/rep)*MB_CONV),"MB/s")
    print(" ")
    
    rep =0;
    sum =0.0;
    
    print(" ")
    print("**********************************")
    print(" Executing Read bandwidth tests")
    print("**********************************")
    
    
    for i in range(repetition):
        input=np.random.randint(low=0,high=8192,size=(DATA_SIZE),dtype=np.int64)
        buffer_in[:]=input.ravel()[:]
        buffer_out[:]=0
        ddrbench_ip.write(0x10,buffer_in.physical_address)
        ddrbench_ip.write(0x1c,buffer_out.physical_address)
        ddrbench_ip.write(0x28,1)
        start = time.time();
        ddrbench_ip.write(0x00,1)
        while(ddrbench_ip.read(0x00) & 0x04 !=0x04):pass
        end = time.time()
        buf_out.invalidate()        
        if(i==0 or (end-start)*MICRO_CONV<best):best=(end-start)*MICRO_CONV;
        if(i==0 or (end-start)*MICRO_CONV>worst):worst=(end-start)*MICRO_CONV;
        print("test ",i,": ","time:",(end-start)*MICRO_CONV,"µs","  Bandwidth:",(DATA_SIZE*64/8)/((end-start)*MB_CONV),"MB/s")
        sum = sum + end-start
        rep = rep+1
    print(" ")
    print("Executed",rep,"tests","Average_time:", sum/rep*MICRO_CONV,"µs")
    print("Best_time:", best,"µs","  Worst_time:",worst,"µs" ,"  Avg_Bandwidth: ",(DATA_SIZE*64/8)/((sum/rep)*MB_CONV),"MB/s")
    print(" ")
    
    rep =0;
    sum =0.0;
    
    print(" ")
    print("**********************************")
    print(" Executing Write bandwidth tests")
    print("**********************************")
    
    
    for i in range(repetition):
        
        buffer_in[:]=123
        buffer_out[:]=0
        ddrbench_ip.write(0x10,buffer_in.physical_address)
        ddrbench_ip.write(0x1c,buffer_out.physical_address)
        ddrbench_ip.write(0x28,2)
        start = time.time();
        ddrbench_ip.write(0x00,1)
        while(ddrbench_ip.read(0x00) & 0x04 !=0x04):pass
        end = time.time()
        buf_out.invalidate()
        if(np.all(buffer_in == buffer_out)):
            if(i==0 or (end-start)*MICRO_CONV<best):best=(end-start)*MICRO_CONV;
            if(i==0 or (end-start)*MICRO_CONV>worst):worst=(end-start)*MICRO_CONV;
            print("test ",i,": ","time:",(end-start)*MICRO_CONV,"µs","  Bandwidth:",(DATA_SIZE*64/8)/((end-start)*MB_CONV),"MB/s")
            sum = sum + end-start
            rep = rep+1
    print(" ")
    print("Executed",rep,"tests","Average_time:", sum/rep*MICRO_CONV,"µs")
    print("Best_time:", best,"µs","  Worst_time:",worst,"µs" ,"  Avg_Bandwidth: ",(DATA_SIZE*64/8)/((sum/rep)*MB_CONV),"MB/s")





def singleTest(buffer_in,buffer_out):
    input=np.random.randint(low=0,high=8192,size=(DATA_SIZE),dtype=np.int64)
    buffer_in[:]=input.ravel()[:]
    buffer_out[:]=0
    ddrbench_ip.write(0x10,buffer_in.physical_address)
    ddrbench_ip.write(0x1c,buffer_out.physical_address)
    ddrbench_ip.write(0x28,0)
    #ddrbench_ip.write(0x28,*int)
    start = time.time();
    ddrbench_ip.write(0x00,1)
    while(ddrbench_ip.read(0x00) & 0x04 !=0x04):pass
    end = time.time()
    buf_out.invalidate()
    if(np.all(input == buffer_out)):
        print("test executed, time:",(end-start)*MICRO_CONV,"µs","  Bandwidth:",(DATA_SIZE*64/8)/((end-start)*MB_CONV),"MB/s")





buf_in = allocate(DATA_SIZE,np.int64)
buf_out = allocate(DATA_SIZE,np.int64)
#singleTest(buf_in,buf_out)

print("*********************************************************************************************************")
print(" Main Memory characterizator for Pynq z1   v1.0")
print(" ")
print(" Author: Valentino Guerrini")
print(" Project Supervisor: Davide Conficconi")
print(" ")

print("",TEST_NUM," Tests will be executed for each area: Read&Write, Pure Read and Pure write on SoC main memory")
print(" Every test is done by reading/writing an array of ",DATA_SIZE," int64 on main memory")

print("*********************************************************************************************************")
print(" ")
print(" ")
print(" ")


multipleTests(buf_in,buf_out,TEST_NUM)






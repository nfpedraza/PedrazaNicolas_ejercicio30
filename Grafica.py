import os
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Clase_30.dat")

plt.figure(1, figsize=(10,5)) 

plt.subplot(1,3,1)
plt.imshow(data.T)
plt.xlabel('Posicion')
plt.ylabel('Tiempo')

plt.subplot(1,3,2)
plt.plot(data[:,0], data[:,-1])
plt.plot(data[:,0], data[:,-5])
plt.plot(data[:,0], data[:,-10])
plt.xlabel('PSI')
plt.ylabel('Posicion')


plt.subplot(1,3,3)
plt.plot(data[:,0],data[:,20])

plt.xlabel('PSI(x=0)')
plt.ylabel('Tiempo')

plt.savefig("graph1.png")

plt.figure(2, figsize=(10,5)) 

plt.subplot(1,3,1)
plt.imshow(data.T)
plt.xlabel('Posicion')
plt.ylabel('Tiempo')

plt.subplot(1,3,2)
plt.plot(data[:,0], data[:,-1])
plt.plot(data[:,0], data[:,-5])
plt.plot(data[:,0], data[:,-10])
plt.xlabel('PSI')
plt.ylabel('Posicion')


plt.subplot(1,3,3)
plt.plot(data[:,0],data[:,20])

plt.xlabel('PSI(x=0)')
plt.ylabel('Tiempo')

plt.savefig('graph2.png')

plt.figure(3, figsize=(10,5)) 

plt.subplot(1,3,1)
plt.imshow(data.T)
plt.xlabel('Posicion')
plt.ylabel('Tiempo')

plt.subplot(1,3,2)
plt.plot(data[:,0], data[:,-1])
plt.plot(data[:,0], data[:,-5])
plt.plot(data[:,0], data[:,-10])
plt.xlabel('PSI')
plt.ylabel('Posicion')


plt.subplot(1,3,3)
plt.plot(data[:,0],data[:,20])

plt.xlabel('PSI(x=0)')
plt.ylabel('Tiempo')

plt.savefig('graph3.png')


plt.figure(1, figsize=(10,5)) 

plt.subplot(1,3,1)
plt.imshow(data.T)
plt.xlabel('Posicion')
plt.ylabel('Tiempo')

plt.subplot(1,3,2)
plt.plot(data[:,0], data[:,-1])
plt.plot(data[:,0], data[:,-5])
plt.plot(data[:,0], data[:,-10])
plt.xlabel('PSI')
plt.ylabel('Posicion')


plt.subplot(1,3,3)
plt.plot(data[:,0],data[:,20])

plt.xlabel('PSI(x=0)')
plt.ylabel('Tiempo')

plt.savefig('graph4.png')

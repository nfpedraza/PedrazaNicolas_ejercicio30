import os
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Clase_30.dat")

plt.figure(figsize=(15,4))

dt = data[:,0]
dt= np.delete(dt,-1)

dx = data[-1,:]
dx = np.delete(dx,0)

diff = np.delete(data,0,1)
diff = np.delete(diff,-1,0)

plt.subplot(1,3,1)
plt.imshow(diff,extent=[-1,1,1,0],aspect=2.0)
plt.colorbar()
plt.xlabel('X (m)')
plt.ylabel('Time (s)')
plt.title("$\Psi$ ($m^2/s$)")

plt.subplot(1,3,2)
plt.plot(diff)


plt.xlabel('PSI')
plt.ylabel('Posicion')



plt.savefig("difusion.png")

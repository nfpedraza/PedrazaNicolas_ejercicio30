import os
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Clase_30.dat")
x=np.linspace(0,100,30)
y=np.linspace(0,12000,30)
y2=np.linspace(0,1.2,30)
y3=np.ones(30)*10**-6
x2=np.e**-x

plt.figure(figsize=(15,4))


plt.subplot(1,3,1)
plt.plot(x,x**2,marker ='.')
plt.xlabel('$N_x$')
plt.ylabel('# inte')

plt.subplot(1,3,2)
		 
plt.plot(x2,y2, marker ='.')
plt.xlabel('$N_x$')
plt.ylabel('$|PSI_(0)-PSI_(0)analitica|$')

plt.subplot(1,3,3)
		 
plt.plot(x,y3, marker ='.')
plt.xlabel('$N_x$')
plt.ylabel('$epsilon$')



plt.savefig("difusion.png")

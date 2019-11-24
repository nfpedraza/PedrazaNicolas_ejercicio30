graph4.png : Clase_30.dat Grafica.py
	python Grafica.py

graph3.png : Clase_30.dat Grafica.py
	python Grafica.py

graph2.png : Clase_30.dat Grafica.py
	python Grafica.py

graph1.png : Clase_30.dat Grafica.py
	python Grafica.py
	

Clase_30.dat : Clase_30.x
	./Clase_30.x 

Clase_30.x : Clase_30.cpp
	c++ Clase_30.cpp -o Clase_30.x
	
clean : 
	rm Clase_30.x Clase_30.dat Clase_30_2.dat graph1.png graph2.png
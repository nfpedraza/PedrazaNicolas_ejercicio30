#include <iostream>
#include <cmath>
#include <fstream>

//Codigo extraido y modificado de : https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation/ y de mi ejercicio asado

using namespace std;
const double xmin= -1.0;
const double xmax=1.0;
const int xn=30;
const int tn=450;
const double D= 1.0;
const double T=1.0;
const double S=1.0;
double dif(int tn,int xn);
double difN(double **C, int tn, int xn);
int convergencia (double **C, double **CN int xn, int tn);

double dif(int tn, int xn){
    
    int i,j;
    double time =0.0;
    double dx =(xmax-xmin)/xn;
    double dt= pow(dx,2)/(2*D);
    double x = -1.0;
	
    double **C = new double *[tn];
    for (i=0;i<=tn;i++)
    {
        C[i] =new double[xn];
    }
    
    for(i = 0; i <tn; i++){
        for(j=1; j<xn; j++){
            
            C[i+1][j] = (0.5)*((C[i][j+1] - 2*C[i][j] + C[i][j-1])+(dt*S)); //aqui se define la ecuacion de difusion del libro
            
		C[0][j+1]=0.0;                             //boundary condition i)      
   
        C[xn-1][j+1]=0.0;                        //boundary condition ii) 
        }
    }
	return C;
}
 
double difN(double **C, int tn, int xn){
    
    int i,j;
    double time =0.0;
    double dx =(xmax-xmin)/xn;
    double dt= pow(dx,2)/(2*D);
    double x = -1.0;
	
    double **CN = new double *[tn];
    for (i=0;i<=tn;i++)
    {
        CN[i] =new double[xn];
    }
    
    for(i = 0; i <tn; i++){
        for(j=1; j<xn; j++){
            
            CN[i][j] = abs(C[i][j] - C[i-1][j] ); //aqui se define la ecuacion de difusion del libro
            
		C[0][j+1]=0.0;                             //boundary condition i)      
   
        C[xn-1][j+1]=0.0;                        //boundary condition ii) 
        }
    }
	return CN;
}
   int convergencia (double **C, double **CN int xn, int tn){
	   
	   int i,j =1;
	   double Cm= C[1][0];
	   double CNm=CN[1][0];
	   
	   for (j=0;j<xn;j++){
		   if (C[1][j]>Cm){
			   Cm=C[1][j];
		   }
		   else{
			   Cm=C[1][0];
		   }
		   if(CN[1][j]>CNm){
			   CNm=CN[1][j];
		   }
		   else{
			   CNm=CN[1][0];
		   }
	   }
	   while((CNm/Cm)>pow(10,-5){
		   int paso++;
		   for (j=0;j<xn;j++){
		   if (C[paso][j]>Cm){
			   Cm=C[paso][j];
		   }
		   else{
			   Cm=C[1][j];
		   }
		   if(CN[paso][j]>CNm){
			   CNm=CN[paso][j];
		   }
		   else{
			   CNm=CN[1][j];
		   }
	   }
	   }
		 return paso;
		 }
		   
	   
	   
int main (){
	
    convergencia(C, CN,xn,tn);
    return 0;
}

			   
	                                   

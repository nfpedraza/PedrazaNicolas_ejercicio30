#include <iostream>
#include <cmath>
#include <fstream>

//Codigo extraido y modificado de : https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation/ y de mi ejercicio asado

using namespace std;
const double xmin= -1.0;
const double xmax=1.0;
const int xn=100;
const double D= 1.0;
const double T=1.0;
const double S=1.0;
double **dif(int xn);
double **difN(double **C,int xn);
void convergencia (double **C, double **CN, int xn);

double **dif(int xn){
    
    int i,j;
    double time =0.0;
    double dx =(xmax-xmin)/xn;
    int tn= (2*D)/pow(dx,2);
    double x = -1.0;
	
    double **C = new double *[tn];
    for (i=0;i<=tn;i++)
    {
        C[i] =new double[xn];
    }
    
    for(i = 0; i <tn; i++){
        for(j=1; j<xn; j++){
            
            C[i+1][j] = (0.5)*((C[i][j+1] - 2*C[i][j] + C[i][j-1])+(S/tn)); //aqui se define la ecuacion de difusion del libro
            
		C[0][j+1]=0.0;                             //boundary condition i)      
   
        C[xn-1][j+1]=0.0;                        //boundary condition ii) 
        }
    }
	return C;
}
 
double **difN(double **C, int xn){
    
    int i,j;
    double time =0.0;
    double dx =(xmax-xmin)/xn;
    int tn= (2*D)/pow(dx,2);
    double x = -1.0;
	
    double **CN = new double *[tn];
    for (i=0;i<=tn;i++)
    {
        CN[i] =new double[xn];
    }
    
    for(i = 0; i <tn; i++){
        for(j=1; j<xn; j++){
            CN[i][j] = abs(C[i+1][j] - C[i][j] ); //aqui se define la ecuacion de difusion del libro
            
		CN[0][j+1]=0.0;                             //boundary condition i)      
   
        CN[xn-1][j+1]=0.0;                        //boundary condition ii) 
        }
    }
	return CN;
}
   void convergencia (double **C, double **CN, int xn){
	   
	   ofstream fout("Clase_30.dat");
	   int i,j =1;
       int paso=1;
	   double Cm= C[1][0];
	   double CNm= CN[1][0];
	   
	   for (j=1;j<xn;j++){
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
	   while((CNm/Cm)>pow(10,-5)){
		   paso++;
		   for (j=1;j<xn;j++){
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
		  fout<<xn<<"\t"<<paso<<"\n";
	   fout.close();
		 }

int main (){
	
	convergencia(dif(xn),difN(dif(xn),xn),xn);
	
	
    return 0;
}
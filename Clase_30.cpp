#include <iostream>
#include <cmath>
#include <fstream>

//Codigo extraido y modificado de : https://www.dreamincode.net/forums/topic/125770-simulating-diffusion-equation/

using namespace std;
const double xmin= -1.0;
const double xmax=1.0;
const int xn=30;
const int tn=450;
const double D= 1.0;
const double T=1.0;
const double S=1.0;
void dif(int tn,int xn);

int main ()
{
    dif(tn,xn);
    return 0;
}

void dif(int tn, int xn){
    
    int i,j;
    double time =0.0;
    double dx =(xmax-xmin)/xn;
    double dt= pow(dx,2)/(2*D);
    double x = -1.0;
	
    ofstream fout("Clase_30.dat");

    double **C = new double *[tn];
    for (i=0;i<=tn;i++)
    {
        C[i] =new double[xn];
    }
    
    for(i = 0; i <tn; i++){
        for(j=1; j<xn; j++){
            
            C[i+1][j] = C[i][j] +((D*dt/(pow(dx,2)))*(C[i][j+1] - 2*C[i][j] + C[i][j-1]))+(dt*S); //aqui se define la ecuacion de difusion del libro
            C[0][j+1]=0.0;                             //boundary condition i)      
   
        C[xn-1][j+1]=0.0;                        //boundary condition ii) 
        }
    }
    
    
    for (i = 0; i<=tn; i++)
    {
        fout<<time<<"\t";
        time+=dt;
        for (j = 0; j <=xn; j++)
        {
            fout<<C[i][j]<<"\t";
        }
        fout<<"\n";
    }
    
    fout<<0<<"\t"; 
    for(j=0; j<=xn;j++){
        
        fout<<x<<"\t";
        x+= dx;
    }

    fout.close();
	                                    
}

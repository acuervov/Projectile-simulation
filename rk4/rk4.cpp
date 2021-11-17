#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "integration3.h"
#include "mortar.h"

const double g = 9.8;
const double v0 = 1000000;
const double x0 = 0.0;
const double z0 = 0.0;
const double ro = 1.19;
const double c = 0.2;
const double S = 0.25;
const double m = 15.0;
const double T0 = 0.0;
const double H = 0.001;
int NSTEPS=0;
const int DIM = 4;
double W0=0;
char a0;
char a4;
char p4;
char p8;

typedef std::vector<double> state_t;

void fderiv(const state_t & y, state_t & dydt, double t)
{
    double xp = y[1]* std::cos(y[0]);
    double zp = y[1]* std::sin(y[0]); 
    double fd = 0.5*c*ro*S*(std::pow((xp-W0),2)+std::pow(zp,2));
    dydt[0] = -(g/y[1])* std::cos(y[0]);
    dydt[1] = -g* std::sin(y[0])-fd*(1/m);
    dydt[2] = xp;
    dydt[3] = zp; 
}


int main(void)
{

      
Vector U(8);
Vector DU(2);
Vector O(8);
Vector DO(2);
 interaction (U,O,a0,a4,p4,p8);
 Hemisferio(U,a0,a4);
 Hemisferio(O,p4,p8);
 Convertion (U,DU);
 Convertion(O,DO);

  
  std::cout << "Apuntar a: " << Angulo (DU,DO) <<std::endl;

    state_t y(DIM);
      

    double dis=Distancia (DU,DO);
    double a=0.0;

   // while (y[2]<dis){
 a=80;
double A=a*(M_PI/180);
double v=v0;
double x=x0;
double z=z0;
W0=0;

y = {A,v,x,z};// initial conditions
    integrate(fderiv,y,T0,H,W0,A,z);  


    std::cout << "Con una inclinación de: " << a << "º"<<std::endl;
    return 0; 
}



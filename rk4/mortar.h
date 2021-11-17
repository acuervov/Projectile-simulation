#ifndef __MORTAR_H_
#define __MORTAR_H_

#include<iostream>
#include<cmath>
#include <vector> 


double o1;
double o2;
double o3;
double ns=0;
double a1=0.0;
double a2=0.0;
double a3=0.0;
double eo=0;
double p1;
double p2;
double p3;
double p5=0.0;
double p6=0.0;
double p7=0.0;


typedef std::vector<double> Vector;

void interaction (Vector & U, Vector & O, char& o4, char& a4, char& p4, char& p8);
void Hemisferio (Vector & V, char a, char b);
void Convertion (const Vector & V, Vector & D);
double Angulo(const Vector & P, const Vector & O);
double Distancia (const Vector & P, const Vector & O);
  

void interaction (Vector & U, Vector & D, char& o4, char& a4, char& p4, char& p8){

std::cout << "Ingrese sus posición en coordenadas hexagesimales "<<std::endl;
std::cout << "Latitud"<<std::endl;
std::cout << "Grados: "; std::cin >> U[0];
std::cout << "minutos: "; std::cin >> U[1];
std::cout << "segundos: "; std::cin >> U[2];
std::cout << "Hemisferio: "; std::cin >> o4;

std::cout << "Longitud"<<std::endl;
std::cout << "Grados: "; std::cin >> U[4];
std::cout << "minutos: "; std::cin >> U[5];
std::cout << "segundos: "; std::cin >> U[6];
std::cout << "Hemisferio: "; std::cin >> a4;

std::cout << "Ingrese coordenadas del objetivo "<<std::endl;
std::cout << "Latitud"<<std::endl;
std::cout << "Grados: "; std::cin >> D[0];
std::cout << "minutos: "; std::cin >> D[1];
std::cout << "segundos: "; std::cin >> D[2];
std::cout << "Hemisferio: "; std::cin >> p4;

std::cout << "Longitud"<<std::endl;
std::cout << "Grados: "; std::cin >> D[4];
std::cout << "minutos: "; std::cin >> D[5];
std::cout << "segundos: "; std::cin >> D[6];
std::cout << "Hemisferio: "; std::cin >> p8;


  
  
}

void Hemisferio (Vector & V,char a, char b){
 if (toupper( a )=='N'){V[3]=1;} else if (toupper ( a ) == 'S') {V[3]=-1;} else {std::cout << "error" <<std::endl;}
 if (toupper( b )=='E'){V[7]=1;} else if (toupper ( b ) == 'W') {V[7]=-1;} else {std::cout << "error" <<std::endl;}
 
}


void Convertion (const Vector & V, Vector & D){


 D[0]=V[3]*(V[0]+(V[1]/60)+(V[2]/3600));
 D[1]=V[7]*(V[4]+(V[5]/60)+(V[6]/3600));

 
 }

double Angulo (const Vector & P, const Vector & O){
double resultado=0;
double a=0;
double b=0;
double c=O[0];
double d=O[1];
  if (P[0]>=0){a=-P[0];}
  else {a=P[0];}
  if (P[1]>=0){b=-P[1];}
  else {b=P[1];}
  Vector NC (2);
  NC [0]=c+a;
  NC [1]=d+b;

 if (NC[0]>=0 && NC[1] >=0){resultado=std::atan((std::pow(NC[0],2))/(std::pow (NC[1],2)));}
 else if (NC[0]>=0 && NC[1] < 0){resultado=90+std::atan((std::pow(NC[0],2))/(std::pow (NC[1],2)));}
 else if (NC[0]<0 && NC [1] <0 ){resultado=180+std::atan((std::pow(NC[0],2))/(std::pow (NC[1],2)));}
 else if (NC[0]<0 && NC [1] >=0){resultado=270+std::atan((std::pow(NC[0],2))/(std::pow (NC[1],2)));}
 return resultado*(180/M_PI); 
  
}

double Distancia (const Vector & P, const Vector & O){

double  a=P[0]-O[0];
double  b=P[1]-O[1];
double  c=std::pow (a,2);
double  d=std::pow (b,2);
double  e=std::pow ((c+d),0.5);
return e;

}

#endif


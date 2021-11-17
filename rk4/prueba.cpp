#ifndef __MORTAR_H_
#define __MORTAR_H_

#include<iostream>
#include<cmath>
#include <vector> 


double o1;
double o2;
double o3;
char o4;
double ns=0;
double a1=0.0;
double a2=0.0;
double a3=0.0;
char  a4;
double eo=0;
double p1;
double p2;
double p3;
char p4;
double p5=0.0;
double p6=0.0;
double p7=0.0;
char p8;

void interaction ();

typedef std::vector<double> Vector;
void Hemisferio (Vector & V, char a, char b);
void Convertion (const Vector & V, Vector & D);
double Angulo(const Vector & P, const Vector & O);
double Distancia (const Vector & P, const Vector & O);

int main (int argc, char**argv){
  
interaction ();
Vector U;
Vector DU;
Vector O;
Vector DO;
 U = {o1,o2,o3,ns,a1,a2,a3,eo};
 DU={0,0};
 O= {p1,p2,p3,ns,p5,p6,p7,eo};
 DO={0,0};  
 std::cout <<"Longitud: "<< U[0] << "º "<< U[1]  << "' "<< U[2] << "'' "<< o4<< std::endl;
 std::cout <<"Latitud: "<< U[4] << "º "<< U[5]  << "' "<< U[6] << "'' "<< a4<< std::endl;
 Hemisferio(U,o4,a4);
 Hemisferio(O,p4,p8);
 Convertion (U,DU);
 Convertion(O,DO);

  std::cout << "Decimal ("<< DU[0] << ","<<DU[1]<<")"<<std::endl;
  std::cout << "Decimal ("<< DO[0] << ","<<DO[1]<<")"<<std::endl;
  std::cout << "Apuntar a: " << Angulo (DU,DO) <<std::endl;
  std::cout << "Distancia: " << Distancia (DU,DO) <<std::endl;
  return 0;
  }


void interaction (){

std::cout << "Ingrese sus posición en coordenadas hexagesimales "<<std::endl;
std::cout << "Longitud"<<std::endl;
std::cout << "Grados: "; std::cin >> o1;
std::cout << "minutos: "; std::cin >> o2;
std::cout << "segundos: "; std::cin >> o3;
std::cout << "Hemisferio: "; std::cin >> o4;

std::cout << "Latitud"<<std::endl;
std::cout << "Grados: "; std::cin >> a1;
std::cout << "minutos: "; std::cin >> a2;
std::cout << "segundos: "; std::cin >> a3;
std::cout << "Hemisferio: "; std::cin >> a4;

std::cout << "Ingrese coordenadas del enemigo  "<<std::endl;
std::cout << "Longitud"<<std::endl;
std::cout << "Grados: "; std::cin >> p1;
std::cout << "minutos: "; std::cin >> p2;
std::cout << "segundos: "; std::cin >> p3;
std::cout << "Hemisferio: "; std::cin >> p4;

std::cout << "Latitud"<<std::endl;
std::cout << "Grados: "; std::cin >> p5;
std::cout << "minutos: "; std::cin >> p6;
std::cout << "segundos: "; std::cin >> p7;
std::cout << "Hemisferio: "; std::cin >> p8;


  
  
}

void Hemisferio (Vector & V,char a, char b){
 if (toupper( a )=='N'){V[3]=1;} else if (toupper ( o4 ) == 'S') {V[3]=-1;} else {std::cout << "error" <<std::endl;}
 if (toupper( b )=='E'){V[7]=1;} else if (toupper ( a4 ) == 'W') {V[7]=-1;} else {std::cout << "error" <<std::endl;}
 
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


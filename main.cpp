#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

const double G=9.8;
const double v0=50;
const double x0=0.0;
const double z0=0.0;
const double W0=0.0;
const double M=15;
const double c=0.2;
const double p=1.29;
const double S=0.25;
typedef std::vector<double> vecto_r;
void velocityC ( vecto_r & data, double x0,double z0,double t,double W);
void AcelerationC (const vecto_r & data,double t);
void PositionC (const vecto_r & data,const vecto_r data1, vecto_r & data2, double x0,double z0,double t);
void WindC (const double& t, double& W);
void WindCG (const double t,double& W);


int main() {

 vecto_r velocity(4);
velocity={0.0,0.0,0.0,0.0};//vx,vy,M,vTetha
vecto_r Aceleration(2);
Aceleration={0.0,0.0};
vecto_r position (2);
position={0.0,0.0};
 



for (int ii=5;ii<=90;ii+=5){
std::string path = "resultados/";
std::string filename =std::to_string (ii)+" grados.txt";
std::ofstream printg (path + filename);

double A=ii*(M_PI/180);
double v=v0;
double x=x0;
double z=z0;
double W=W0;


for (double t=0.0;z>=0.0;t+=0.001){
// WindCG(t,W);
  velocityC(velocity,v,A,t,W);
  PositionC(Aceleration,velocity,position,x,z,t);
  printg <<t<<" "<<position [0]<<" "<<position[1]<<std::endl;
  v=velocity[2];
  A=velocity[3];
  x=position [0];
  z=position [1];
}

}

return 0;
}

void velocityC (vecto_r & data, double v,double A,double t,double W){
  data[0]=v*std::cos(A)+W;
  double a=data[0];
  data[1]=v*std::sin(A)-G*t;
  double b=data[1];
  data[2]=std::sqrt((std::pow(data[0],2)+std::pow(data[1],2)));
  double c=data[2];
  double VA=-(G/data[2])*std::cos(A);
  data[3]=A+VA*t;
}

void AcelerationC (const vecto_r & data,vecto_r & data1,double t){
  data1[0]=((-0.5*c*p*S*(std::pow (data[0],2)))/M)-G*std::sin(data[3]);
  data1[1]=((-0.5*c*p*S*(std::pow (data[1],2)))/M)-G*std::sin(data[3]);
}

void PositionC (const vecto_r & data,const vecto_r data1, vecto_r & data2, double x0,double z0,double t){
  data2[0]=x0+data1[0]*t+data[0]*std::pow(t,2);
  data2[1]=x0+data1[1]*t+data[1]*std::pow(t,2);
}


void WindC (const double& t,double&  W){

  double a=t/2;
  double b=std::floor(t);
  double c=std::floor(a);
if (t-b==0.0){
  if (a-c==0.0){
    W=0.0;}
  else {W=10;}  
}
 else {W=W;}
 }
 
void WindCG (const double t,double&  W){

 W=1/(10*std::sqrt(2*M_PI))* exp(-0.5*std::pow((t/10),2));
}




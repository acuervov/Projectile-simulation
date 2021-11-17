#include <iostream>
#ifndef __INTEGRATION_H_
#define __INTEGRATION_H_
#include <fstream>
#include <cmath>

template<typename system_t, typename state_t>
    void rk4(system_t deriv, state_t & data, double t, double h)
{
    state_t dydt(data.size());
    state_t k1(data.size()), k2(data.size()),
        k3(data.size()), k4(data.size()), aux(data.size());
    // k1
    deriv(data, dydt, t);
    for(int ii = 0; ii < data.size(); ++ii) {
        k1[ii] = h*dydt[ii];
    }
    // k2 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k1[ii]/2;
    }
    // k2
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k2[ii] = h*dydt[ii];
    }
    // k3 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k2[ii]/2;
    }
    // k3
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k3[ii] = h*dydt[ii];
    }
    // k4 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k3[ii];
    }
    // k4
    deriv(aux, dydt, t + h);
    for(int ii = 0; ii < data.size(); ++ii) {
        k4[ii] = h*dydt[ii];
    }
    // write new data
    for(int ii = 0; ii < data.size(); ++ii) {
        data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }
}
template<typename system_t, typename state_t>
    void integrate(system_t deriv, state_t & data, double tmin, double dt, double& W, double i,double z0)
{

double a=i*180/M_PI;
std::string path = "resultados/";
std::string filename =std::to_string (a)+" grados.txt";
std::ofstream printg (path + filename);
double z=z0;

    for (int ii = 0; z>=0.0; ++ii) {

    z=data[3];
    double t = tmin + ii*dt;

  //int b=1/dt-(t+dt); if (b%2==0){W=10;} else {W=0;}	//viento cambia cada segundo

  W=1/(10*std::sqrt(2*M_PI))* exp(-0.5*std::pow((t/10),2));//cambio del viento con distribución gauseana
        printg << t << "  " << data[0] << "  " << data[1] << "  " <<data[2] << "  " << data[3] <<"\n";

rk4(deriv, data, t, dt);

    }
}



#endif // __INTEGRATION_H_

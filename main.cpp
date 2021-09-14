#include <iostream>
#include "Lagrange.h"
#include "Newton.h"
int main() {
    std::vector<double> x = {0,1,2,3,4,5};
    std::vector<double> y = {0,1,8,27,64,125};
    Lagrange otvet(x,y);
    std::cout <<"Lagrange: "<< otvet.interpolate(1.5) << std::endl;
    Newton newton(x,y);
    std::cout<<"Newton: "<<newton.interpolate(1.5)<<std::endl;

    return 0;
}
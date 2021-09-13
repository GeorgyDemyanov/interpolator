#include <iostream>
#include "Lagrange.h"
int main() {
    std::vector<double> x = {0,1,2,3,4};
    std::vector<double> y = {0,1,4,9,16};
    Lagrange otvet(x,y);
    std::cout << otvet.interpolate(85) << std::endl;
    return 0;
}

//
// Created by Demia on 14.09.2021.
//

#ifndef INTERPOLATOR_NEWTON_H
#define INTERPOLATOR_NEWTON_H

#include <vector>

class Newton {
private:
    std::vector<double> x;
    std::vector<double> y;

    double difference(double k, int first, int last, std::vector<double> &diff);

public:
    Newton(const std::vector<double> &x,
           const std::vector<double> &y);

    double interpolate(double x);

};


#endif //INTERPOLATOR_NEWTON_H

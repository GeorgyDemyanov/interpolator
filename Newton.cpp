//
// Created by Demia on 14.09.2021.
//

#include "Newton.h"
#include <algorithm>
#include <cmath>
#include <iostream>

Newton::Newton(const std::vector<double> &x, const std::vector<double> &y) {
    this->x = x;
    this->y = y;
}

double Newton::difference(double k, int first, int last, std::vector<double> &diff) {
    if (k == 1) {
        return (y[last] - y[first]) / (x[last] - x[first]);
    }
    double left = difference(k - 1, first + 1, last, diff);
    double right = difference(k - 1, first, last - 1, diff);
    diff[k - 1] = right;
    return (left - right) /
           (x[last] - x[first]);

}

double Newton::interpolate(double x) {
    std::vector<double> diff(this->x.size());
    int N = this->x.size() - 1;
    diff.back() = difference(N, 0, N, diff);
    double result = 0;
    double complex;
    for (int i = 1; i < diff.size(); ++i) {
        complex = 1;
        for (int k = 0; k < i; k++) {
            complex *= (x - this->x[k]);
        }
        result += diff[i] * complex;

    }
    return result+y[0];

};







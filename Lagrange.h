//
// Created by Demia on 13.09.2021.
//

#ifndef INTERPOLATOR_LAGRANGE_H
#define INTERPOLATOR_LAGRANGE_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
class Lagrange {
private:
    std::vector<T> x;
    std::vector<T> y;

    T l(T x, int k) const {
        T result = 1;
        for (int i = 0; i < this->x.size(); ++i) {
            if (i == k) continue;
            result *= (x - this->x[i]) / (this->x[k] - this->x[i]);
        }
        return result;
    }

public:
    Lagrange(const std::vector<T> &x, const std::vector<T> &y) {
        this->x = x;
        this->y = y;
    }

    T interpolate(T x) const {
        if (!(this->x[0] <= x && this->x.back() >= x)) {
            std::cout << "Babushka perepolnilas\'" << std::endl;
            return 0;
        }
        int i = std::upper_bound(this->x.begin(), this->x.end(), x) - this->x.begin();
        if (std::abs(x - this->x[i]) < 1e-15 && i < this->x.size()) {
            return y[i];
        }
        if (std::abs(x - this->x[i - 1]) < 1e-15 && i > 0) {
            return y[i - 1];
        }
        T result = 0;
        for (int k = 0; k < this->x.size(); ++k) {
            result += l(x, k) * this->y[k];
        }
        return result;
    }


};


#endif //INTERPOLATOR_LAGRANGE_H

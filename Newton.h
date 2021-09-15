//
// Created by Demia on 14.09.2021.
//

#ifndef INTERPOLATOR_NEWTON_H
#define INTERPOLATOR_NEWTON_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
template<typename T>
class Newton {
private:
    std::vector<T> x;
    std::vector<T> y;
    std::vector<T> diff;


    T difference(T k, int first, int last) {
        if (k == 1) {
            return (y[last] - y[first]) / (x[last] - x[first]);
        }
        T left = difference(k - 1, first + 1, last);
        T right = difference(k - 1, first, last - 1);
        diff[k - 1] = right;
        return (left - right) /
               (x[last] - x[first]);

    }


public:
    Newton(const std::vector<T> &x, const std::vector<T> &y) {
        this->x = x;
        this->y = y;
        diff.resize(this->x.size());
        int N = this->x.size() - 1;
        diff.back() = difference(N, 0, N);
        diff[0] = y[0];
    }


    T interpolate(T x) {
        T result = 0;
        T complex;
        for (int i = 0; i < diff.size(); ++i) {
            complex = 1;
            for (int k = 0; k < i; k++) {
                complex *= (x - this->x[k]);
            }
            result += diff[i] * complex;

        }
        return result;

    };

};
//
// Created by Demia on 14.09.2021.
//




#endif //INTERPOLATOR_NEWTON_H

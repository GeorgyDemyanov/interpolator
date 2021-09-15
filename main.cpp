#include <iostream>
#include "Lagrange.h"
#include "Newton.h"
#include <cmath>
#include "algorithm"
#include <cassert>
template <typename T>
std::vector<T> generateData(int n) {
    std::vector<T> test(n);
    for (auto &element: test) {
        element = std::sin(rand()) * 1000;
    }
    return test;
}
template <typename T>
void test(int n) {
    std::vector<T> x = generateData<T>(10);
    std::vector<T> y = generateData<T>(10);
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    Lagrange<T> lagrange(x, y);
    Newton<T> newton(x, y);
    for (int i = 0; i < n; i++) {
        T t = std::sin(rand()) * 0.5 * (x.back() - x[0]) + 0.5 * (x.back() + x[0]);
        T l = lagrange.interpolate(t);
        T h = newton.interpolate(t);
        std::cerr << i << " " << l << " " << h << std::endl;
        assert(std::abs(l-h) <= 1e-8 && "Tb| pidor");
    }
}

int main() {
//    std::vector<double> x = {0, 1, 2, 3, 4, 5};
//    std::vector<double> y = {0, 1, 8, 27, 64, 125};
//    Lagrange otvet(x, y);
//    std::cout << "Lagrange: " << otvet.interpolate(1.5) << std::endl;
//    Newton newton(x, y);
//    std::cout << "Newton: " << newton.interpolate(1.5) << std::endl;
    test<double>(100);

    return 0;
}
#include <tuple>
#include <stdexcept>
#include <iostream>
#include <math.h>
#include <string>

std::pair<double, double> findRoots(double a, double b, double c)
{
    //throw std::logic_error("Waiting to be implemented");
    // compute delta
    double delta = b*b - (4*a*c);
    //find x1 and x2
    double diff = 2*a;
    double x1 = ( sqrt(delta) - b) / diff;
    double x2 = (-b - sqrt(delta)) / diff;
    
    return std::make_pair(x1, x2);
}

#ifndef RunTests
int main()
{
    std::pair<double,double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}
#endif
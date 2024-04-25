#ifndef POLINOM_H
#define POLINOM_H

#include <vector>
#include <iostream> 
#include <sstream>

using namespace std;


struct polinom
{
    vector<double> egyutthatok;

    polinom();
    polinom(const std::vector<double>& a);
    polinom(const polinom& cpy);
    polinom(const int& x);


     void iras();
     polinom operator+(const polinom& p) const;
     polinom operator-(const polinom& p) const;
     polinom operator*(const polinom& p) const;
     polinom diff() const;
};

#endif
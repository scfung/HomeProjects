//
//  HunPolynomial.hpp
//  HunPolynomial
//
//  Created by Stanley Fung on 5/3/22.
//

#ifndef HunPolynomial_h
#define HunPolynomial_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


class HunPolynomial{
    public:
    HunPolynomial();
    HunPolynomial(std::vector<int> poly);
    ~HunPolynomial();
    void Set(std::vector<int> polynomial);
    int getDegree() const;
    int getCoefficent(int index) const;
    float operator() (float x);
    void setSize(int size);
    void PolySetter(int degree, int coeff);
    private:
    std::vector<int> coefficents;
    int degreeOfPoly;
    
};
std::ostream& operator<<(std::ostream& os, HunPolynomial& object);
HunPolynomial operator+(const HunPolynomial& add1, const HunPolynomial& add2);
HunPolynomial operator-(const HunPolynomial& object1, const HunPolynomial& object2);
HunPolynomial operator*(const HunPolynomial& fact1, const HunPolynomial& fact2);
#endif /* HunPolynomial_hpp */

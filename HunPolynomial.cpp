//
//  HunPolynomial.cpp
//  HunPolynomial
//
//  Created by Stanley Fung on 5/3/22.
//

#include "HunPolynomial.h"

HunPolynomial::HunPolynomial(){
    degreeOfPoly = -1;
    coefficents.resize(0);
}

HunPolynomial::~HunPolynomial(){
    
};
int HunPolynomial::getDegree() const{
    return degreeOfPoly;
}
int HunPolynomial::getCoefficent(int index) const{
    if(index <= degreeOfPoly){
        return coefficents[index];
    }
    else{
        return 0.0;
    }
}
HunPolynomial::HunPolynomial(std::vector<int> poly){
    unsigned long int temp;
    temp = poly.size();
    degreeOfPoly = (int)temp - 1;
    coefficents = poly;
}
// if poly[i] = 0 print out nothing, if poly[i] = 1, print only the variable, and poly[i] = -1, print negative sign and variable.
void HunPolynomial::Set(std::vector<int> polynomial){
    unsigned long int temp;
    temp = polynomial.size();
    degreeOfPoly = (int)temp - 1;
    coefficents = polynomial;
}
void HunPolynomial::PolySetter(int degree, int coeff){
    
    coefficents[degree] = coeff;
}
void HunPolynomial::setSize(int size){
    degreeOfPoly = size;
    coefficents.resize(size, 0);
}
HunPolynomial operator+(const HunPolynomial& add1, const HunPolynomial&add2){
    int degree1 = add1.getDegree();
    int degree2 = add2.getDegree();
    int temp_degree, sum, x;
    if(degree1 > degree2){
        temp_degree = degree1;
        x = temp_degree - degree2;
    }
    else{
        temp_degree = degree2;
        x = temp_degree - degree1;
    }
    if(degree1 < 0){
        return add2;
    }
    if(degree2 < 0){
        return add1;
    }
    HunPolynomial sumPoly;
    sumPoly.setSize(temp_degree);
    for(int i = temp_degree; i >= 0; i--){
        int t = i - x;
        if(t >= 0){
            if(degree1 > degree2){
                sum = add1.getCoefficent(i) + add2.getCoefficent(t);
                sumPoly.PolySetter(i, sum);
            }
            if(degree1 < degree2){
                sum = add1.getCoefficent(t) + add2.getCoefficent(i);
                sumPoly.PolySetter(i, sum);
            }
            if(degree1 == degree2){
                sum = add1.getCoefficent(i) + add2.getCoefficent(i);
                sumPoly.PolySetter(i, sum);
            }
        }
        else if(degree1 > degree2){
            sum = add1.getCoefficent(i);
            sumPoly.PolySetter(i, sum);
        }
        else{
            sum = add2.getCoefficent(i);
            sumPoly.PolySetter(i, sum);
            }
        }
    return sumPoly;
}
HunPolynomial operator-(const HunPolynomial& object1, const HunPolynomial& object2){
    int degree1 = object1.getDegree();
    int degree2 = object2.getDegree();
    int temp_degree, difference, x;
    if(degree1 > degree2){
        temp_degree = degree1;
        x = temp_degree - degree2;
    }
    else{
        temp_degree = degree2;
        x = temp_degree - degree1;
    }
    if(degree1 < 0){
        return object2;
    }
    if(degree2 < 0){
        return object1;
    }
    HunPolynomial diffPoly;
    diffPoly.setSize(temp_degree);
    for(int i = temp_degree; i >= 0; i--){
        int t = i - x;
        if(t >= 0){
            if(degree1 > degree2){
                difference = object1.getCoefficent(i) - object2.getCoefficent(t);
                diffPoly.PolySetter(i, difference);
            }
            if(degree1 < degree2){
                difference = object1.getCoefficent(t) - object2.getCoefficent(i);
                diffPoly.PolySetter(i, difference);
            }
            if(degree1 == degree2){
                difference = object1.getCoefficent(i) - object2.getCoefficent(i);
                diffPoly.PolySetter(i, difference);
            }
        }
        else if(degree1 > degree2){
            difference = object1.getCoefficent(i);
            diffPoly.PolySetter(i, difference);
        }
        else{
            difference = 0 - object2.getCoefficent(i);
            diffPoly.PolySetter(i, difference);
            }
    }
    return diffPoly;
}

HunPolynomial operator*(const HunPolynomial& fact1, const HunPolynomial& fact2){
    int largest_degree = fact1.getDegree() + fact2.getDegree();
    int degree1 = fact1.getDegree();
    int degree2 = fact2.getDegree();
    int product, temp;
    HunPolynomial productPoly;
    productPoly.setSize(largest_degree);
    for(int i = 0; i <= degree1; i++){
        for(int j = 0; j <= degree2; j++){
            int comDeg = i + j;
            product = fact1.getCoefficent(i) * fact2.getCoefficent(j);
            if(productPoly.getCoefficent(comDeg) != 0){
                temp = productPoly.getCoefficent(comDeg) + product;
                productPoly.PolySetter(comDeg, temp);
            }
            else{
            productPoly.PolySetter(comDeg, product);
            }
        }
    }
    //productPoly.PolySetter(largest_degree, 0);
    return productPoly;
}
float HunPolynomial::operator()(float x){
    float total = 0, exponent = 1;
    for(int i = degreeOfPoly; i >= 0; i--){
        total += coefficents[i] * exponent;
        exponent *= x;
    }
    return total;
}

std::ostream& operator<< (std::ostream& os, HunPolynomial& object){
    
    if(object.getCoefficent(0) == 1){
        os << "x^" << object.getDegree();
    }
    if(object.getCoefficent(0) == -1){
        os << "- " << "x^" << object.getDegree();
    }
    if(object.getCoefficent(0) <= -2){
        os << "- " << abs(object.getCoefficent(0)) << "*" << "x^" << object.getDegree();
    }
    if(object.getCoefficent(0) >= 2){
        os << object.getCoefficent(0) << "*" << "x^" << object.getDegree();
    }
    for(int i = 1; i <= object.getDegree() - 2; i++){
        if(object.getCoefficent(i) == 1){
            os << " + " << "x^" << object.getDegree() - i;
        }
        if(object.getCoefficent(i) == -1){
            os << " - " << "x^" << object.getDegree() - i;
        }
        if(object.getCoefficent(i) <= -2){
            os << " - " << abs(object.getCoefficent(i)) << "*" << "x^" << object.getDegree() - i;
        }
        if(object.getCoefficent(i) >= 2){
            os << " + " << object.getCoefficent(i) << "*" << "x^" << object.getDegree() - i;
        }
    }
    int k = object.getDegree() - 1;
    if(object.getCoefficent(k) == 1 and object.getDegree() - 1 == k){
        os << " + " << "x";
    }
    if(object.getCoefficent(k) == -1 and object.getDegree() - 1 == k){
        os << " - " << "x";
    }
    if(object.getCoefficent(k) <= -2 and object.getDegree() - 1 == k){
        os << " - " << abs(object.getCoefficent(k)) << "*" << "x";
    }
    if(object.getCoefficent(k) >= 2 and object.getDegree() - 1 == k){
        os << " + " << object.getCoefficent(k) << "*" << "x";
    }
    int x = object.getDegree();
    if(object.getCoefficent(x) == 1 and object.getDegree() == x){
        os << " + " << 1;
    }
    if(object.getCoefficent(x) == -1 and object.getDegree() == x){
        os << " - " << 1;
    }
    if(object.getCoefficent(x) <= -2 and object.getDegree() == x){
        os << " - " << abs(object.getCoefficent(x));
    }
    if(object.getCoefficent(x) >= 2 and object.getDegree() == x){
        os << " + " << object.getCoefficent(x);
    }
        
    return os;
}


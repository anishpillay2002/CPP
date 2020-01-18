/*
 * Complex.h
 *
 *  Created on: Mar 10, 2019
 *      Author: anishpillay
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace testprogramming {

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();
	virtual ~Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	const Complex &operator=(const Complex &other);

	double getReal() const{
		return real;
	}
	double getImaginary() const{
			return imaginary;
		}
	bool operator==(const Complex &other) const;
};

ostream &operator<<(ostream &out, const Complex &c);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+( double d, const Complex &c1);

} /* namespace testprogramming */

#endif /* COMPLEX_H_ */

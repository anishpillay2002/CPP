/*
 * Complex.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: anishpillay
 */

#include "Complex.h"


namespace testprogramming {

//Complex::Complex():real(0), imaginary(0) {
//	// TODO Auto-generated constructor stub
//
//}

ostream &operator<<(ostream &out,const Complex &c){
	out<< "("<< c.getReal()<<","<<c.getImaginary()<<")";
	return out;
}

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary){

}

Complex operator+(const Complex &c1, const Complex &c2){
	return Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
}

Complex operator+(const Complex &c1, double d){
	return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex operator+(double d, const Complex &c1){
	return Complex(c1.getReal()+d, c1.getImaginary());
}

bool Complex::operator==(const Complex &other) const{
	return (real ==other.real && imaginary ==other.imaginary);
}

Complex::Complex(const Complex &other){

	real = other.real;
	imaginary = other.imaginary;
}


Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

const Complex &Complex::operator=(const Complex &other){
	real = other.real;
	imaginary=other.imaginary;
	return *this;
}

} /* namespace testprogramming */

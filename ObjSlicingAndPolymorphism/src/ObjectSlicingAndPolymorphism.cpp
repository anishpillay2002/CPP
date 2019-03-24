/*
 * ObjectSlicingAndPolymorphism.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: anishpillay
 */


#include <iostream>
using namespace std;

class Parent{
public:
	Parent(){}
	Parent(const Parent &other){
		cout<<"Copy PARENT"<<endl;
	}
	virtual void print(){
		cout<<"Parent"<<endl;
	}

	virtual ~Parent(){

	}
};


class Child:public Parent{
public:
	void print(){
		cout<<"child"<<endl;
	}

};

int main(){

	Child u;
	//u.print();
	u.print();
	Parent &t = u;
	t.print();

	Parent p2 =Child(); // invokes Copy constructor
	p2.print();
	return 0;
}


/*
 * ComplexNumClass.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: anishpillay
 */

#include <iostream>
#include "Complex.h"


using namespace std;
using namespace testprogramming;

int main()
{
	Complex c1(2,3);
	Complex c2(2,3);


	Complex c3=c1+c2;
	Complex c4 = c1+4;

	cout<<"Give me something"<<endl;
	cout<<c1<<";"<<c2<<endl;


	cout<<c3<<";"<<1+2+c1+c2+c3<<endl;
	cout<<c4<<endl;

	if (c1==c2)
	{cout<<"Equal"<<endl;
	}
	else
	{cout<<"Not Equal"<<endl;
	}


	return 0;
}




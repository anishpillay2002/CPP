/*
 * TemplateClass.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: anishpillay
 */
#include <iostream>
using namespace std;

template<class T>
class Test{
private:
	T obj;
public:
	Test(T obj){
		this->obj = obj;
	}

	void print()
	{
		cout<<obj<<endl;
	}
};



template<class Y>
void print(Y n)
{
	cout<<n<<endl;
}

int main()
{
	Test<string> obj1("Hello");
	obj1.print();

	print<string>("Eureka");
	print<int>(5);
	print(4);
	print("Yellow monster");
	return 0;
}



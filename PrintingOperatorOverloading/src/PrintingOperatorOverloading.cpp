/*
 * PrintingOperatorOverloading.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: anishpillay
 */



#include <iostream>
using namespace std;

class Test{
private:
	int id;
	string name;

public:
	Test(int id, string name): id(id), name(name){}

	~Test(){
		//cout<<"Object is destroyed"<<endl;
	}

	void print(){
		cout<< id<< "; "<< name <<endl;
	}

	const Test &operator=(const Test &other){
		cout<<"Assignment Running"<< endl;

		id = other.id;
		name = other.name;
		return *this;
	}


	Test(const Test &other) {
		cout<<"Copy constructor running" <<endl;
		*this = other;
	}

	friend ostream &operator<<(ostream &out, Test &test)
	{
		out<<test.id <<";"<<test.name;
		return out;
	}
};

int main(){

	Test test1(10,"Mike");
	cout<<"Print test1:"<<flush;
	cout<< test1<<endl;

	Test test2(20,"Bob");

	test2 = test1;
	cout<<"Print test2: "<<flush;
	test2.print();

	Test test3 = test1;
	cout<<"Print test3: "<<flush;

	test3.print();



	return 0;
}

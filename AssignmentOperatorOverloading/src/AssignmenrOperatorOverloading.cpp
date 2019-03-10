/*
 * AssignmenrOperatorOverloading.cpp
 *
 *  Created on: Mar 9, 2019
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
};

int main(){

	Test test1(10,"Mike");
	test1.print();
	return 0;
}

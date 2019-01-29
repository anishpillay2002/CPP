/*
 * CustObjsAsMap.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: anishpillay
 */


#include <iostream>
#include <map>

using namespace std;

class Person
{
private:
	string name;
	int age;

public:
	Person(): name(""),age(0){

	}

	/* Copy constructor bcoz if you normally copy an object itll
	 * point to the same memory location so you need t create this constructor
	 * to manually assign values when copying */

	Person(const Person &other){
		cout<<"Copy Constructor running"<<endl;
		name = other.name;
		age = other.age;
	}

	Person(string name, int age) :
		name(name), age(age){

	}

	void print(){
		cout<< name<< ": " <<age <<endl;
	}

};


int main(){
	map<int, Person> people;


	people[50] = Person("Raj",20);
	people[32] = Person("Mike",40);
	people[1] = Person("Vicky",30);

	people.insert(make_pair(55,Person("Bob",45)));
	people.insert(make_pair(55,Person("Sue",32)));

	for(map<int, Person>::iterator it =people.begin(); it!=people.end(); it++){
		cout<< it->first<<": "<<flush;
		it->second.print();
	}

	return 0;

}

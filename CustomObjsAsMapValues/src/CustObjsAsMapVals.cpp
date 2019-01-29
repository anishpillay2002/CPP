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
		name = other.name;
		age = other.age;
	}

	Person(string name, int age) :
		name(name), age(age){

	}

	void print() const{
		cout<< name<< ": " <<age <<flush;
	}

	bool operator<(const Person &other) const{
		/* When you add this if else condition, it understands if the name is same but age is different in 2 entries ,
		then it explicity makes another entry. Check with and without this if else to see the effect.*/
		if (name==other.name){
			return age<other.age;
		}
		else
		{
		return name < other.name;
		}
	}


};


int main(){
	map<Person, int> people;


	people[Person("Raj",20)] = 41;
	people[Person("Mike",444)] = 32;
	people[Person("Mike",40)] = 213;// Notice the key did not change, only value changed in the output for "mike". Run this without the if else in condition in 'bool operator<' function
	people[Person("Vicky",30)] = 21;

	for(map<Person, int>::iterator it =people.begin(); it!=people.end(); it++){
		cout<< it->second<<": "<<flush;
		it->first.print();
		cout<<endl;
	}

	return 0;

}

/*
 * SortingVectors.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: anishpillay
 */

#include <iostream>
#include <stack>
#include <queue>

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

/*
	bool operator<(const Test &other) const{
	return id< other.id;
	}
*/

	friend bool comp(const Test &a,const Test &b);
};


bool comp(const Test &a,const Test &b){
	return a.name<b.name;
}

int main()
{
	vector<Test> tests;

	tests.push_back(Test(20,"Mike"));
	tests.push_back(Test(4,"John"));
	tests.push_back(Test(10,"Sue"));
	tests.push_back(Test(2,"Anish"));

	sort(tests.begin(), tests.end(), comp);

	for(int i=0;i<tests.size(); i++)
	{
		tests[i].print();
	}

	return 0;
}


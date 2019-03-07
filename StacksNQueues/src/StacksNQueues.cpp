/*
 * StacksNQueues.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: anishpillay
 */




#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test{
private:
	string name;

public:
	Test(string name):name(name){}

	~Test(){
		//cout<<"Object is destroyed"<<endl;
	}

	void print(){
		cout<< name<<endl;
	}

};


int main()
{
	// ============== Stack ===================== //
	// LIFO : Last in first out -> Think of it as a stack of pancakes
	// Push and pop are two main methods to add and remove from stack resp

	cout<<" ======= Start Stack Operation ====== "<<endl;
	stack<Test> testStack;

	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Sue"));
	testStack.push(Test("Anish"));

//	cout<<"Object creation start"<<endl;
//	Test test1 = testStack.top();
//	test1.print();
//
//	testStack.pop();
//
//	Test test2 = testStack.top();
//	test2.print();

	// To be efficient use reference

	/* This is invalid code! ! Object is destroyed
	Test &test2 = testStack.top();
	testStack.pop();
	test2.print(); // Reference refers to destroyed objects
	*/

	while(testStack.size() > 0)
	{
		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}


	cout<<"DONE Stack"<<endl;
	cout<<endl;
	cout<<" ======= Start Queue Operation ====== "<<endl;
	// ============== Queue ===================== //
	// FIFO : First in first out -> Think of it as a stack of pancakes
		// Push and pop are two main methods to add and remove from stack resp
		queue<Test> testQueue;

		testQueue.push(Test("Mike"));
		testQueue.push(Test("John"));
		testQueue.push(Test("Sue"));
		testQueue.push(Test("Anish"));

	//	cout<<"Object creation start"<<endl;
	//	Test test1 = testStack.top();
	//	test1.print();
	//
	//	testStack.pop();
	//
	//	Test test2 = testStack.top();
	//	test2.print();

		// To be efficient use reference

		/* This is invalid code! ! Object is destroyed
		Test &test2 = testStack.top();
		testStack.pop();
		test2.print(); // Reference refers to destroyed objects
		*/

		while(testQueue.size() > 0)
		{
			Test &test = testQueue.front();
			test.print();
			testQueue.pop();
		}


		cout<<"DONE Queue"<<endl;

	return 0;
}

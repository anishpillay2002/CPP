/*
 * FunctionPointer.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: anishpillay
 */


#include <iostream>
using namespace std;

void Test(){
	cout<<"Hello"<<endl;

}

void Test1(int value){
	cout<<"The value is "<<value<<endl;

}


//int main(){
//	Test();
//	void(*pTest)();
//
//	pTest = &Test;
//	(*pTest)();
//	return 0;
//}
// or
//int main(){
//	Test();
//	void(*pTest)();
//
//	pTest = Test;
//	pTest();
//	return 0;
//}
//or
int main(){
	Test();
	void(*pTest)()= Test;

	pTest();

	void(*p1Test)(int)= Test1;

	p1Test(5);
	return 0;
}

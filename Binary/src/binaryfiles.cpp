// To run these programs the first time, go to project, Right click select 'Properties' and select 'Run/debug settings'. Select 'New' or 'Edit' existing configuration and select the .exe file for the program in the Debug or release folder. The .exe file appears only after building the code once.

#include<iostream>
using namespace std;

/*  cpp adds padding to the memory allocated to be more efficient while computing data. A pragma is
 * added so that this padding can be removed/ignored. */
#pragma pack(push, 1)

struct Person{

	char name[50];
	int age;
	double weight;
};

#pragma pack(pop)

int main_test(){
	cout<<sizeof(Person)<<endl; // This should be 62 but shows up as 64 as cpp adds padding.
	return 0;
}

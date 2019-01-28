// To run these programs the first time, go to project, Right click select 'Properties' and select 'Run/debug settings'. Select 'New' or 'Edit' existing configuration and select the .exe file for the program in the Debug or release folder. The .exe file appears only after building the code once.

#include<iostream>
#include<fstream>
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

int main(){

	Person someone ={"Frodo",220,0.8};
	string filename = "test.bin";

	// Write Binary File
	ofstream outputfile;
	outputfile.open(filename,ios::binary);

	if(outputfile.is_open())
	{
		outputfile.write(reinterpret_cast<char *>(&someone),sizeof(Person));
		outputfile.close();
		cout<<"Created File"<<endl;
	}
	else{
		cout<<"Could not create file: "<< filename;
	}

	Person someoneElse = {};

	// Read Binary File
	ifstream inputfile;
	inputfile.open(filename,ios::binary);

		if(inputfile.is_open())
		{
			inputfile.read(reinterpret_cast<char *>(&someoneElse),sizeof(Person));
			inputfile.close();
			cout<<"Read File"<<endl;
		}
		else{
			cout<<"Could not create file: "<< filename;
		}

		cout<< someoneElse.name<<", "<<someoneElse.age<<", "<<someoneElse.weight<<endl;
	//cout<<sizeof(Person)<<endl; // This should be 62 but shows up as 64 as cpp adds padding.
	return 0;
}

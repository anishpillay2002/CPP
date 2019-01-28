/* To run these programs the first time, go to project,
 * Right click select 'Properties' and select 'Run/debug settings'.
 * Select 'New' or 'Edit' existing configuration and select the .exe file
 * for the program in the Debug or release folder. The .exe file appears only
 * after building the code once.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> strings;
	strings.push_back("first");
	strings.push_back("second");
	strings.push_back("third");

	//strings[3] = "dog"; You can either do a push_back so cpp handles the sizing or you can assign a particular index like this line
	cout<<"Output of for loop"<<endl;
	for(int i=0;i<strings.size();i++)
	{
		cout<<strings[i]<<endl;

	}

	// You can either do a for loop or an iterator as below
	cout<<"Output of iterator"<<endl;
	vector<string>::iterator it =strings.begin();
	it++;
	cout<<*it<<endl;

	// for loop with the iterator
	cout<<"Output of for loop and iterator"<<endl;

	for(vector<string>::iterator it =strings.begin();it!=strings.end();it++)
	{
		cout<<*it<<endl;
	}


	// You can skip elements as well
	cout<<"Skipping elements"<<endl;
	vector<string>::iterator it2 =strings.begin();
	it2 +=2;
	cout<<*it2<<endl;


	// This one is a test of my memory
	cout<<"Testing my memory"<<endl;
	for(vector<string>::iterator it3 =strings.begin(); it3!=strings.end();it3++)
	{
		cout<<"This is my test: "<<*it3 <<endl;

	}

	return 0;

}

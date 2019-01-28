
// To run these programs the first time, go to project, Right click select 'Properties' and select 'Run/debug settings'. Select 'New' or 'Edit' existing configuration and select the .exe file for the program in the Debug or release folder. The .exe file appears only after building the code once.
#include <iostream>
#include <fstream>
using namespace std;


int main()
{

	ifstream infile;
	string infilename = "stats.txt";

	infile.open(infilename, ios::in);

	if(infile.is_open()){
		string lineToRead;
		while(infile){  //Operator Overloading
			getline(infile,lineToRead,':'); //Getting line with :
			int population;
			infile>>population;  //Getting integer from that line
			//infile.get();
			infile>>ws; // either infile.get or infile>>ws both read whitespace char in file
			if(!infile){
			break;
			}
			cout<<"'"<<lineToRead<<"'"<<"-->"<< "'"<<population<<"'"<<endl;
		}
		infile.close();
	}
	else{
		cout<<"Cannot open file: "<<infilename<<endl;
	}
	return 0;

}

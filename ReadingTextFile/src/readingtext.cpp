#include <iostream>
#include <fstream>
using namespace std;


int main()
{

	ifstream infile;
	string infilename = "text.txt";

	infile.open(infilename, ios::in);

	if(infile.is_open()){

		string lineToRead;
		while(infile){  //Operator Overloading
			getline(infile,lineToRead);
			cout<<"String in File: "<<lineToRead<<endl;
		}
		infile.close();
	}
	else{
		cout<<"Cannot open file"<<infilename<<endl;

	}
	return 0;

}

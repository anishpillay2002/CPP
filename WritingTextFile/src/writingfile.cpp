/*
 * writingfile.cpp
 *
 *  Created on: Jan 26, 2019
 *      Author: anishpillay
 */


#include <iostream>
#include <fstream>
using namespace std;


int main()
{

	fstream outfile;
	string outfilename = "text.txt";

	outfile.open(outfilename, ios::out);

	if(outfile.is_open()){
		outfile<<"Hello. Anish Changed the file"<<endl;
		outfile<<"As of Jan26_2019 6pm"<<endl;
		outfile.close();
		cout<<"Wrote this file"<<outfilename<<endl;
	}
	else{
		cout<<"Could not write file"<<outfilename<<endl;

	}
	return 0;

}



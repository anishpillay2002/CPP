/*
 * maps.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: anishpillay
 */

// map stores key value pairs

#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string,int> ages;

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;


	ages["Mike"] = 70;
	pair<string,int> addToMap("Peter",14);
	ages.insert(addToMap);



	ages.insert(pair<string,int>("Lucky",67));//

	// A sshortcut way of creating pair variables
	ages.insert(make_pair("YoYo",49));

	cout<<ages["Raj"]<<endl;

	cout<<ages["Sue"]<<endl;

	if(ages.find("Vicky") != ages.end()){
		cout<<"Found Vicky" <<endl;
	}
	else
	{
		cout<<"Key not found"<<endl;
	}


	for(map<string, int>::iterator it=ages.begin();it!=ages.end();it++){
		pair<string, int> age =*it;// either use the pair initialization to access key value or use pointer references as in second iterator
		cout<< age.first <<": "<< age.second <<endl;

	}

	for(map<string, int>::iterator it=ages.begin();it!=ages.end();it++){
		cout<< it->first <<": "<< it->second <<endl;

	}


	return 0;

}

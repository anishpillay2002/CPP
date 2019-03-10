/*
 * MultiMap.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: anishpillay
 */


#include <iostream>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(100, "Vicky"));
	lookup.insert(make_pair(21, "Ram"));
	lookup.insert(make_pair(30, "Ronny")); // In normal map, string ronny would have replaced mike but in multimap it creates multiple entries
	lookup.insert(make_pair(14, "Linda"));


	for(multimap<int, string>::iterator it=lookup.begin();it !=lookup.end();it++)
	{
		cout<< it->first<< ": "<<it->second<<endl;
	}

	cout<<"Finding Value"<<endl;

	for(multimap<int, string>::iterator it=lookup.find(21);it !=lookup.end();it++)
	{
		cout<< it->first<< ": "<<it->second<<endl;
	}

	cout<< "Finding Range"<<endl;
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

	for(multimap<int, string>::iterator it = its.first; it != its.second; it++)
	{
		cout<< it->first<< ": "<<it->second<<endl;
	}

	cout<< "Finding Range- Better way of writing in CPP11"<<endl;
	auto its2 = lookup.equal_range(30);

	for(multimap<int, string>::iterator it = its2.first; it != its2.second; it++)
	{
		cout<< it->first<< ": "<<it->second<<endl;
	}

	return 0;

}



#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;
#include <sstream> 


class StringManip
{
public:
	struct queryParse {
		int id, att;
	};
	vector<string> getSubString(string str, char delimitr);
	bool CheckStartOrEnd(string str);
	string removeUnwanted(string str);
};
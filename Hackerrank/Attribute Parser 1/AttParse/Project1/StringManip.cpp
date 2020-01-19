#include "AttParse.h"
#include "StringManip.h"

vector<string> StringManip::getSubString(string str, char delimitr)
{
	stringstream ss(str);
	string token;
	vector<string> tokens;
	while (getline(ss, token, delimitr)) {
		tokens.push_back(token);
	}
	return tokens;
}

bool StringManip::CheckStartOrEnd(string str)
{
	string s2 = "</";
	if ((str.compare(0, 2, s2)) == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

string StringManip::removeUnwanted(string str)
{
	str.erase(std::remove(str.begin(), str.end(), '/'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\\'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '<'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '>'), str.end());
	return str;
}

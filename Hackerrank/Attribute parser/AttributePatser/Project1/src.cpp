#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;
#include <sstream> 



void DisplayNotFound()
{
	cout << "Not Found!" << endl;
}


class TagNode
{
public:
	vector<string> TagIdVec;
	string TagId;
	string TagAttribute;
	map<string, string> AttValue;
	int Ts;
	bool tagClosed = false;

	TagNode()
	{
	}
	void setId(vector<string> InTagIdVec)
	{
		TagIdVec = InTagIdVec;
		stringstream tmpStr;
		string delimiter = ".";
		copy(InTagIdVec.begin(), InTagIdVec.end(), ostream_iterator<string>(tmpStr, delimiter.c_str()));
		TagId = tmpStr.str();
		TagId.pop_back();

	}
	string getId()
	{
		return TagId;

	}
	void setVal(string TagAttribute, string TagVal)
	{

		AttValue[TagAttribute] = TagVal;
	}
	string getVal(string TagAttribute)
	{
		if (AttValue.count(TagAttribute) > 0)
			return AttValue[TagAttribute];
		else
		{
			DisplayNotFound();
			return "" ;
		}
	}


	void closeTag(int Ts)
	{
		if (Ts == 1)
		{
			tagClosed = true;
		}

	}

	struct Finder {
		Finder(string const & n) : name(n) { }
		bool operator () (const TagNode & el) const {
			return el.TagId== name;
		}
		string name;
	};

};



class stringManip
{
public:
	struct queryParse {
		int id, att;
	};
	vector<string> getSubString(string str, char delimitr)
	{
		stringstream ss(str);
		string token;
		vector<string> tokens;
		while (getline(ss, token, delimitr)) {
			tokens.push_back(token);
		}
		return tokens;
	}
	bool CheckStartOrEnd(string str)
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
	string removeUnwanted(string str)
	{
		str.erase(std::remove(str.begin(), str.end(), '/'), str.end());
		str.erase(std::remove(str.begin(), str.end(), '\\'), str.end());
		str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
		str.erase(std::remove(str.begin(), str.end(), '<'), str.end());
		str.erase(std::remove(str.begin(), str.end(), '>'), str.end());
		return str;
	}

};



int main1() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int LinesOfCode, NumOfQueries;

	cin >> LinesOfCode;
	cin >> NumOfQueries;
	vector<TagNode> tn;
	stringManip sm;
	vector<string> prevStr;
	int tnId = 0;
	for (int i = 0; i <= LinesOfCode; i++)
	{
		string str;
		getline(cin, str);
		if (!str.empty())
		{
			bool StartOrEnd;
			vector<string> strVec;
			strVec = sm.getSubString(str, ' ');
			StartOrEnd = sm.CheckStartOrEnd(strVec[0]);
			string strToCheck = sm.removeUnwanted(strVec[0]);
			if (StartOrEnd == 0)
			{
				prevStr.push_back(strToCheck);
				TagNode subtn;
				if (subtn.tagClosed == false)
				{
					subtn.setId(prevStr);
					subtn.setVal(strVec[1], sm.removeUnwanted(strVec[3]));
					tn.push_back(subtn);
				}
			}
			else {
				prevStr.pop_back();
				vector<TagNode>::iterator it;
				it = find_if(tn.begin(), tn.end(), TagNode::Finder(strToCheck));
				if (it != tn.end()) {
					it->closeTag(1);
				}
			}
		}
	}
	for (int i = 0; i < NumOfQueries; i++)
	{
		string str;
		getline(cin, str);
		if (str.empty() == 1)
		{	
			DisplayNotFound();
			continue;
		}
		bool notFound = false;
		vector<string> qryVec;
		qryVec = sm.getSubString(str, '~');
		if (qryVec.size() == 2)
		{
			vector<TagNode>::iterator it;
			it = find_if(tn.begin(), tn.end(), TagNode::Finder(qryVec[0]));
			if (it != tn.end()) {

				string tmpStr = it->getVal(qryVec[1]);
				if (!tmpStr.empty())
					cout << tmpStr << endl;
			}
			else
			{
				DisplayNotFound();
			}
		}
		else
			DisplayNotFound();

	}
	
	return 0;
}

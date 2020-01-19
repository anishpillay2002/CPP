#include "AttParse.h"

class TagNode
{
public:
	vector<string> TagIdVec;
	string TagId;
	string TagAttribute;
	map<string, string> AttValue;
	int Ts;
	bool tagClosed = false;
	struct Finder {
		Finder(string const & n) : name(n) { }
		bool operator () (const TagNode & el) const {
			return el.TagId == name;
		}
		string name;
	};

	TagNode();
	void setId(vector<string> InTagIdVec);
	string getId();
	void setVal(string TagAttribute, string TagVal);
	string getVal(string TagAttribute);
	void closeTag(int Ts);

};


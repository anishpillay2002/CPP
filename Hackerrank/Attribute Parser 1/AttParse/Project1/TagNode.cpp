#include "TagNode.h"
TagNode::TagNode()
{
}

void TagNode::setId(vector<string> InTagIdVec)
{
	TagIdVec = InTagIdVec;
	stringstream tmpStr;
	string delimiter = ".";
	copy(InTagIdVec.begin(), InTagIdVec.end()-1, ostream_iterator<string>(tmpStr, delimiter.c_str()));
	TagId = tmpStr.str();

}

string TagNode::getId()
{
	return TagId;

}

void TagNode::setVal(string TagAttribute, string TagVal)
{
	AttValue[TagAttribute] = TagVal;
}

string TagNode::getVal(string TagAttribute)
{
	if (AttValue.count(TagAttribute) > 0)
		return AttValue[TagAttribute];
	else
	{
		DisplayNotFound();
		return "";
	}
}


void TagNode::closeTag(int Ts)
{
	if (Ts == 1)
	{
		tagClosed = true;
	}

}
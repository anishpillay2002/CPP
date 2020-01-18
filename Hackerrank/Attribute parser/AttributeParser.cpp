#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#include <sstream> 

class TagNode
{
    public:
    vector<string> TagIdVec;
    string TagId;
    string TagAttribute;
    string TagVal;
    map<string, string> AttValue;
    int Ts;
    bool tagClosed = false;

    TagNode()
    {
    }
    void setId(vector<string> TagIdVec)
    {
        TagIdVec = TagIdVec;
        TagId = TagIdVec.back();

    }
    string getId()
    {
        return TagId;

    }
    void setVal(string TagAttribute,string TagVal)
    {
        
        AttValue[TagAttribute] =TagVal;
    }
    void closeTag(int Ts)
    {
        if(Ts == 1)
        {tagClosed = true;}

    }
};

class stringManip
{
    public:
    vector<string> getSubString(string str)
    {
        stringstream strTmp(str); 
        string token;
        vector<string> tokens;
        while (getline(strTmp, token, ' ')) {
            tokens.push_back(token);
        }
        return tokens;
    }
    bool CheckStartOrEnd(string str)
    {
        string s2 = "</";
        if((s2.compare(0, 2, str)) == 0) 
        { return true;}
        else {
        return false;
        }
    }
    string removeUnwanted(string str)
    {
        str.erase(std::remove(str.begin(), str.end(), '/'), str.end());
        str.erase(std::remove(str.begin(), str.end(), '<'), str.end());
        str.erase(std::remove(str.begin(), str.end(), '>'), str.end());
        return str;
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int LinesOfCode,NumOfQueries;

    cin>>LinesOfCode>>NumOfQueries;
    TagNode tn[NumOfQueries];
    stringManip sm;
    vector<string> prevStr;
    int tnId = 0;
    for(int i =0;i<=LinesOfCode;i++)
    {
        string str;
        getline(cin, str);
        if(!str.empty())
        {
            bool StartOrEnd;
            vector<string> strVec;
            strVec = sm.getSubString(str);
            StartOrEnd = sm.CheckStartOrEnd(strVec[0]);
            string strToCheck = sm.removeUnwanted(strVec[0]);
            if(StartOrEnd == 0)
            {
                prevStr.push_back(strToCheck);
                if(tn[tnId].tagClosed == false)
                {
                    tn[tnId].setId(prevStr);
                    tn[tnId].setVal(strVec[1],strVec[3]);
                    tnId++;
                }
            }
            else{
                prevStr.pop_back();
                for( int j =0; j< sizeof(tn); j++)
                {
                    if(tn[j].getId().compare(strToCheck) == 1)
                    {  tn[j].closeTag(1); }
                }
            }
        }
    }
    //cout<<InputTxt;
    return 0;
}

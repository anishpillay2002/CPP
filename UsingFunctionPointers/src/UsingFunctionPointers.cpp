#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool match(string test)
{
	return test.size() ==3;
}

int countStrings(vector<string> &texts, bool (*match)(string test)){
	int tally =0;
	for(int i= 0; i<texts.size();i++)
	{
		if(match(texts[i])){
			tally++;
		}
	}
	return tally;
}


int main(){


	vector<string> texts;


	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("four");
	texts.push_back("five");
	texts.push_back("six");
	texts.push_back("seven");
	texts.push_back("eight");

	cout<<match("three")<<endl;
	cout<<match("one")<<endl;



	cout<<count_if(texts.begin(),texts.end(),match)<<endl;

	cout<<countStrings(texts,match)<<endl;
	return 0;

}

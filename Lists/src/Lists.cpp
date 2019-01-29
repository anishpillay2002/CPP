#include <iostream>
#include <list>
using namespace std;


//with lists you can enter elements in between the list , in vector you can only add to the end
//lists are made of nodes and contain pointer to next node
//whereas vector is just adjacent memory blocks
int main()
{

	list<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);


	list<int>::iterator it=numbers.begin();
	cout<<"Element: "<<*it<<endl;

	it++;
	numbers.insert(it,100);
	cout<<"Element 2: "<<*it<<endl;


	list<int>::iterator  eraseIt = numbers.begin();
	eraseIt++;

	eraseIt = numbers.erase(eraseIt);
	cout<<"Element Erase2: "<<*eraseIt<<endl;

	cout<<"first Iterator"<<endl;
	for (list<int>::iterator it=numbers.begin();it!=numbers.end();it++){ // you cant +=2 ,only ++ or --
		cout<<*it<<endl;
	}

	cout<<"Messing with list"<<endl;
	// you cant +=2 ,only ++ or -- for a pointer of list type
	for (list<int>::iterator it=numbers.begin();it!=numbers.end();){
		if(*it ==2)
		{
			numbers.insert(it,1234);
		}
		if(*it ==1)
		{
			it = numbers.erase(it);
		}
		else{
			it++;
		}
		cout<<*it<<endl;
	}


	cout<<"Final Iterator"<<endl;
	for (list<int>::iterator it=numbers.begin();it!=numbers.end();it++){ // you cant +=2 ,only ++ or --
		cout<<*it<<endl;
	}



	return 0;
}

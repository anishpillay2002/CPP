#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> numbers(0);

	cout<<"Size: "<<numbers.size()<<endl;


	int capacity = numbers.capacity();
	cout<<"Capacity "<<capacity<<endl;
	for (int i=0;i<10000;i++)
	{
		if (numbers.capacity()!=capacity){
			capacity=numbers.capacity();
			cout<<"New Capacity at "<<i<<": "<<capacity<<endl;
		}
		numbers.push_back(i);
	}


	numbers.reserve(100000);
	//numbers.clear();
	cout<<"Size: "<<numbers.size()<<endl;
	cout<<"Capacity "<<numbers.capacity()<<endl;// Once capacity is set previously, it needs to be reinitialized for the memory to clear
	return 0;

}

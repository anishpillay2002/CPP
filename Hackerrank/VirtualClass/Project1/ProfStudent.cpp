#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;
#include <sstream> 
static int nextPID = 0;
static int nextSID = 0;

class Person
{
protected:

public:

	string name;
	int age;
	virtual void getdata()
	{
	}

	virtual void putdata()
	{
	}

};

class Professor :public Person
{
public:
	int publications;
	int cur_id;

	Professor()
	{
		nextPID++;
		cur_id = nextPID;
	}

	void getdata()
	{
		cin >> name >> age >> publications;
	}

	void putdata()
	{
		cout << name << " " << age << " " << publications << " " << cur_id;
	}
};

class Student :public Person
{
public:
	int marks[6];
	int cur_id;
	Student()
	{
		nextSID++;
		cur_id = nextSID;
	}
	void getdata()
	{
		cin >> name >> age;

		for (int i = 0; i < 6; i++)
		{
			cin >> marks[i];
		}
	}
	int arraySum(int a[], int n)
	{
		int initial_sum = 0;
		return accumulate(a, a + n, initial_sum);
	}
	void putdata()
	{
		int n = sizeof(marks) / sizeof(marks[0]);
		cout << name << " " << age << " " << arraySum(marks, n) << " " << cur_id;
	}
};


int main()
{
	int numOfPpl;
	cin >> numOfPpl;
	Person* bptr[100];
	Professor tmpP[10];
	Student tmpS[10];
	int ptype;
	int j=0;
	int k = 0;

	for (int i = 0; i < numOfPpl; i++)
	{
		cin >> ptype;
		if (ptype == 1)
		{
			bptr[i] = &tmpP[j]; 
			bptr[i]->getdata();
			j++;
		}
		else {
			bptr[i] = &tmpS[k];
			bptr[i]->getdata();
			k++;
		}
	}

	// Print
	for (int i = 0; i < numOfPpl; i++)
	{
		bptr[i]->putdata();
		cout << endl;
	}

	cout << "Hurray";
}



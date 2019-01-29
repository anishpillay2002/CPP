/*
 * TwoDimensionalVector.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: anishpillay
 */


#include <iostream>
#include <vector>

using namespace std;

int main()
{

	/* Number of Row= 3; Number of Column = 4 and Initialize all values of the vector with 7*/
	vector< vector<int> > grid(3,vector<int>(4, 7)); //FYI : grid is variable name and not an inbuilt function


	grid[1].push_back(8);// vector does not need to have same number of elements in each row or column... interesting
	for (int row =0; row<grid.size();row++)
	{
		for (int col=0;col<grid[row].size();col++)
		{
			cout<< grid[row][col]<< flush;
		}
		cout<<endl;
	}


}


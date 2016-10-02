#include "Output.h"



Output::Output()
{
}


Output::~Output()
{
}


void Output::Print1DVector(vector<int> &v)
{
	for (auto & it : v)
	{
		cout << it << " ";
	}
	cout << "\n";
}	

void Output::Print2DVector(vector<vector<int>> &v)
{
	for (auto &outer : v)
	{
		Print1DVector(outer);
	}
}
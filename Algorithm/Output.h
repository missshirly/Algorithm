#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Output
{
public:
	Output();
	~Output();
	static void Print1DVector(vector<int> &v);
	static void Print2DVector(vector<vector<int>> &v);
};


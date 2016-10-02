#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
class ParseFile
{
public:
	ParseFile(string filename);
	~ParseFile();
	void ParseTo1DArray(vector<vector<int>> &v);
	void ParseString(vector<string> &strs);
	void Parse2DPoints(list<pair<int, int>> &ls);
protected:
	ifstream _input;
};


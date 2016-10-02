#include "ParseFile.h"



ParseFile::ParseFile(string filename):_input(filename)
{
	
}


ParseFile::~ParseFile()
{
}

void ParseFile::ParseTo1DArray(vector<vector<int>> &v)
{
	string line;
	while (getline(_input, line))
	{
		line.erase(line.find('['), 1);
		line.erase(line.find(']'), 1);
		string token;
		istringstream ss(line);
		vector<int> cur;
		while (getline(ss, token, ','))
		{
			cur.push_back(stoi(token));
		}
		v.push_back(cur);
	}
}

void ParseFile::ParseString(vector<string> &strs)
{
	string str;
	while (getline(_input, str))
	{
		str.erase(str.find('"'), 1);
		str.erase(str.find('"'), 1);
		strs.push_back(str);
	}
}

void ParseFile :: Parse2DPoints(list<pair<int, int>> &ls)
{
	string line;
	while (getline(_input, line))
	{
		istringstream ss(line);
		string token;
		pair<int, int> point;
		int i = 0;
		while (getline(ss, token, ','))
		{
			if (i == 0) point.first = stoi(token);
			else point.second = stoi(token);
			++i;
		}
		ls.push_back(point);
	}
}
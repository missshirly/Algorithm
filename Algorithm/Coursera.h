#pragma once
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <string>
using namespace std;
class Coursera
{
public:
	Coursera();
	~Coursera();
	static int RomanToInt(string &str);
	static bool checkDuplicate(int num);
	static vector<pair<string, string>> getSortedList(vector<pair<string, string>> &v);
	static string findMaxSubstring(string &str);
	static int arrayReduction(vector<int> &v);
	static list<pair<int, int>> findNonDominEntities1(list<pair<int, int>> &v);
	static int getLovelyNoWithinRange(int low, int high);
	static int getLovelyNoFromZero(int num);
	static int getLovelyNoWithinRange1(int low, int high);
};


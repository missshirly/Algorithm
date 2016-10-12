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
class CC150
{
public:
	//return index of the Min ( all lements are unique)
	static int FindMinInRotatedSortedArray(vector<int> &v);
	static int FindElementInCirularSortedArray(vector<int> &v, int x);
	//Chapter 1
	static bool isUnique(char *str);
	static void reverse(char *str);
	static bool isPermutation(string &a, string &b);
	static void replaceSpace(char *str, int len);
	static void compressString(string &str);
	CC150();
	~CC150();
};


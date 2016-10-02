#include "Coursera.h"



Coursera::Coursera()
{
}


Coursera::~Coursera()
{
}

int Coursera::RomanToInt(string &str)
{
	if (str.empty()) return 0;
	unordered_map<char, int> mp = { { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 } };
	int res = mp[str[str.size() - 1]];
	for (int i = str.size() - 2; i >= 0; --i)
	{
		if (mp[str[i]] < mp[str[i + 1]])
		{
			res += -mp[str[i]];
		}
		else res += mp[str[i]];
	}
	return res;
}






bool Coursera::checkDuplicate(int num)
{
	string str = to_string(num);
	unordered_set<int> set;
	for (auto &it : str)
	{
		if (set.find(it) != set.end()) return false;
		set.insert(it);
	}
	return true;
}

vector<pair<string, string>> Coursera::getSortedList(vector<pair<string, string>> &v)
{
	vector<pair<string, string>> res;
	map<string, map<int, vector<int>>> mp;
	int i = 0;
	for (auto &it : v)
	{
		mp[it.first][RomanToInt(it.second)].push_back(i++);
	}
	for (auto &it1 : mp)
	{
		for (auto &it2 : it1.second)
		{
			for (auto &pos : it2.second)
			{
				res.push_back(v[pos]);
			}
		}
	}
	return res;
}

string Coursera::findMaxSubstring(string &str)
{
	if (str.empty()) return str;
	int size = str.size();
	int right = size - 1;
	for (int i = str.size() - 2; i >= 0; --i)
	{
		if (str[i] > str[right]) right = i;
		else if (str[i] == str[right])
		{
			int lenLeft = size - right, lenRight = right - i;
			int times = min(lenLeft - 1, lenRight - 1);
			int l1 = i + 1, r1 = right + 1;
			while (times > 0)
			{
				if (str[l1] > str[r1])
				{
					right = i;
					break;
				}
				++l1;
				++r1;
				--times;
			}
			if (r1 == size && lenLeft > lenRight || l1 - 1 == i) right = i;
		}
	}
	return str.substr(right, size - right);
}

int Coursera::arrayReduction(vector<int> &v)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (auto &it : v)
	{
		minHeap.push(it);
	}
	int first, second;
	int res = 0;
	while (minHeap.size() > 1)
	{
		first = minHeap.top();
		minHeap.pop();
		second = minHeap.top();
		minHeap.pop();
		int newValue = first + second;
		res += newValue;
		minHeap.push(newValue);
	}
	return res;
}



struct Cmp
{
	bool operator ()(const pair<int, int> &a, const pair<int, int> &b)
	{
		return (a.first > b.first) || (a.first == b.first && a.second < b.second);
	}
};

list<pair<int, int>> Coursera::findNonDominEntities1(list<pair<int, int>> &v)
{
	set<pair<int, int>, Cmp> set;

	for (auto &it : v)
	{
		set.insert(it);
	}
	list<pair<int, int>> res;
	int preY = set.begin()->second;
	int cnt = 0;
	for (auto &it : set)
	{
		int curY = it.second;
		if (curY >= preY)
		{
			++cnt;
			res.push_back(it);
			preY = curY;
		}
	}

	return res;
}
int Coursera::getLovelyNoWithinRange(int low, int high)
{
	int cnt = 0;
	for (int i = low; i <= high; ++i)
	{
		if (checkDuplicate(i)) ++cnt;
	}
	return cnt;
}

int Coursera::getLovelyNoFromZero(int num)
{
	if (num < 10) return num + 1;
	string str = to_string(num);
	int n = str.size();

	int res = 0;
	int tmp = 10;
	res += tmp;
	for (int i = 2; i < n; ++i)
	{
		tmp = 9;
		for (int j = 1; j < i; ++j)
		{
			tmp *= (10 - j);
		}
		res += tmp;
		//cout << tmp << "," << res << endl;
	}
	unordered_set<int> used;

	tmp = str[0] - '1';
	for (int i = 2; i <= n; ++i)
	{
		tmp *= (11 - i);
	}
	res += tmp;


	used.insert(str[0] - '0');
	//i : index of string
	for (int i = 1; i < n; ++i)
	{
		tmp = 0;
		int cur = str[i] - '0';
		for (int j = 0; j < cur; ++j)
		{
			if (used.find(j) == used.end()) ++tmp;
		}
		if (i == n - 1 && used.find(cur) == used.end()) ++tmp;
		for (int j = i + 1; j < n; ++j)
		{
			tmp *= (10 - j);
		}
		res += tmp;
		used.insert(cur);
	}
	return res;
}

int Coursera::getLovelyNoWithinRange1(int low, int high)
{
	return getLovelyNoFromZero(high) - getLovelyNoFromZero(low - 1);
}




#include "Yahoo.h"



Yahoo::Yahoo()
{
}


Yahoo::~Yahoo()
{
}

int Yahoo::FindMinInSymetricOrderedArray(vector<int> &v) {
	int n = v.size();
	if (n < 3) return n - 1;
	int l = 0, r = n - 1;
	while ((r - l) >= 2) {
		int mid = l + (r - l) / 2;
		if (v[mid] <= v[mid - 1] && v[mid] <= v[mid + 1]) return mid;
		else if (v[mid] <= v[mid - 1] && v[mid] >= v[mid + 1]) l = mid;
		else if (v[mid] >= v[mid - 1] && v[mid] <= v[mid + 1]) r = mid;
	}
	return -1;
}

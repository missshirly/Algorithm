#include "C150.h"



CC150::CC150()
{
}


CC150::~CC150()
{
}
// int CC150::FindMinInRotatedSortedArray(vector<int> &v)
//{
//	int l = 0, r = v.size() - 1;
//	while (l <= r) {
//		//[1,2,3,4,5] or [1](after devide)
//		if (v[l] <= v[r]) return l;
//		int mid = l + (r - l) / 2;
//		if (v[mid] < v[l])
//		{
//			//[4,5,1,2,3]
//			if (v[mid] < v[mid - 1]) return mid;
//			r = mid - 1;
//		}
//		else if (v[mid] > v[r]) l = mid + 1;
//	}
//	return -1;
//}

int CC150::FindMinInRotatedSortedArray(vector<int> &v)
{
	int n = v.size();
	int l = 0, r = n - 1;
	int mid, pre, next;
	while (l <= r) {
		//if (v[l] <= v[r]) return l; //fast the speed
		mid = l + (r - l) / 2;
		pre = (mid + n - 1) % n;
		next = (mid + 1) % n;
		// = is for when there's only one elment.
		if (v[mid] <= v[pre] && v[mid] <= v[next]) return mid;
		else if(v[mid] >= v[r]) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

 //at least one half should be sorted(might be more than one)
 int CC150::FindElementInCirularSortedArray(vector<int> &v, int x){
	 int l = 0, r = v.size() - 1;
	 while (l <= r) {
		 int mid = l + (r - l) / 2;
		 if (v[mid] == x) return mid;
		 //right half sorted
		 if (v[mid] <= v[r]) {
			 if (x > v[mid] && x <= v[r]) {
				 l = mid + 1;
			 }
			 else {
				 r = mid - 1;
			 }
		 }
		 //left half sorted
		 else if (v[mid] >= v[l]) {
			 if (x < v[mid] && x >= v[l]) {
				 r = mid - 1;
			 }
			 else {
				 l = mid + 1;
			 }
		 }
	 }
	 return -1;
 }

 bool CC150::isUnique(char *str) {
	 bool dic[256];
	 for (int i = 0; i < 256; ++i) {
		 dic[i] = false;
	 }
	 char *ch = str;
	 while (*ch != '\0') {
		 if (dic[*ch]) return false;
		 dic[*ch] = true;
		 ++ch;
	 }
	 return true;
 }

 void CC150::reverse(char *str) {
	 if (str == nullptr) return;
 	 char *left = str, *right = str;
	 while (*right != '\0' && *(right + 1) != '\0') {
		 ++left;
		 ++++right;
	 }
	 if (*right != '\0') {
		 right = left + 1;
	 }
	 else {
		 right = left;
	 }
	 --left;
	 while (*right != '\0') {
		 char tmp = *right;
		 *right = *left;
		 *left = tmp;
		 --left;
		 ++right;
	 }
 }

 bool CC150::isPermutation(string &a, string &b) {
	 int dic[256];
	 for (int i = 0; i < 256; ++i) {
		 dic[i] = 0;
	 }
	 for (auto &it : a) {
		 ++dic[it];
	 }
	 for (auto &it : b) {
		 if (--dic[it] < 0) return false;
	 }
	 return true;
 }


 void CC150::replaceSpace(char *str, int len) {
	 char *ch = str, *lastChar = nullptr;
	 int spaceCnt = 0;
	 while (*ch != '\0') {
		 if(isspace(*ch)) ++spaceCnt;
		 else lastChar = ch;
		 ++ch;
	 }
	 int end = len + spaceCnt * 2;
	 while (len >= 0) {
		 char cur =  *(str + len);
		 if (isspace(cur)) {
			 *(str + end--) = '0';
			 *(str + end--) = '2';
			 *(str + end--) = '%';
		 }
		 else {
			 *(str + end--) = cur;
		 }
		 --len;
	 }
 }

 int countDigits(int num) {
	 int cnt = 0;
	 while (num > 0) {
		 ++cnt;
		 num /= 10;
	 }
	 return cnt;
 }

 void CC150::compressString(string &str){
	 int dic[26];

	 for (int i = 0; i < 26; ++i) {
		 dic[i] = 0;
	 }
	 for(auto &it : str) {
		 ++dic[it - 'a'];
	 }
	 int originCnt = 0, compressCnt = 0;
	 string cmp;
	 for (int i = 0; i < 26; ++i) {
		 originCnt += dic[i];
		 //Don't forget this validation 
		 if (dic[i] > 0) {
			 compressCnt += countDigits(dic[i]);
			 ++compressCnt;
			 cmp.push_back('a' + i);
			 cmp.append(to_string(dic[i]));
		 }
	 }
	 if (originCnt > compressCnt) str = cmp;
 }
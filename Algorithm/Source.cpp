#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "ParseFile.h"
#include "Output.h"
#include "Coursera.h"
#include "C150.h"
#include "Yahoo.h"
using namespace std;

//find the number of integers with unique digits.
void testPrint(int n)
{
	int res = 0;
	int tmp = 10;
	res += tmp;
	std::cout << tmp << "," << res<<endl;
	for (int i = 2; i <= n; ++i)
	{
		tmp = 9;
		for (int j = 1; j < i; ++j)
		{
			tmp *= (10 - j);
		}
		res += tmp;
		std::cout << tmp << "," << res << endl;
	}
}



int main() {

	ParseFile ps("String.txt");
	vector<string> vec;
	ps.ParseString(vec);
	for (auto str : vec) {
		CC150::compressString(str);
		cout << str << endl;
		//char *cstr = new char[str.length() + 1];
		//strcpy(cstr, str.c_str());		
		//CC150::reverse(cstr);
		//CC150::replaceSpace(cstr,str.size());
		//cout << cstr << endl;
		/*cout << CC150::isUnique(cstr)<<CC150::reverse<<endl;*/
		//cout << Yahoo::FindMinInSymetricOrderedArray(arr) << endl;
	}


	//ParseFile ps("VectorInt.txt");
	//vector<vector<int>> vec;
	//ps.ParseTo1DArray(vec);
	//for (auto arr : vec) {
	//	cout << CC150::FindMinInRotatedSortedArray(arr) << ","
	//		<< CC150::FindElementInCirularSortedArray(arr, 4) << endl;
	//	//cout << Yahoo::FindMinInSymetricOrderedArray(arr) << endl;
	//}
	//testPrint(10);

	//cout<<Coursera::getLovelyNoWithinRange(23814,95145)<<endl;
	//cout << Coursera::getLovelyNoWithinRange(0, 9843) << endl;
	//cout << Coursera::getLovelyNoWithinRange(0, 24) << endl;
	//cout << Coursera::getLovelyNoFromZero(95145) - Coursera::getLovelyNoFromZero(23813);
	

	return 0;

}
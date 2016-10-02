#include "ParseFile.h"
#include "Output.h"
#include "Coursera.h"
using namespace std;


//find the number of integers with unique digits.
void testPrint(int n)
{
	int res = 0;
	int tmp = 10;
	res += tmp;
	cout << tmp << "," << res<<endl;
	for (int i = 2; i <= n; ++i)
	{
		tmp = 9;
		for (int j = 1; j < i; ++j)
		{
			tmp *= (10 - j);
		}
		res += tmp;
		cout << tmp << "," << res << endl;
	}
}



int main() {
	//testPrint(10);

	cout<<Coursera::getLovelyNoWithinRange(23814,95145)<<endl;
	cout << Coursera::getLovelyNoWithinRange(0, 9843) << endl;
	cout << Coursera::getLovelyNoWithinRange(0, 24) << endl;
	cout << Coursera::getLovelyNoFromZero(95145) - Coursera::getLovelyNoFromZero(23813);
	

	return 0;

}
#include "imports/test/include.h"
// this include.cpp for me,so u don't have to use it, but also u can modify them

using namespace std;

#define edl '\n'

class Data_Structures
{
public:
	Data_Structures() {}
	void TEST()
	{
		// test the DSs here;
		Vector<int> vec;
		fr(i, 1, 11) vec.push_back(i * 5);
		vec.print();
	}
};

int main()
{
	Data_Structures DS;
	// freopen("imports/test/input.txt", "r", stdin);
	freopen("imports/test/output.txt", "w", stdout);
	int tc(1);
	// cin >> tc;
	while (tc--)
		cout << "Case #" << tc + 1 << edl, DS.TEST();
	cout << edl << "DONE" << edl;
	return (0);
}
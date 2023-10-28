#include "imports/include.h"
// this include.h for me,so u don't have to use it, but also u can modify them

#define edl '\n'

class Data_Structures
{
public:
	Data_Structures() { Sukuna; }
	void TEST()
	{
		// test the Data Structures here;
	}
};

int main()
{
	Data_Structures DS;
	// freopen("imports/test/input.txt", "r", stdin);
	freopen("imports/test/output.txt", "w", stdout);
	int tc(1);
	// std::cin >> tc;
	while (tc--)
		std::cout << "Case #" << tc + 1 << edl, DS.TEST();
	std::cout << edl << "DONE" << edl;
	return (0);
}
#include "imports/test/include.cpp"

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

class Data_Structures
{
public:
	Data_Structures() { Mesh_Ali; }
	void TEST()
	{
		// test the DSs here;
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
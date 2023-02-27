#include "test/include.cpp"

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

int main()
{
	Mesh_Ali;
	// freopen("test/input.txt", "r", stdin);
	freopen("test/output.txt", "w", stdout);
	Vector<int> vec(4);
	for (int i(0); i < 4; ++i)
		cin >> vec[i];
	vec.print();
	cout << edl << "DONE" << edl;
	return (0);
}
#include "include.cpp"

using namespace std;

typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

int main()
{
	Mesh_Ali;
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	AVL_Tree<int> tree;

	for (int i(0); i < 11; ++i)
		tree.insert_value(i);

	tree.print_in_order();
	cout << edl;
	tree.print_in_order();

	cout << edl << "DONE" << edl;
	return (0);
}

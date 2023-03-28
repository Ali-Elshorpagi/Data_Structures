#include "test/include.cpp"

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

Binary_Search_Tree<int> *GetTree()
{
	Binary_Search_Tree<int> *tree = new Binary_Search_Tree<int>(50);
	tree->insert(20);
	tree->insert(60);
	tree->insert(15);
	tree->insert(45);
	tree->insert(70);
	tree->insert(35);
	tree->insert(73);

	tree->insert(14);
	tree->insert(16);
	tree->insert(36);
	tree->insert(58);
	return tree;
}

int main()
{
	Mesh_Ali;
	// freopen("test/input.txt", "r", stdin);
	freopen("test/output.txt", "w", stdout);
	Binary_Search_Tree<int> *tree = GetTree();
	cout << tree->min_value() << ' ' << tree->max_value() << edl;

	cout << edl << "DONE" << edl;
	return (0);
}
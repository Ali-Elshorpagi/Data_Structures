#include <bits/stdc++.h>
#include "include.cpp"

using namespace std;

typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

int main()
{
	Mesh_Ali;
	Binary_Search_Tree<int> tree(4);
	tree.insert(1);
	tree.insert(7);
	tree.insert(5);
	tree.insert(47);
	tree.insert(2);
	tree.insert(-34);
	tree.print_in_order();
	cout << edl;

	cout << tree.max_value() << ' ' << tree.min_value() << edl;
	cout << edl << "DONE" << edl;
	return 0;
}
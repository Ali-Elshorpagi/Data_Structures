#include <bits/stdc++.h>
#include "include.cpp"

using namespace std;

typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

Binary_Search_Tree<ll> *GetTree()
{
	Binary_Search_Tree<ll> *tree = new Binary_Search_Tree<ll>(50);
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

	cout << edl << "DONE" << edl;
	return 0;
}
#include "BinaryTree.h"

template <class type>
BinaryTree<type>::BinaryTree(type data) : data(data)
{
}

template <class type>
BinaryTree<type>::~BinaryTree()
{
    clear();
}

template <class type>
void BinaryTree<type>::clear()
{
    // Don't try to call clear for children and also delete. This deletes twice!
    if (left)
        delete left, left = nullptr;
    if (right)
        delete right, left = right;
}

template <class type>
void BinaryTree<type>::add(vector<type> values, vector<char> direction)
{
	assert(values.size() == direction.size());
	BinaryTree* current = this;
	ll len((int)values.size());
	for (ll i(0); i < len; ++i)
	{
		if (direction[i] == 'L')
		{
			if (!current->left)
				current->left = new BinaryTree<type>(values[i]);
			else
				assert(current->left->data == values[i]);
			current = current->left;
		}
		else
		{
			if (!current->right)
				current->right = new BinaryTree<type>(values[i]);
			else
				assert(current->right->data == values[i]);
			current = current->right;
		}
	}
}

template <class type>
void BinaryTree<type>::print_in_order()
{
	if (left)
		left->print_in_order();
	cout << data << ' ';
	if (right)
		right->print_in_order();
}

template <class type>
void BinaryTree<type>::print_pre_order()
{
	cout << data << ' ';
	if (left)
		left->print_pre_order();
	if (right)
		right->print_pre_order();
}


template <class type>
void BinaryTree<type>::print_post_order()
{
	if (left)
		left->print_post_order();
	if (right)
		right->print_post_order();
	cout << data << ' ';
}

template <class type>
type BinaryTree<type>::tree_max()
{
	type mx = data;
	if (left)
		mx = max(mx, left->tree_max());
	if (right)
		mx = max(mx, right->tree_max());

	return mx;
}
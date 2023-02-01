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

template <class type>
ll BinaryTree<type>::tree_height()
{
	ll height(0);
	if (left)
		height = 1 + left->tree_height();
	if (right)
		height = max(height, 1 + right->tree_height());
	return height;
}

template <class type>
ll BinaryTree<type>::total_nodes() 
{
	ll cnt(1);
	if (left)
		cnt += left->total_nodes();
	if (right)
		cnt += right->total_nodes();
	return cnt;
}

template <class type>
ll BinaryTree<type>::no_leaf_nodes() 
{
	ll cnt (!left && !right);
	if (left)
		cnt += left->no_leaf_nodes();
	if (right)
		cnt += right->no_leaf_nodes();
	return cnt;
}

template <class type>
bool BinaryTree<type>::is_exists(type value)
{
	bool res(value == data);
	if (!res && left)
		res = left->is_exists(value);
	if (!res && right)
		res = right->is_exists(value);
	return res;
}
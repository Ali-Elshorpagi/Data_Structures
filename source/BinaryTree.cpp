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

template <class type>
bool BinaryTree<type>::is_perfect_fomula()
{
	ll height (tree_height());
	ll nodes (total_nodes());
	ll res = pow(2, (height + 1)) - 1;
	return (res == nodes);
}


template <class type>
bool BinaryTree<type>::is_perfect(ll h)
{
	if (h == -1) // first call
		h = tree_height();

	if (!left && !right)
		return h == 0;

	if (!left && right || left && !right)
		return false; 
	return left->is_perfect(h - 1) && right->is_perfect(h - 1);
}

template <class type>
void BinaryTree<type>::print_inorder_iterative()
{
	stack<pair<BinaryTree<type>*, bool>> nodes;
	nodes.push(make_pair(this, false));
	while (!nodes.empty())
	{
		BinaryTree<type>* current(nodes.top().first);
		bool is_done(nodes.top().second);
		nodes.pop();
		if (is_done)
			cout << current->data << ' ';
		else
		{
			if (current->right)
				nodes.push(make_pair(current->right, false));
			nodes.push(make_pair(current, true));
			if (current->left)
				nodes.push(make_pair(current->left, false));
		}
	}
	cout << edl;
}

template <class type>
void BinaryTree<type>::traverse_left_boundry()
{
	cout << data << ' ';
	if (left)
		left->traverse_left_boundry();
	else if (right)
		right->traverse_left_boundry();
}

template <class type>
pair<ll,ll> BinaryTree<type>::tree_diameter() 
{
	pair<ll, ll> res(make_pair(0, 0));
	if (!left && !right)
		return res;
	pair<ll, ll> left_diam(make_pair(0, 0));
	pair<ll, ll> right_diam(make_pair(0, 0));
	if (left)
		left_diam = left->tree_diameter(), res.first += 1 + left_diam.second;
	if (right)
		right_diam = right->tree_diameter(), res.first += 1 + right_diam.second;
	// diameter if in one of my children subtrees
	res.first = max(res.first, max(left_diam.first, right_diam.first));
	// normal height computation
	res.second = 1 + max(left_diam.second, right_diam.second);
	return res;
}

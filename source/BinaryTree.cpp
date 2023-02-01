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


template <class type>
void BinaryTree<type>::level_order_traversal_0()
{
	queue<BinaryTree<type>*> nodes_queue;
	nodes_queue.push(this);
	while (!nodes_queue.empty())
	{
		BinaryTree<type>* cur(nodes_queue.front());
		nodes_queue.pop();
		cout << cur->data << ' ';
		if (cur->left)
			nodes_queue.push(cur->left);
		if (cur->right)
			nodes_queue.push(cur->right);
	}
	cout << edl;
}

template <class type>
void BinaryTree<type>::level_order_traversal_1()
{
	queue<BinaryTree*> nodes_queue;
	nodes_queue.push(this);
	ll level(0),sz;
	while (!nodes_queue.empty())
	{
		sz = nodes_queue.size();
		cout << "Level " << level << ": ";
		while (sz--)
		{
			BinaryTree<type>* cur(nodes_queue.front());
			nodes_queue.pop();
			cout << cur->data << ' ';
			if (cur->left)
				nodes_queue.push(cur->left);
			if (cur->right)
				nodes_queue.push(cur->right);
		}
		++level;
		cout << edl;
	}
}

template <class type>
void BinaryTree<type>::print_level_nodes(ll level)
{
	if (!level)
		cout << data << ' ';
	else if (level)
	{
		if (left)
			left->print_level_nodes(level - 1);
		if (right)
			right->print_level_nodes(level - 1);
	}
}

template <class type>
void BinaryTree<type>::level_order_traversal_recursive() // O(N^2)
{
	ll height(tree_height());
	for (ll level(0); level <= height; ++level)
		print_level_nodes(level);
}

template <class type>
void BinaryTree<type>::level_order_traversal_spiral()
{
	deque<BinaryTree*> nodes_deque;
	nodes_deque.push_back(this);
	ll level(0), sz;
	bool flag(true);
	while (!nodes_deque.empty())
	{
		sz = nodes_deque.size();
		cout << "Level " << level << ": ";
		while (sz--)
		{
			BinaryTree<type>* cur;
			if (flag)
			{
				cur = nodes_deque.front();
				nodes_deque.pop_front();
				if (cur->left)
					nodes_deque.push_back(cur->left);
				if (cur->right)
					nodes_deque.push_back(cur->right);
			}
			else 
			{
				cur = nodes_deque.back();
				nodes_deque.pop_back();
				if (cur->right)
					nodes_deque.push_front(cur->right);
				if (cur->left)
					nodes_deque.push_front(cur->left);
			}
			cout << cur->data << ' ';
		}
		flag = !flag, ++level;
		cout << edl;
	}
}


template <class type>
bool BinaryTree<type>::is_complete()
{
	queue<BinaryTree<type>*> nodes_queue;
	nodes_queue.push(this);
	bool no_more_allowed(false);
	while (!nodes_queue.empty())
	{
		ll sz(nodes_queue.size());
		while (sz--)
		{
			BinaryTree<type>* cur(nodes_queue.front());
			nodes_queue.pop();
			if (cur->left)
			{
				if (no_more_allowed)
					return false;
				nodes_queue.push(cur->left);
			}
			else
				no_more_allowed = true;

			if (cur->right)
			{
				if (no_more_allowed)
					return false;
				nodes_queue.push(cur->right);
			}
			else
				no_more_allowed = true;
		}
	}
	return true;
}


template <class type>
BinaryTree<type>::BinaryTree(deque<ll>& preorder, deque<ll>& inorder, ll inorder_start, ll inorder_end)
{
	if (inorder_end == -1)
		inorder_end = (int)inorder.size() - 1;
	data = preorder[0];
	preorder.pop_front();
	for (ll split (inorder_start); split <= inorder_end; ++split)
	{
		if (inorder[split] == data)
		{
			if (inorder_start < split)
				left = new BinaryTree(preorder, inorder, inorder_start, split - 1);
			if (split < inorder_end)
				right = new BinaryTree(preorder, inorder, split + 1, inorder_end);
			break;
		}
	}
}
template <class type>
BinaryTree<type>::BinaryTree(queue<pair<ll, ll>>& preorder_queue)
{
	pair<ll, ll> p = preorder_queue.front();
	preorder_queue.pop();
	data = p.first;
	if (!p.second)
	{
		if (preorder_queue.size())
			left = new BinaryTree(preorder_queue);
		if (preorder_queue.size())
			right = new BinaryTree(preorder_queue);
	}
}

template <class type>
void BinaryTree<type>::build_preorder(queue<pair<ll, ll>>& preorder_queue)
{
	preorder_queue.push(make_pair(data, !left && !right));
	if (left)
		left->build_preorder(preorder_queue);
	if (right)
		right->build_preorder(preorder_queue);
}

template <class type>
void BinaryTree<type>::print_preorder_complete()
{
	cout << data << ' ';
	if (left)
		left->print_preorder_complete();
	else
		cout << "-1 "; 

	if (right)
		right->print_preorder_complete();
	else
		cout << "-1 "; 
}

template <class type>
string BinaryTree<type>::to_str(ll n)
{
	ostringstream oss;
	oss << n;
	return oss.str();
}
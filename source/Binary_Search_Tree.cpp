#include "..\\header\Binary_Search_Tree.h"

template <class type>
Binary_Search_Tree<type>::Binary_Search_Tree(type data) : data(data) {}

template <class type>
Binary_Search_Tree<type>::Binary_Search_Tree(deque<type> &preorder, type min, type max)
{
    data = preorder[0];
    preorder.pop_front();
    if (next_between(preorder, min, data))
        left = new Binary_Search_Tree<type>(preorder, min, data);
    if (next_between(preorder, data, max))
        right = new Binary_Search_Tree<type>(preorder, data, max);
}

template <class type>
Binary_Search_Tree<type>::~Binary_Search_Tree()
{
    clear();
}

template <class type>
void Binary_Search_Tree<type>::clear()
{
    // Don't try to call clear for children and also delete. This deletes twice!
    if (left)
        delete left, left = nullptr;
    if (right)
        delete right, left = right;
}

template <class type>
void Binary_Search_Tree<type>::get_in_order(vector<type> &inorder_values)
{
    if (left)
        left->get_in_order(inorder_values);
    inorder_values.emplace_back(data);
    if (right)
        right->get_in_order(inorder_values);
}

template <class type>
void Binary_Search_Tree<type>::get_pre_order(deque<type> &preorder_values)
{
    preorder_values.push_back(data);
    if (left)
        left->get_pre_order(preorder_values);
    if (right)
        right->get_pre_order(preorder_values);
}

// Check if the next element in the preorder is in the range
template <class type>
bool Binary_Search_Tree<type>::next_between(deque<type> &preorder, type min, type max)
{
    if (preorder.empty())
        return false;
    return ((min < preorder[0]) && (preorder[0] < max));
}

template <class type>
void Binary_Search_Tree<type>::print_in_order()
{
    if (left)
        left->print_in_order();
    cout << data << ' ';
    if (right)
        right->print_in_order();
}

template <class type>
void Binary_Search_Tree<type>::insert(type val)
{
    if (val < data)
    {
        if (!left)
            left = new Binary_Search_Tree<type>(val);
        else
            left->insert(val);
    }
    else if (val > data)
    {
        if (!right)
            right = new Binary_Search_Tree<type>(val);
        else
            right->insert(val);
    }
}

template <class type>
bool Binary_Search_Tree<type>::search(type val)
{
    if (val == data)
        return true;
    if (val < data)
        return left && left->search(val);
    return right && right->search(val);
}

template <class type>
type Binary_Search_Tree<type>::min_value()
{
    Binary_Search_Tree<type> *cur(this);
    while (cur && cur->left)
        cur = cur->left;
    return cur->data;
}

template <class type>
type Binary_Search_Tree<type>::max_value()
{
    Binary_Search_Tree<type> *cur(this);
    while (cur && cur->right)
        cur = cur->right;
    return cur->data;
}

template <class type>
bool Binary_Search_Tree<type>::search_iterative(type val)
{
    Binary_Search_Tree<type> *root(this);
    while (root)
    {
        if (val == root->data)
            return true;
        if (root->data < val)
            root = root->right;
        else if (root->data > val)
            root = root->left;
    }
    return false;
}

template <class type>
bool Binary_Search_Tree<type>::is_bst_0(type mn, type mx)
{
    bool status((mn < data) && (data < mx));
    if (!status)
        return false;
    bool left_bst(!left || left->is_bst_0(mn, data));
    if (!left_bst)
        return false;
    bool right_bst(!right || right->is_bst_0(data, mx));
    return right_bst;
}

template <class type>
bool Binary_Search_Tree<type>::is_bst_1()
{
    vector<type> inorder_values;
    get_in_order(inorder_values);
    ll len((int)inorder_values.size());
    for (ll i(1); i < len; ++i)
        if (inorder_values[i] < inorder_values[i - 1])
            return false;

    return true;
}

template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::build_balanced_bst_tree(vector<type> &values, ll str, ll end)
{
    if (end == -1)
        end = (int)values.size() - 1;
    if (str > end)
        return nullptr;
    ll mid((str + end) >> 1);
    Binary_Search_Tree<type> *left(build_balanced_bst_tree(values, str, mid - 1));
    Binary_Search_Tree<type> *right(build_balanced_bst_tree(values, mid + 1, end));
    Binary_Search_Tree<type> *root(new Binary_Search_Tree<type>(values[mid], left, right));
    return root;
}

template <class type>
type Binary_Search_Tree<type>::kth_smallest_0(ll &k)
{
    vector<type> vals;
    get_in_order(vals);
    ll len((int)vals.size());
    if (k >= len)
        return -1234;
    else
        return vals[k - 1];
}

template <class type>
type Binary_Search_Tree<type>::kth_smallest_1(ll &k)
{
    if (k == 0)
        return -1234;
    if (left)
    {
        type res(left->kth_smallest_1(k));
        if (k == 0)
            return res;
    }
    --k;
    if (k == 0)
        return data;
    if (right)
        return right->kth_smallest_1(k);
    return -1234;
}

template <class type>
type Binary_Search_Tree<type>::LCA(type x, type y)
{
    if (data > x && data > y)
        return left->LCA(x, y);
    if (data < x && data < y)
        return right->LCA(x, y);
    return data;
}

template <class type>
bool Binary_Search_Tree<type>::find_chain(vector<Binary_Search_Tree<type> *> &ancestors, type val)
{
    ancestors.push_back(this);
    if (val == data)
        return true;
    if (val < data)
        return left && left->find_chain(ancestors, val);
    return right && right->find_chain(ancestors, val);
}

template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::get_next(vector<Binary_Search_Tree<type> *> &ancestors)
{
    if (ancestors.size() == 0)
        return nullptr;
    Binary_Search_Tree<type> *node(ancestors.back());
    ancestors.pop_back();
    return node;
}

template <class type>
pair<bool, type> Binary_Search_Tree<type>::successor(type val)
{
    vector<Binary_Search_Tree<type> *> ancestors;

    if (!find_chain(ancestors, val))
        return make_pair(false, -1);

    Binary_Search_Tree<type> *child(get_next(ancestors));

    if (child->right)
        return make_pair(true, child->right->min_value());

    Binary_Search_Tree<type> *parent(get_next(ancestors));

    while (parent && parent->right == child)
        child = parent, parent = get_next(ancestors);

    if (parent)
        return make_pair(true, parent->data);
    return make_pair(false, -1);
}
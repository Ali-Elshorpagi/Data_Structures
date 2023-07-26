#ifndef BINARY_SEARCH_TREE_CPP
#define BINARY_SEARCH_TREE_CPP

#include "../header/Binary_Search_Tree.h"

template <class type>
Binary_Search_Tree<type>::Binary_Search_Tree(type d, Binary_Search_Tree<type> *l, Binary_Search_Tree<type> *r) : data(d), left(l), right(r) {}

template <class type>
Binary_Search_Tree<type>::Binary_Search_Tree(std::deque<type> &preorder, type min, type max)
{
    data = preorder[0];
    preorder.pop_front();
    if (next_between(preorder, min, data))
        left = new Binary_Search_Tree<type>(preorder, min, data);
    if (next_between(preorder, data, max))
        right = new Binary_Search_Tree<type>(preorder, data, max);
}

template <class type>
Binary_Search_Tree<type>::Binary_Search_Tree(std::deque<type> level_order)
{
    std::queue<std::pair<Binary_Search_Tree<type> *, std::pair<int, int>>> nodes_queue;
    data = level_order[0];
    level_order.pop_front();
    nodes_queue.push(range(this, INT_MIN, INT_MAX));
    while (!nodes_queue.empty())
    {
        int sze(nodes_queue.size());
        while (sze--)
        {
            Binary_Search_Tree<type> *cur(nodes_queue.front().first);
            type mn(nodes_queue.front().second.first);
            type mx(nodes_queue.front().second.second);
            type data(cur->data);
            nodes_queue.pop();
            if (next_between(level_order, mn, data))
            {
                type new_data(level_order[0]);
                level_order.pop_front();
                cur->left = new Binary_Search_Tree<type>(new_data);
                nodes_queue.push(range(cur->left, mn, data));
            }
            if (next_between(level_order, data, mx))
            {
                type new_data(level_order[0]);
                level_order.pop_front();
                cur->right = new Binary_Search_Tree<type>(new_data);
                nodes_queue.push(range(cur->right, data, mx));
            }
        }
    }
    assert(is_bst_1());
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

// Check if the next element in the preorder is in the range
template <class type>
bool Binary_Search_Tree<type>::next_between(std::deque<type> &preorder, type min, type max)
{
    if (preorder.empty())
        return false;
    return ((min < preorder[0]) && (preorder[0] < max));
}

template <class type>
std::pair<Binary_Search_Tree<type> *, std::pair<type, type>> Binary_Search_Tree<type>::range(Binary_Search_Tree<type> *node, type mn, type mx)
{
    std::pair<type, type> range(make_pair(mn, mx));
    return make_pair(node, range);
}

template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::min_node()
{
    Binary_Search_Tree<type> *cur(this);
    while (cur && cur->left)
        cur = cur->left;
    return cur;
}

template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::max_node()
{
    Binary_Search_Tree<type> *cur(this);
    while (cur && cur->right)
        cur = cur->right;
    return cur;
}

template <class type>
void Binary_Search_Tree<type>::special_delete(Binary_Search_Tree<type> *child)
{
    data = child->data;
    left = child->left;
    right = child->right;
    delete child;
}
template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::delete_node_s(type target, Binary_Search_Tree<type> *node)
{
    if (!node)
        return nullptr;
    if (target < node->data)
        node->left = delete_node_s(target, node->left);
    else if (target > node->data)
        node->right = delete_node_s(target, node->right);
    else
    {
        if (!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }
        else if (!node->right)                // case 2: has left only
            node->special_delete(node->left); // connect with child
        else if (!node->left)                 // case 2: has right only
            node->special_delete(node->right);
        else // 2 children: Use successor
        {
            Binary_Search_Tree<type> *mn(node->right->min_node());
            node->data = mn->data; // copy & go delete
            node->right = delete_node_s(node->data, node->right);
        }
    }
    return node;
}

template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::delete_node_p(type target, Binary_Search_Tree<type> *node)
{
    if (!node)
        return nullptr;
    if (target < node->data)
        node->left = delete_node_p(target, node->left);
    else if (target > node->data)
        node->right = delete_node_p(target, node->right);
    else
    {
        if (!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }
        else if (!node->right)                // case 2: has left only
            node->special_delete(node->left); // connect with child
        else if (!node->left)                 // case 2: has right only
            node->special_delete(node->right);
        else // 2 children: Use predecessor
        {
            Binary_Search_Tree<type> *mx(node->left->max_node());
            node->data = mx->data; // copy & go delete
            node->left = delete_node_p(node->data, node->left);
        }
    }
    return node;
}

template <class type>
void Binary_Search_Tree<type>::get_in_order(std::vector<type> &inorder_values)
{
    if (left)
        left->get_in_order(inorder_values);
    inorder_values.emplace_back(data);
    if (right)
        right->get_in_order(inorder_values);
}

template <class type>
void Binary_Search_Tree<type>::get_pre_order(std::deque<type> &preorder_values)
{
    preorder_values.push_back(data);
    if (left)
        left->get_pre_order(preorder_values);
    if (right)
        right->get_pre_order(preorder_values);
}

template <class type>
void Binary_Search_Tree<type>::print_in_order()
{
    if (left)
        left->print_in_order();
    std::cout << data << ' ';
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
std::deque<type> Binary_Search_Tree<type>::level_order_traversal()
{
    std::queue<Binary_Search_Tree<type> *> nodes_queue;
    nodes_queue.push(this);
    std::deque<type> level_order;
    int level(0);
    while (!nodes_queue.empty())
    {
        int sze(nodes_queue.size());
        while (sze--)
        {
            Binary_Search_Tree<type> *cur(nodes_queue.front());
            nodes_queue.pop();
            level_order.push_back(cur->data);
            if (cur->left)
                nodes_queue.push(cur->left);
            if (cur->right)
                nodes_queue.push(cur->right);
        }
        ++level;
    }
    return level_order;
}

template <class type>
type Binary_Search_Tree<type>::min_value()
{
    return min_node()->data;
}

template <class type>
type Binary_Search_Tree<type>::max_value()
{
    return max_node()->data;
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
    std::vector<type> inorder_values;
    get_in_order(inorder_values);
    int len((int)inorder_values.size());
    for (int i(1); i < len; ++i)
    {
        if (inorder_values[i] < inorder_values[i - 1])
            return false;
    }
    return true;
}

template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::build_balanced_bst_tree(std::vector<type> &values, int str, int end)
{
    if (end == -1) // first call
        end = (int)values.size() - 1;
    if (str > end)
        return nullptr;
    int mid((str + end) >> 1); // mid(str + ((end - str) >> 1));
    Binary_Search_Tree<type> *left(build_balanced_bst_tree(values, str, mid - 1));
    Binary_Search_Tree<type> *right(build_balanced_bst_tree(values, mid + 1, end));
    Binary_Search_Tree<type> *root(new Binary_Search_Tree<type>(values[mid], left, right));
    return root;
}

template <class type>
type Binary_Search_Tree<type>::kth_smallest_0(int &k)
{
    std::vector<type> vals;
    get_in_order(vals);
    int len((int)vals.size());
    if (k >= len)
        return -1234;
    else
        return vals[k - 1];
}

template <class type>
type Binary_Search_Tree<type>::kth_smallest_1(int &k)
{
    if (!k)
        return -1234;
    if (left)
    {
        type res(left->kth_smallest_1(k));
        if (!k)
            return res;
    }
    --k;
    if (!k)
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
bool Binary_Search_Tree<type>::find_chain(std::vector<Binary_Search_Tree<type> *> &ancestors, type val)
{
    ancestors.push_back(this);
    if (val == data)
        return true;
    if (val < data)
        return left && left->find_chain(ancestors, val);
    return right && right->find_chain(ancestors, val);
}

template <class type>
Binary_Search_Tree<type> *Binary_Search_Tree<type>::get_next(std::vector<Binary_Search_Tree<type> *> &ancestors)
{
    if (!ancestors.size())
        return nullptr;
    Binary_Search_Tree<type> *node(ancestors.back());
    ancestors.pop_back();
    return node;
}

template <class type>
std::pair<bool, type> Binary_Search_Tree<type>::successor(type val)
{
    std::vector<Binary_Search_Tree<type> *> ancestors;

    if (!find_chain(ancestors, val))
        return std::make_pair(false, -1);

    Binary_Search_Tree<type> *child(get_next(ancestors));

    if (child->right)
        return std::make_pair(true, child->right->min_value());

    Binary_Search_Tree<type> *parent(get_next(ancestors));

    while (parent && parent->right == child)
        child = parent, parent = get_next(ancestors);

    if (parent)
        return std::make_pair(true, parent->data);
    return std::make_pair(false, -1);
}

template <class type>
void Binary_Search_Tree<type>::delete_value_successor(type val)
{
    if (val == data && !left && !right)
        return; // can't remove root in this structure
    delete_node_s(val, this);
}

template <class type>
void Binary_Search_Tree<type>::delete_value_predecessor(type val)
{
    if (val == data && !left && !right)
        return; // can't remove root in this structure
    delete_node_p(val, this);
}
#endif
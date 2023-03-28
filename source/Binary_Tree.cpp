#include "../header/Binary_Tree.h"

template <class type>
Binary_Tree<type>::Binary_Tree(type data) : data(data) {}

template <class type>
Binary_Tree<type>::~Binary_Tree()
{
    clear();
}

template <class type>
void Binary_Tree<type>::clear()
{
    // Don't try to call clear for children and also delete. This deletes twice!
    if (left)
        delete left, left = nullptr;
    if (right)
        delete right, left = right;
}

template <class type>
void Binary_Tree<type>::add(vector<type> values, vector<char> direction)
{
    assert(values.size() == direction.size());
    Binary_Tree *current(this);
    int len((int)values.size());
    for (int i(0); i < len; ++i)
    {
        if (direction[i] == 'L')
        {
            if (!current->left)
                current->left = new Binary_Tree<type>(values[i]);
            else
                assert(current->left->data == values[i]);
            current = current->left;
        }
        else
        {
            if (!current->right)
                current->right = new Binary_Tree<type>(values[i]);
            else
                assert(current->right->data == values[i]);
            current = current->right;
        }
    }
}

template <class type>
void Binary_Tree<type>::print_in_order()
{
    if (left)
        left->print_in_order();
    cout << data << ' ';
    if (right)
        right->print_in_order();
}

template <class type>
void Binary_Tree<type>::print_pre_order()
{
    cout << data << ' ';
    if (left)
        left->print_pre_order();
    if (right)
        right->print_pre_order();
}

template <class type>
void Binary_Tree<type>::print_post_order()
{
    if (left)
        left->print_post_order();
    if (right)
        right->print_post_order();
    cout << data << ' ';
}

template <class type>
type Binary_Tree<type>::tree_max()
{
    type mx(data);
    if (left)
        mx = max(mx, left->tree_max());
    if (right)
        mx = max(mx, right->tree_max());
    return mx;
}

template <class type>
int Binary_Tree<type>::tree_height_0()
{
    int height(0);
    if (left)
        height = 1 + left->tree_height_0();
    if (right)
        height = max(height, 1 + right->tree_height_0());
    return height;
}

template <class type>
int Binary_Tree<type>::tree_height_1()
{
    if (!left || !right)
        return 0;
    return 1 + max(left->tree_height_1(), right->tree_height_1());
}

template <class type>
int Binary_Tree<type>::total_nodes()
{
    int cnt(1);
    if (left)
        cnt += left->total_nodes();
    if (right)
        cnt += right->total_nodes();
    return cnt;
}

template <class type>
int Binary_Tree<type>::no_leaf_nodes()
{
    int cnt(!left && !right);
    if (left)
        cnt += left->no_leaf_nodes();
    if (right)
        cnt += right->no_leaf_nodes();
    return cnt;
}

template <class type>
bool Binary_Tree<type>::is_exists(type value)
{
    bool res(value == data);
    if (!res && left)
        res = left->is_exists(value);
    if (!res && right)
        res = right->is_exists(value);
    return res;
}

template <class type>
bool Binary_Tree<type>::is_perfect_fomula()
{
    int height(tree_height_0()), nodes(total_nodes());
    int res(pow(2, (height + 1)) - 1);
    return (res == nodes);
}

template <class type>
bool Binary_Tree<type>::is_perfect(int h)
{
    if (h == -1) // first call
        h = tree_height_0();

    if (!left && !right)
        return h == 0;

    if (!left && right || left && !right)
        return false;
    return left->is_perfect(h - 1) && right->is_perfect(h - 1);
}

template <class type>
void Binary_Tree<type>::print_inorder_iterative_0()
{
    stack<pair<Binary_Tree<type> *, bool>> nodes;
    nodes.push(make_pair(this, false));
    while (!nodes.empty())
    {
        Binary_Tree<type> *current(nodes.top().first);
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
void Binary_Tree<type>::print_inorder_iterative_1()
{
    stack<Binary_Tree<type> *> st;
    Binary_Tree<type> *cur(this);
    while (cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cout << cur->data << ' ';
        cur = cur->right;
    }
}

template <class type>
void Binary_Tree<type>::traverse_left_boundry()
{
    cout << data << ' ';
    if (left)
        left->traverse_left_boundry();
    else if (right)
        right->traverse_left_boundry();
}

template <class type>
pair<int, int> Binary_Tree<type>::tree_diameter()
{
    pair<int, int> res(make_pair(0, 0));
    if (!left && !right)
        return res;
    pair<int, int> left_diam(make_pair(0, 0));
    pair<int, int> right_diam(make_pair(0, 0));
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
void Binary_Tree<type>::level_order_traversal_0()
{
    queue<Binary_Tree<type> *> nodes_queue;
    nodes_queue.push(this);
    while (!nodes_queue.empty())
    {
        Binary_Tree<type> *cur(nodes_queue.front());
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
void Binary_Tree<type>::level_order_traversal_1()
{
    queue<Binary_Tree<type> *> nodes_queue;
    nodes_queue.push(this);
    int level(0), sz;
    while (!nodes_queue.empty())
    {
        sz = (int)nodes_queue.size();
        cout << "Level " << level << ": ";
        while (sz--)
        {
            Binary_Tree<type> *cur(nodes_queue.front());
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
void Binary_Tree<type>::print_level_nodes(int level)
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
void Binary_Tree<type>::level_order_traversal_sorted()
{
    priority_queue<pair<type, Binary_Tree<type> *>> heaps[2];
    int flag(0);
    heaps[flag].push(make_pair(data, this));
    while (!heaps[flag].empty())
    {
        int sz(heaps[flag].size());
        while (sz--)
        {
            pair<type, Binary_Tree<type> *> cur_pair(heaps[flag].top());
            heaps[flag].pop();
            Binary_Tree<type> *cur(cur_pair.second);
            cout << cur_pair.first << ' ';
            if (cur->left)
                heaps[!flag].push(make_pair(cur->left->data, cur->left));
            if (cur->right)
                heaps[!flag].push(make_pair(cur->right->data, cur->right));
        }
        cout << edl;
        flag = !flag;
    }
}

template <class type>
void Binary_Tree<type>::level_order_traversal_recursive() // O(N^2)
{
    int height(tree_height_0());
    for (int level(0); level <= height; ++level)
        print_level_nodes(level);
}

template <class type>
void Binary_Tree<type>::level_order_traversal_spiral()
{
    deque<Binary_Tree<type> *> nodes_deque;
    nodes_deque.push_back(this);
    int level(0), flag(1);
    while (!nodes_deque.empty())
    {
        int sz(nodes_deque.size());
        cout << "Level " << level << ": ";
        while (sz--)
        {
            Binary_Tree<type> *cur;
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
bool Binary_Tree<type>::is_complete()
{
    queue<Binary_Tree<type> *> nodes_queue;
    nodes_queue.push(this);
    bool no_more_allowed(false);
    while (!nodes_queue.empty())
    {
        int sz(nodes_queue.size());
        while (sz--)
        {
            Binary_Tree<type> *cur(nodes_queue.front());
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
Binary_Tree<type>::Binary_Tree(deque<type> &preorder, deque<type> &inorder, int inorder_start, int inorder_end)
{
    if (inorder_end == -1)
        inorder_end = (int)inorder.size() - 1;
    data = preorder[0];
    preorder.pop_front();
    for (int split(inorder_start); split <= inorder_end; ++split)
    {
        if (inorder[split] == data)
        {
            if (inorder_start < split)
                left = new Binary_Tree<type>(preorder, inorder, inorder_start, split - 1);
            if (split < inorder_end)
                right = new Binary_Tree<type>(preorder, inorder, split + 1, inorder_end);
            break;
        }
    }
}

template <class type>
Binary_Tree<type>::Binary_Tree(queue<pair<type, type>> &preorder_queue)
{
    pair<type, type> p(preorder_queue.front());
    preorder_queue.pop();
    data = p.first;
    if (!p.second)
    {
        if (preorder_queue.size())
            left = new Binary_Tree<type>(preorder_queue);
        if (preorder_queue.size())
            right = new Binary_Tree<type>(preorder_queue);
    }
}

template <class type>
void Binary_Tree<type>::build_preorder(queue<pair<type, type>> &preorder_queue)
{
    preorder_queue.push(make_pair(data, !left && !right));
    if (left)
        left->build_preorder(preorder_queue);
    if (right)
        right->build_preorder(preorder_queue);
}

template <class type>
void Binary_Tree<type>::print_preorder_complete()
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
string Binary_Tree<type>::to_str(type n)
{
    ostringstream oss;
    oss << n;
    return oss.str();
}

template <class type>
string Binary_Tree<type>::parenthesize_0(bool left_first)
{
    string repr("(" + to_str(data));

    if (left_first)
    {
        if (left)
            repr += left->parenthesize_0(left_first);
        else
            repr += "()"; // null: no child

        if (right)
            repr += right->parenthesize_0(left_first);
        else
            repr += "()"; // null: no child
    }
    else
    {
        if (right)
            repr += right->parenthesize_0(left_first);
        else
            repr += "()"; // null: no child

        if (left)
            repr += left->parenthesize_0(left_first);
        else
            repr += "()"; // null: no child
    }
    repr += ")";
    return repr;
}

template <class type>
string Binary_Tree<type>::parenthesize_canonical()
{
    string repr("(" + to_str(data));
    vector<string> v;
    if (left)
        v.push_back(left->parenthesize_canonical());
    else
        v.push_back("()");

    if (right)
        v.push_back(right->parenthesize_canonical());
    else
        v.push_back("()");

    sort(v.begin(), v.end());

    int len((int)v.size());

    for (int i(0); i < len; ++i)
        repr += v[i];

    repr += ")";
    return repr;
}

template <class type>
bool Binary_Tree<type>::is_mirror(Binary_Tree<type> *first, Binary_Tree<type> *second)
{
    if (!first && !second)
        return true;

    if (first && second && first->data == second->data)
        return is_mirror(first->left, second->right) &&
               is_mirror(first->right, second->left);

    return false;
}

template <class type>
bool Binary_Tree<type>::is_symmetric()
{
    if (!left && !right)
        return true;

    if (!left && right || left && !right)
        return false;

    return (left->parenthesize_0() == right->parenthesize_0(false));
    // return is_mirror(left, right);
}

template <class type>
bool Binary_Tree<type>::is_flip_equiv_0(Binary_Tree<type> *other)
{
    return parenthesize_canonical() == other->parenthesize_canonical();
}

template <class type>
bool Binary_Tree<type>::is_flip_equiv_1(Binary_Tree<type> *first, Binary_Tree<type> *second)
{
    if (!first && !second)
        return true;
    if (!first || !second)
        return false;
    if (first->data != second->data)
        return false;
    bool y, x(is_flip_equiv_1(first->left, second->left) && is_flip_equiv_1(first->right, second->right));
    if (!x)
        y(is_flip_equiv_1(first->left, second->right) && is_flip_equiv_1(first->right, second->left));
    return (x || y);
}

template <class type>
string Binary_Tree<type>::parenthesize_1(vector<string> &all_repres)
{
    string repr("(" + to_str(data));
    if (left)
        repr += left->parenthesize_1(all_repres);
    else
        repr += "()";

    if (right)
        repr += right->parenthesize_1(all_repres);
    else
        repr += "()";

    repr += ")";

    if (left || right) // nodes > 1
        all_repres.push_back(repr);
    return repr;
}

template <class type>
void Binary_Tree<type>::print_duplicate_subtrees()
{
    vector<string> all_repres;
    parenthesize_1(all_repres);

    sort(all_repres.begin(), all_repres.end());
    all_repres.push_back("#");

    int len((int)all_repres.size());
    for (int i(0); i < len;)
    {
        int j(i + 1);
        while (j < len && all_repres[i] == all_repres[j])
            ++j;
        if (j > i + 1)
            cout << all_repres[i] << edl;
        i = j;
    }
}
#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "../header/Binary_Tree.h"

template <class type>
Binary_Tree<type>::Binary_Tree(type data) : data(data) {}

template <class type>
Binary_Tree<type>::Binary_Tree(const Binary_Tree<type> &other) : data(other.data)
{
  if (other.left)
    left = new Binary_Tree<type>(*other.left);
  if (other.right)
    right = new Binary_Tree<type>(*other.right);
}

template <class type>
Binary_Tree<type> &
Binary_Tree<type>::operator=(const Binary_Tree<type> &other)
{
  if (this != &other)
  {
    clear();
    data = other.data;
    if (other.left)
      left = new Binary_Tree<type>(*other.left);
    if (other.right)
      right = new Binary_Tree<type>(*other.right);
  }
  return *this;
}

template <class type>
Binary_Tree<type>::~Binary_Tree() { clear(); }

template <class type>
void Binary_Tree<type>::clear()
{
  // Don't try to call clear for children and also delete. This deletes twice!
  if (left)
    delete left, left = nullptr;
  if (right)
    delete right, right = nullptr;
}

template <class type>
void Binary_Tree<type>::add(std::vector<type> values, std::vector<char> direction)
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
const void Binary_Tree<type>::get_in_order(std::vector<type> &inorder_values)
{
  if (left)
    left->get_in_order(inorder_values);
  inorder_values.emplace_back(data);
  if (right)
    right->get_in_order(inorder_values);
}

template <class type>
void Binary_Tree<type>::print_in_order()
{
  if (left)
    left->print_in_order();
  std::cout << data << ' ';
  if (right)
    right->print_in_order();
}

template <class type>
void Binary_Tree<type>::print_pre_order()
{
  std::cout << data << ' ';
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
  std::cout << data << ' ';
}

template <class type>
type Binary_Tree<type>::max_value()
{
  type mx(data);
  if (left)
    mx = std::max(mx, left->max_value());
  if (right)
    mx = std::max(mx, right->max_value());
  return mx;
}

template <class type>
int Binary_Tree<type>::tree_height_0()
{
  int height(0);
  if (left)
    height = 1 + left->tree_height_0();
  if (right)
    height = std::max(height, 1 + right->tree_height_0());
  return height;
}

template <class type>
int Binary_Tree<type>::tree_height_1()
{
  if (!left && !right)
    return 0;
  return 1 + std::max(left ? left->tree_height_1() : 0, right ? right->tree_height_1() : 0);
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
  int res((1 << (height + 1)) - 1);
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
  std::stack<std::pair<Binary_Tree<type> *, bool>> nodes;
  nodes.push(std::make_pair(this, false));
  while (!nodes.empty())
  {
    Binary_Tree<type> *current(nodes.top().first);
    bool is_done(nodes.top().second);
    nodes.pop();
    if (is_done)
      std::cout << current->data << ' ';
    else
    {
      if (current->right)
        nodes.push(std::make_pair(current->right, false));
      nodes.push(std::make_pair(current, true));
      if (current->left)
        nodes.push(std::make_pair(current->left, false));
    }
  }
  std::cout << edl;
}

template <class type>
void Binary_Tree<type>::print_inorder_iterative_1()
{
  std::stack<Binary_Tree<type> *> st;
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
    std::cout << cur->data << ' ';
    cur = cur->right;
  }
}

template <class type>
void Binary_Tree<type>::traverse_left_boundry()
{
  std::cout << data << ' ';
  if (left)
    left->traverse_left_boundry();
  else if (right)
    right->traverse_left_boundry();
}

template <class type>
std::pair<int, int> Binary_Tree<type>::tree_diameter()
{
  std::pair<int, int> res(std::make_pair(0, 0));
  if (!left && !right)
    return res;
  std::pair<int, int> left_diam(std::make_pair(0, 0));
  std::pair<int, int> right_diam(std::make_pair(0, 0));
  if (left)
    left_diam = left->tree_diameter(), res.first += 1 + left_diam.second;
  if (right)
    right_diam = right->tree_diameter(), res.first += 1 + right_diam.second;
  // diameter if in one of my children subtrees
  res.first = std::max(res.first, std::max(left_diam.first, right_diam.first));
  // normal height computation
  res.second = 1 + std::max(left_diam.second, right_diam.second);
  return res;
}

template <class type>
void Binary_Tree<type>::level_order_traversal_0()
{
  std::queue<Binary_Tree<type> *> nodes_queue;
  nodes_queue.push(this);
  while (!nodes_queue.empty())
  {
    Binary_Tree<type> *cur(nodes_queue.front());
    nodes_queue.pop();
    std::cout << cur->data << ' ';
    if (cur->left)
      nodes_queue.push(cur->left);
    if (cur->right)
      nodes_queue.push(cur->right);
  }
  std::cout << edl;
}

template <class type>
void Binary_Tree<type>::level_order_traversal_1()
{
  std::queue<Binary_Tree<type> *> nodes_queue;
  nodes_queue.push(this);
  int level(0), sze;
  while (!nodes_queue.empty())
  {
    sze = (int)nodes_queue.size();
    std::cout << "Level " << level << ": ";
    while (sze--)
    {
      Binary_Tree<type> *cur(nodes_queue.front());
      nodes_queue.pop();
      std::cout << cur->data << ' ';
      if (cur->left)
        nodes_queue.push(cur->left);
      if (cur->right)
        nodes_queue.push(cur->right);
    }
    ++level;
    std::cout << edl;
  }
}

template <class type>
void Binary_Tree<type>::print_level_nodes(int level)
{
  if (!level)
    std::cout << data << ' ';
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
  std::priority_queue<std::pair<type, Binary_Tree<type> *>> heaps[2];
  int flag(0);
  heaps[flag].push(std::make_pair(data, this));
  while (!heaps[flag].empty())
  {
    int sze(heaps[flag].size());
    while (sze--)
    {
      std::pair<type, Binary_Tree<type> *> cur_pair(heaps[flag].top());
      heaps[flag].pop();
      Binary_Tree<type> *cur(cur_pair.second);
      std::cout << cur_pair.first << ' ';
      if (cur->left)
        heaps[!flag].push(std::make_pair(cur->left->data, cur->left));
      if (cur->right)
        heaps[!flag].push(std::make_pair(cur->right->data, cur->right));
    }
    std::cout << edl;
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
  std::deque<Binary_Tree<type> *> nodes_deque;
  nodes_deque.push_back(this);
  int level(0), flag(1);
  while (!nodes_deque.empty())
  {
    int sze(nodes_deque.size());
    std::cout << "Level " << level << ": ";
    while (sze--)
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
      std::cout << cur->data << ' ';
    }
    flag = !flag, ++level;
    std::cout << edl;
  }
}

template <class type>
bool Binary_Tree<type>::is_complete()
{
  std::queue<Binary_Tree<type> *> nodes_queue;
  nodes_queue.push(this);
  bool no_more_allowed(false);
  while (!nodes_queue.empty())
  {
    int sze(nodes_queue.size());
    while (sze--)
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
Binary_Tree<type>::Binary_Tree(std::deque<type> &preorder,
                               std::deque<type> &inorder, int inorder_start,
                               int inorder_end)
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
        left =
            new Binary_Tree<type>(preorder, inorder, inorder_start, split - 1);
      if (split < inorder_end)
        right =
            new Binary_Tree<type>(preorder, inorder, split + 1, inorder_end);
      break;
    }
  }
}

template <class type>
Binary_Tree<type>::Binary_Tree(
    std::queue<std::pair<type, type>> &preorder_queue)
{
  std::pair<type, type> p(preorder_queue.front());
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
void Binary_Tree<type>::build_preorder(
    std::queue<std::pair<type, type>> &preorder_queue)
{
  preorder_queue.push(std::make_pair(data, !left && !right));
  if (left)
    left->build_preorder(preorder_queue);
  if (right)
    right->build_preorder(preorder_queue);
}

template <class type>
void Binary_Tree<type>::print_preorder_complete()
{
  std::cout << data << ' ';
  if (left)
    left->print_preorder_complete();
  else
    std::cout << "-1 ";

  if (right)
    right->print_preorder_complete();
  else
    std::cout << "-1 ";
}

template <class type>
std::string Binary_Tree<type>::to_str(type n)
{
  std::ostringstream oss;
  oss << n;
  return oss.str();
}

template <class type>
std::string Binary_Tree<type>::parenthesize_0(bool left_first)
{
  std::string repr("(" + to_str(data));

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
std::string Binary_Tree<type>::parenthesize_canonical()
{
  std::string repr("(" + to_str(data));
  std::vector<std::string> v;
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
  bool y, x(is_flip_equiv_1(first->left, second->left) &&
            is_flip_equiv_1(first->right, second->right));
  if (!x)
    y(is_flip_equiv_1(first->left, second->right) &&
      is_flip_equiv_1(first->right, second->left));
  return (x || y);
}

template <class type>
std::string
Binary_Tree<type>::parenthesize_1(std::vector<std::string> &all_repres)
{
  std::string repr("(" + to_str(data));
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
  std::vector<std::string> all_repres;
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
      std::cout << all_repres[i] << edl;
    i = j;
  }
}
#endif
#ifndef AVL_TREE_CPP
#define AVL_TREE_CPP

#include "../header/AVL_Tree.h"

template <class type>
AVL_Tree<type>::AVL_Tree() {}

template <class type>
AVL_Tree<type>::~AVL_Tree() { clear(this->root); }

template <class type>
AVL_Tree<type>::AVL_Tree(const AVL_Tree<type> &other)
{
  if (other.root)
    root = copy_node(other.root);
}

template <class type>
AVL_Tree<type> &AVL_Tree<type>::operator=(const AVL_Tree<type> &other)
{
  if (this != &other)
  {
    clear(root);
    root = nullptr;
    if (other.root)
      root = copy_node(other.root);
  }
  return *this;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::copy_node(AVL_Node<type> *node)
{
  if (!node)
    return nullptr;
  AVL_Node<type> *new_node(new AVL_Node<type>(node->data));
  new_node->height = node->height;
  new_node->left = copy_node(node->left);
  new_node->right = copy_node(node->right);
  return new_node;
}

template <class type>
void AVL_Tree<type>::clear(AVL_Node<type> *node)
{
  if (node)
  {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}

template <class type>
bool AVL_Tree<type>::search_node(type val, AVL_Node<type> *node)
{
  if (!node)
    return false;
  if (val == node->data)
    return true;
  if (val < node->data)
    return search_node(val, node->left);
  return search_node(val, node->right);
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::right_rotation(AVL_Node<type> *Q)
{
  // std::cout << "right_rotation " << Q->data << edl;
  AVL_Node<type> *P(Q->left);
  Q->left = P->right;
  P->right = Q;
  Q->update_height();
  P->update_height();
  return P;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::left_rotation(AVL_Node<type> *P)
{
  // std::cout << "left_rotation " << P->data << edl;
  AVL_Node<type> *Q(P->right);
  P->right = Q->left;
  Q->left = P;
  P->update_height();
  Q->update_height();
  return Q;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::balance(AVL_Node<type> *node)
{
  if (node->balance_factor() == 2) // Left
  {
    if (node->left->balance_factor() == -1)   // Left Right?
      node->left = left_rotation(node->left); // To Left Left
    node = right_rotation(node);              // Balance Left Left
  }
  else if (node->balance_factor() == -2)
  {
    if (node->right->balance_factor() == 1)
      node->right = right_rotation(node->right);

    node = left_rotation(node);
  }
  return node;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::insert_node(type val, AVL_Node<type> *node)
{
  if (val < node->data)
  {
    if (!node->left)
      node->left = new AVL_Node<type>(val);
    else
      node->left = insert_node(val, node->left);
  }
  else if (val > node->data)
  {
    if (!node->right)
      node->right = new AVL_Node<type>(val);
    else
      node->right = insert_node(val, node->right);
  }
  node->update_height();
  return balance(node);
}

template <class type>
bool AVL_Tree<type>::is_bst(AVL_Node<type> *node)
{
  bool left_bst(!node->left || (node->data > node->left->data && is_bst(node->left)));

  if (!left_bst)
    return false;

  bool right_bst(!node->right || (node->data < node->right->data && is_bst(node->right)));
  return right_bst;
}

template <class type>
void AVL_Tree<type>::verify()
{
  assert(abs(root->balance_factor()) < 2);
  assert(is_bst(root));
}

template <class type>
void AVL_Tree<type>::print_in_order_node(AVL_Node<type> *node)
{
  if (!node)
    return;
  print_in_order_node(node->left);
  std::cout << node->data << ' ';
  print_in_order_node(node->right);
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::min_node(AVL_Node<type> *cur)
{
  while (cur && cur->left)
    cur = cur->left;
  return cur;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::max_node(AVL_Node<type> *cur)
{
  while (cur && cur->right)
    cur = cur->right;
  return cur;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::delete_node(type val, AVL_Node<type> *node)
{
  if (!node)
    return nullptr;
  if (val < node->data)
    node->left = delete_node(val, node->left);
  else if (val > node->data)
    node->right = delete_node(val, node->right);
  else
  {
    AVL_Node<type> *tmp(node);
    if (!node->left && !node->right) // case 1: no child
      node = nullptr;
    else if (!node->right) // case 2: has left only
      node = node->left;   // connect with child
    else if (!node->left)  // case 2: has right only
      node = node->right;
    else // 2 children: Use successor
    {
      AVL_Node<type> *mn(min_node(node->right));
      node->data = mn->data; // copy & go delete
      node->right = delete_node(node->data, node->right);
      tmp = nullptr; // Don't delete me. Successor will be deleted
    }
    if (tmp)
      delete tmp;
  }
  if (node)
  {
    node->update_height();
    node = balance(node);
  }
  return node;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::lower_bound_node(type val, AVL_Node<type> *node)
{
  if (!node)
    return nullptr;
  if (node->data >= val)
  {
    AVL_Node<type> *ans(lower_bound_node(val, node->left));
    if (ans)
      return ans;
    return node;
  }
  return lower_bound_node(val, node->right);
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::upper_bound_node(type val, AVL_Node<type> *node)
{
  if (!node)
    return nullptr;
  if (node->data > val)
  {
    AVL_Node<type> *ans(upper_bound_node(val, node->left));
    if (ans)
      return ans;
    return node;
  }
  return upper_bound_node(val, node->right);
}

template <class type>
bool AVL_Tree<type>::prefix_exist_node(std::string prefix, AVL_Node<type> *node)
{
  std::string str(node->data.substr(0, std::min(node->data.size(), prefix.size())));
  if (prefix == str)
    return true;
  if (prefix < str)
    return node->left && prefix_exist_node(prefix, node->left);
  return node->right && prefix_exist_node(prefix, node->right);
}

template <class type>
void AVL_Tree<type>::insert_value(type val)
{
  if (!root)
    root = new AVL_Node<type>(val);
  else
    root = insert_node(val, root);
  verify();
}

template <class type>
bool AVL_Tree<type>::search(type val)
{
  return search_node(val, root);
}

template <class type>
void AVL_Tree<type>::print_in_order()
{
  print_in_order_node(root);
}

template <class type>
type AVL_Tree<type>::min_value()
{
  return min_node(root)->data;
}

template <class type>
type AVL_Tree<type>::max_value()
{
  return max_node(root)->data;
}

template <class type>
void AVL_Tree<type>::delete_value(type val)
{
  if (root)
  {
    root = delete_node(val, root);
    verify();
  }
}

template <class type>
void AVL_Tree<type>::level_order_traversal()
{
  if (!root)
    return;
  std::queue<AVL_Node<type> *> nodes_queue;
  nodes_queue.push(root);
  int level(0);
  while (!nodes_queue.empty())
  {
    int sze(nodes_queue.size());
    std::cout << "Level " << level << ": ";
    while (sze--)
    {
      AVL_Node<type> *cur(nodes_queue.front());
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
std::pair<bool, type> AVL_Tree<type>::lower_bound(type val)
{
  if (root)
  {
    AVL_Node<type> *ans(lower_bound_node(val, root));
    if (!ans)
      return std::make_pair(false, -123);
    return std::make_pair(true, ans->data);
  }
  return std::make_pair(false, -123);
}

template <class type>
std::pair<bool, type> AVL_Tree<type>::upper_bound(type val)
{
  if (root)
  {
    AVL_Node<type> *ans(upper_bound_node(val, root));
    if (!ans)
      return std::make_pair(false, -123);
    return std::make_pair(true, ans->data);
  }
  return std::make_pair(false, -123);
}

template <class type>
int AVL_Tree<type>::avl_nodes_recursive(int height)
{
  // no(h) = 1 + no(h - 1) + no(h - 2);
  if (!height)
    return 1;
  else if (height == 1)
    return 2;
  return 1 + avl_nodes_recursive(height - 1) + avl_nodes_recursive(height - 2);
}

template <class type>
int AVL_Tree<type>::avl_nodes_iterative(int height)
{
  if (!height)
    return 1;
  if (height == 1)
    return 2;
  --height;
  int a(1), b(2), c;
  while (height--)
    c = a + b + 1, a = b, b = c;
  return c;
}

template <class type>
bool AVL_Tree<type>::prefix_exist(std::string prefix)
{
  if (root)
    return prefix_exist_node(prefix, root);
  return false;
}
#endif
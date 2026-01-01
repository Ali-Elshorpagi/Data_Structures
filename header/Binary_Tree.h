#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <deque>
#include <sstream> // ostringstream
#include <math.h>

#define edl '\n'

template <class type>
class Binary_Tree
{
  type data{};
  Binary_Tree<type> *left{};
  Binary_Tree<type> *right{};
  std::string to_str(type n);
  void clear();

public:
  Binary_Tree(type data);
  Binary_Tree(const Binary_Tree<type> &other);
  Binary_Tree<type> &operator=(const Binary_Tree<type> &other);
  ~Binary_Tree();
  void add(std::vector<type> values, std::vector<char> direction);
  void print_in_order();
  void print_pre_order();
  void print_post_order();
  const void get_in_order(std::vector<type> &inorder_values);
  type max_value();
  int tree_height_0();
  int tree_height_1();
  int total_nodes();
  int no_leaf_nodes();
  bool is_exists(type value);
  bool is_perfect(int h = -1);
  bool is_perfect_fomula();
  void print_inorder_iterative_0();
  void print_inorder_iterative_1();
  void traverse_left_boundry();
  std::pair<int, int> tree_diameter();
  void level_order_traversal_0();
  void level_order_traversal_1();
  void level_order_traversal_sorted();
  void print_level_nodes(int level);
  void level_order_traversal_recursive();
  void level_order_traversal_spiral();
  bool is_complete();
  Binary_Tree(std::deque<type> &preorder, std::deque<type> &inorder, int inorder_start = 0, int inorder_end = -1);
  Binary_Tree(std::queue<std::pair<type, type>> &preorder_queue);
  void build_preorder(std::queue<std::pair<type, type>> &preorder_queue);
  void print_preorder_complete();
  std::string parenthesize_0(bool left_first = true);
  std::string parenthesize_canonical();
  bool is_mirror(Binary_Tree<type> *first, Binary_Tree<type> *second);
  bool is_symmetric();
  bool is_flip_equiv_0(Binary_Tree<type> *other);
  bool is_flip_equiv_1(Binary_Tree<type> *first, Binary_Tree<type> *second);
  std::string parenthesize_1(std::vector<std::string> &all_repres);
  void print_duplicate_subtrees();
};
#endif
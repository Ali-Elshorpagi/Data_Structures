#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <vector>
#include <cassert>
#include <deque>
#include <queue>
#include <utility>

#define edl '\n'

template <class type>
class Binary_Search_Tree
{
  type data{};
  Binary_Search_Tree<type> *left{};
  Binary_Search_Tree<type> *right{};
  void clear();
  bool find_chain(std::vector<Binary_Search_Tree<type> *> &ancestors, type val);
  Binary_Search_Tree<type> *get_next(std::vector<Binary_Search_Tree<type> *> &ancestors);
  bool next_between(std::deque<type> &preorder, type min, type max);
  std::pair<Binary_Search_Tree<type> *, std::pair<type, type>> range(Binary_Search_Tree<type> *node, type mn, type mx);
  void special_delete(Binary_Search_Tree<type> *child);
  Binary_Search_Tree<type> *delete_node_s(type target, Binary_Search_Tree<type> *node);
  Binary_Search_Tree<type> *delete_node_p(type target, Binary_Search_Tree<type> *node);
  Binary_Search_Tree<type> *min_node();
  Binary_Search_Tree<type> *max_node();

public:
  // Binary_Search_Tree(type data);
  Binary_Search_Tree(const Binary_Search_Tree<type> &other);
  Binary_Search_Tree<type> &operator=(const Binary_Search_Tree<type> &other);
  Binary_Search_Tree(std::deque<type> &preorder, type min = INT_MIN,
                     type max = INT_MAX);
  Binary_Search_Tree(std::deque<type> level_order);
  Binary_Search_Tree(type d, Binary_Search_Tree<type> *l = nullptr,
                     Binary_Search_Tree<type> *r = nullptr);
  ~Binary_Search_Tree();
  void get_in_order(std::vector<type> &inorder_values);
  void get_pre_order(std::deque<type> &preorder_queue);
  void print_in_order();
  void insert(type val);
  bool search(type val);
  std::deque<type> level_order_traversal();
  type min_value();
  type max_value();
  bool search_iterative(type val);
  bool is_bst_0(type mn = INT_MIN, type mx = INT_MAX);
  bool is_bst_1();
  Binary_Search_Tree<type> *build_balanced_bst_tree(std::vector<type> &values, int str = 0, int end = -1);
  type kth_smallest_0(int &k);
  type kth_smallest_1(int &k);
  type LCA(type x, type y);
  std::pair<bool, type> successor(type val);
  void delete_value_successor(type val);
  void delete_value_predecessor(type val);
};
#endif
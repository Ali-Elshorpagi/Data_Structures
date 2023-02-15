#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <deque>
#include <queue>
#include <utility>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Binary_Search_Tree
{
    type data{};
    Binary_Search_Tree<type> *left{};
    Binary_Search_Tree<type> *right{};
    void clear();
    bool find_chain(vector<Binary_Search_Tree<type> *> &ancestors, type val);
    Binary_Search_Tree<type> *get_next(vector<Binary_Search_Tree<type> *> &ancestors);
    bool next_between(deque<type> &preorder, type min, type max);
    pair<Binary_Search_Tree<type> *, pair<type, type>> range(Binary_Search_Tree<type> *node, type mn, type mx);
    void special_delete(Binary_Search_Tree<type> *child);
    Binary_Search_Tree<type> *delete_node_s(type target, Binary_Search_Tree<type> *node);
    Binary_Search_Tree<type> *delete_node_p(type target, Binary_Search_Tree<type> *node);
    Binary_Search_Tree<type> *min_node();
    Binary_Search_Tree<type> *max_node();

public:
    Binary_Search_Tree(type data);
    Binary_Search_Tree(deque<type> &preorder, type min = INT_MIN, type max = INT_MAX);
    Binary_Search_Tree(deque<type> level_order);
    ~Binary_Search_Tree();
    void get_in_order(vector<type> &inorder_values);
    void get_pre_order(deque<type> &preorder_queue);
    void print_in_order();
    void insert(type val);
    bool search(type val);
    deque<type> level_order_traversal();
    type min_value();
    type max_value();
    bool search_iterative(type val);
    bool is_bst_0(type mn = INT_MIN, type mx = INT_MAX);
    bool is_bst_1();
    Binary_Search_Tree<type> *build_balanced_bst_tree(vector<type> &values, ll str = 0, ll end = -1);
    type kth_smallest_0(ll &k);
    type kth_smallest_1(ll &k);
    type LCA(type x, type y);
    pair<bool, type> successor(type val);
    void delete_value_successor(type val);
    void delete_value_predecessor(type val);
};
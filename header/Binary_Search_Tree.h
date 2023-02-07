#pragma once

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Binary_Search_Tree
{
    type data{};
    Binary_Search_Tree<type> *left{};
    Binary_Search_Tree<type> *right{};
    void get_in_order(vector<type> &inorder_values);
    void clear();

public:
    Binary_Search_Tree(type data);
    ~Binary_Search_Tree();
    void print_in_order();
    void insert(type val);
    bool search(type val);
    type min_value();
    type max_value();
    bool search_iterative(type val);
    bool is_bst_0(type mn = INT_MIN, type mx = INT_MAX);
    bool is_bst_1();
    Binary_Search_Tree<type> *build_balanced_bst_tree(vector<type> &values, ll str = 0, ll end = -1);
    type kth_smallest_0(ll &k);
    type kth_smallest_1(ll &k);
    type LCA(type x, type y);
};
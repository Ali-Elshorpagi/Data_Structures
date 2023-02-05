#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <deque>
#include <sstream> // ostringstream

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Binary_Tree
{
    type data{};
    Binary_Tree *left{};
    Binary_Tree *right{};

public:
    Binary_Tree(type data);
    ~Binary_Tree();
    void clear();
    void add(vector<type> values, vector<char> direction);
    void print_in_order();
    void print_pre_order();
    void print_post_order();
    type tree_max();
    ll tree_height();
    ll total_nodes();
    ll no_leaf_nodes();
    bool is_exists(type value);
    bool is_perfect(ll h = -1);
    bool is_perfect_fomula();
    void print_inorder_iterative();
    void traverse_left_boundry();
    pair<ll, ll> tree_diameter();
    void level_order_traversal_0();
    void level_order_traversal_1();
    void print_level_nodes(ll level);
    void level_order_traversal_recursive();
    void level_order_traversal_spiral();
    bool is_complete();
    Binary_Tree(deque<ll> &preorder, deque<ll> &inorder, ll inorder_start = 0, ll inorder_end = -1);
    Binary_Tree(queue<pair<ll, ll>> &preorder_queue);
    void build_preorder(queue<pair<ll, ll>> &preorder_queue);

    void print_preorder_complete();
    string to_str(ll n);
    string parenthesize_0(bool left_first = true);
    string parenthesize_canonical();
    bool is_mirror(Binary_Tree<type> *first, Binary_Tree<type> *second);
    bool is_symmetric();
    bool is_flip_equiv_0(Binary_Tree<type> *other);
    bool is_flip_equiv_1(Binary_Tree<type> *first, Binary_Tree<type> *second);

    string parenthesize_1(vector<string> &all_repres);
    void print_duplicate_subtrees();
};

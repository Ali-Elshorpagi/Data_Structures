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
class BinaryTree
{
    type data{};
    BinaryTree *left{};
    BinaryTree *right{};

public:
    BinaryTree(type data);
    ~BinaryTree();
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











};

#pragma once

#include <iostream>
#include <cassert>
#include <queue>

using namespace std;
#define edl '\n'

template <class type>
class AVL_Tree_v2
{
    type data{};
    int height{};
    AVL_Tree_v2<type> *left{};
    AVL_Tree_v2<type> *right{};

    int ch_height(AVL_Tree_v2<type> *node);
    int update_height();
    int balance_factor();
    AVL_Tree_v2<type> *right_rotation(AVL_Tree_v2<type> *Q);
    AVL_Tree_v2<type> *left_rotation(AVL_Tree_v2<type> *P);
    AVL_Tree_v2<type> *balance(AVL_Tree_v2<type> *node);
    AVL_Tree_v2<type> *min_node();
    AVL_Tree_v2<type> *max_node();
    void special_delete(AVL_Tree_v2<type> *child);
    AVL_Tree_v2<type> *delete_node(type val, AVL_Tree_v2<type> *node);
    void re_root(AVL_Tree_v2<type> *node);
    void clear();
    void verify();

public:
    AVL_Tree_v2(type data);
    ~AVL_Tree_v2();
    void insert(type val);
    void delete_value(type val);
    void level_order_traversal();
    bool is_bst();
};
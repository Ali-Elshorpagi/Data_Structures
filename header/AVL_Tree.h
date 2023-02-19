#pragma once

#include <iostream>
#include <cassert>
#include <queue>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class T>
struct AVL_Node
{
    T data{};
    ll height{};
    AVL_Node<T> *left{};
    AVL_Node<T> *right{};
    AVL_Node(T data) : data(data) {}
    ll ch_height(AVL_Node<T> *node)
    {
        if (!node)
            return -1;
        return node->height;
    }
    ll update_height()
    {
        return height = 1 + max(ch_height(left), ch_height(right));
    }
    ll balance_factor()
    {
        return ch_height(left) - ch_height(right);
    }
};

template <class type>
class AVL_Tree
{
    AVL_Node<type> *root{};
    bool search_node(type val, AVL_Node<type> *node);
    AVL_Node<type> *right_rotation(AVL_Node<type> *Q);
    AVL_Node<type> *left_rotation(AVL_Node<type> *P);
    AVL_Node<type> *balance(AVL_Node<type> *node);
    AVL_Node<type> *insert_node(type val, AVL_Node<type> *node);
    bool is_bst(AVL_Node<type> *node);
    void verify();
    void print_in_order_node(AVL_Node<type> *node);
    AVL_Node<type> *min_node(AVL_Node<type> *cur);
    AVL_Node<type> *max_node(AVL_Node<type> *cur);

    void clear(AVL_Node<type> *node);

public:
    AVL_Tree();
    ~AVL_Tree();
    void insert_value(type val);
    bool search(type val);
    void print_in_order();
    type min_value();
    type max_value();
};
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

template <class T>
struct BST_Node
{
    T data{};
    BST_Node<T> *left{};
    BST_Node<T> *right{};
    BST_Node(T data) : data(data) {}
};

template <class type>
class Binary_Search_Tree_v2
{
    BST_Node<type> *root{};
    void insert_node(type val, BST_Node<type> *node);
    bool search_node(type val, BST_Node<type> *node);
    void print_in_order_node(BST_Node<type> *node);
    void clear(BST_Node<type> *node);
    BST_Node<type> *min_node(BST_Node<type> *node);
    BST_Node<type> *max_node(BST_Node<type> *node);
    BST_Node<type> *delete_node(type target, BST_Node<type> *node);
    bool is_bst(BST_Node<type> *node);

public:
    Binary_Search_Tree_v2();
    ~Binary_Search_Tree_v2();
    void insert_value(type val);
    bool search(type val);
    void print_in_order();
    type min_value();
    type max_value();
    void delete_value(type val);
    void level_order_traversal();
};
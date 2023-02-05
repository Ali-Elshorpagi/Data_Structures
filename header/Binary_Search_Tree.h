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
private:
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
    bool is_bst_0();
    bool is_bst_1();
};
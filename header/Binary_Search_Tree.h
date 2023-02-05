#pragma once

#include <iostream>
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

public:
    Binary_Search_Tree(type data);
    ~Binary_Search_Tree();
    void clear();
    void print_in_order();
    void insert(type val);
    bool search(type val);
    bool search_iterative(type val);
    type min_value();
    type max_value();
};
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
    Binary_Search_Tree *left{};
    Binary_Search_Tree *right{};

public:
    Binary_Search_Tree(type data);
    ~Binary_Search_Tree();
    void clear();
    void print_inorder();
    void insert(type target);
    bool search(type target);
};
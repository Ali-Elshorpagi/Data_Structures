#pragma once

#include <iostream>
#include <cstring> // memset

using namespace std;
#define edl '\n'

class Letter_Tree
{
    static const int MAX_CHAR = 26;
    Letter_Tree *child[MAX_CHAR];
    bool is_leaf{};

public:
    Letter_Tree();
    ~Letter_Tree();
    void insert_recursive(string str, int idx = 0);
    void insert_iterative(string str);
    bool word_exist_recursive(string str, int idx = 0);
    bool word_exist_iterative(string str);
    bool prefix_exist(string str, int idx = 0);
};
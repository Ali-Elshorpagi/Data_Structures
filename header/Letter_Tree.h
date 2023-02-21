#pragma once

#include <iostream>
#include <cstring> // memset
#include <map>

using namespace std;
#define edl '\n'

class Letter_Tree
{
    map<char, Letter_Tree *> child;
    bool is_leaf{};

public:
    Letter_Tree();
    ~Letter_Tree();
    void insert_recursive(string str, int idx = 0);
    void insert_iterative(string str);
    bool word_exist_recursive(string str, int idx = 0);
    bool word_exist_iterative(string str);
    bool prefix_exist(string str, int idx = 0);
    string first_word_prefix(const string &str);
};
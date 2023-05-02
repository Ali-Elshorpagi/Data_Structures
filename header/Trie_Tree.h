#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define sz(v) ((int)((v).size()))
#define edl '\n'

// if you need to build a Suffix Trie
// it's same idea but just need to reverse the input

class Trie_Tree
{
    map<int, Trie_Tree *> child;
    bool is_leaf{};

public:
    Trie_Tree();
    ~Trie_Tree();
    void insert_recursive(string str, int idx = 0);
    void insert_iterative(string str);
    bool word_exist_recursive(string str, int idx = 0);
    bool word_exist_iterative(string str);
    bool prefix_exist(string str, int idx = 0);
    string first_word_prefix(const string &str);
    void get_all_strings(vector<string> &res, string cur_str = "");
    void auto_complete_0(const string &str, vector<string> &res);
    void auto_complete_1(const string &str, vector<string> &res);
    bool word_exist_with_1_change(string str);
};
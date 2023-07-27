#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include <iostream>
#include <vector>
#include <map>

#define sz(v) ((int)((v).size()))
#define edl '\n'

// if you need to build a Suffix Trie
// it's same idea but just need to reverse the input

class Trie_Tree
{
    std::map<int, Trie_Tree *> child;
    bool is_leaf{};

public:
    Trie_Tree();
    ~Trie_Tree();
    void insert_recursive(std::string str, int idx = 0);
    void insert_iterative(std::string str);
    bool word_exist_recursive(std::string str, int idx = 0);
    bool word_exist_iterative(std::string str);
    bool prefix_exist(std::string str, int idx = 0);
    std::string first_word_prefix(const std::string &str);
    void get_all_strings(std::vector<std::string> &res, std::string cur_str = "");
    void auto_complete_0(const std::string &str, std::vector<std::string> &res);
    void auto_complete_1(const std::string &str, std::vector<std::string> &res);
    bool word_exist_with_1_change(std::string str);
};
#endif
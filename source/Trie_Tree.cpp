#include "../header/Trie_Tree.h"

Trie_Tree::Trie_Tree() {}

Trie_Tree::~Trie_Tree()
{
    for (auto &it : child)
    {
        delete it.second;
        it.second = nullptr;
    }
}

void Trie_Tree::insert_recursive(string str, int idx)
{
    if (idx == (int)str.size())
        is_leaf = 1;
    else
    {
        int cur(str[idx] - 'a');
        if (!child[cur])
            child[cur] = new Trie_Tree();
        child[cur]->insert_recursive(str, idx + 1);
    }
}

void Trie_Tree::insert_iterative(string str)
{
    Trie_Tree *cur(this);
    for (auto &it : str)
    {
        int idx(it - 'a');
        if (!cur->child[idx])
            cur->child[idx] = new Trie_Tree();
        cur = cur->child[idx];
    }
    cur->is_leaf = true;
}

bool Trie_Tree::word_exist_recursive(string str, int idx)
{
    if (idx == (int)str.size())
        return is_leaf;

    int cur(str[idx] - 'a');
    if (!child[cur])
        return false;

    return child[cur]->word_exist_recursive(str, idx + 1);
}

bool Trie_Tree::word_exist_iterative(string str)
{
    Trie_Tree *cur(this);
    for (auto &it : str)
    {
        int idx(it - 'a');
        if (!cur->child[idx])
            return false;
        cur = cur->child[idx];
    }
    return cur->is_leaf;
}

bool Trie_Tree::prefix_exist(string str, int idx)
{
    if (idx == (int)str.size())
        return true;

    int cur(str[idx] - 'a');
    if (!child[cur])
        return false;

    return child[cur]->prefix_exist(str, idx + 1);
}

string Trie_Tree::first_word_prefix(const string &str)
{
    Trie_Tree *cur(this);
    int len((int)str.size());
    for (int i(0); i < len; ++i)
    {
        int ch(str[i] - 'a');
        if (!cur->child[ch])
            break;

        if (cur->child[ch]->is_leaf)
            return str.substr(0, i + 1);
        cur = cur->child[ch];
    }
    return str;
}

void Trie_Tree::get_all_strings(vector<string> &res, string cur_str)
{
    if (is_leaf)
        res.emplace_back(cur_str);
    for (auto &it : child)
        if (it.second)
            it.second->get_all_strings(res, cur_str + (char)(it.first + 'a'));
}

void Trie_Tree::auto_complete_0(const string &str, vector<string> &res)
{
    vector<string> tmp;
    get_all_strings(tmp);
    int len((int)str.size());
    for (auto &it : tmp)
    {
        string s(it.substr(0, len));
        if (s == str)
            res.emplace_back(it);
    }
}

void Trie_Tree::auto_complete_1(const string &str, vector<string> &res)
{
    Trie_Tree *cur(this);
    int len((int)str.size());
    for (auto &it : str)
    {
        int idx(it - 'a');
        if (!cur->child[idx])
            return;
        cur = cur->child[idx];
    }
    cur->get_all_strings(res, str);
}

bool Trie_Tree::word_exist_with_1_change(string str)
{
    for (auto &it : str)
    {
        char cpy(it);
        for (char ch('a'); ch <= 'z'; ++ch)
        {
            if (ch == cpy) // must do a change
                continue;
            it = ch;
            if (word_exist_iterative(str))
                return true;
        }
        it = cpy;
    }
    return false;
}
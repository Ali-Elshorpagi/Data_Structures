#include "..\\header\Letter_Tree.h"

Letter_Tree::Letter_Tree() {}

Letter_Tree::~Letter_Tree()
{
    for (auto &it : child)
    {
        delete it.second;
        it.second = nullptr;
    }
}

void Letter_Tree::insert_recursive(string str, int idx)
{
    if (idx == (int)str.size())
        is_leaf = 1;
    else
    {
        int cur(str[idx] - 'a');
        if (!child[cur])
            child[cur] = new Letter_Tree();
        child[cur]->insert_recursive(str, idx + 1);
    }
}

void Letter_Tree::insert_iterative(string str)
{
    Letter_Tree *cur(this);
    for (auto &it : str)
    {
        int idx(it - 'a');
        if (!cur->child[idx])
            cur->child[idx] = new Letter_Tree();
        cur = cur->child[idx];
    }
    cur->is_leaf = true;
}

bool Letter_Tree::word_exist_recursive(string str, int idx)
{
    if (idx == (int)str.size())
        return is_leaf;

    int cur(str[idx] - 'a');
    if (!child[cur])
        return false;

    return child[cur]->word_exist_recursive(str, idx + 1);
}

bool Letter_Tree::word_exist_iterative(string str)
{
    Letter_Tree *cur(this);
    for (auto &it : str)
    {
        int idx(it - 'a');
        if (!cur->child[idx])
            return false;
        cur = cur->child[idx];
    }
    return cur->is_leaf;
}

bool Letter_Tree::prefix_exist(string str, int idx)
{
    if (idx == (int)str.size())
        return true;

    int cur(str[idx] - 'a');
    if (!child[cur])
        return false;

    return child[cur]->prefix_exist(str, idx + 1);
}

string Letter_Tree::first_word_prefix(const string &str)
{
    Letter_Tree *cur(this);
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

void Letter_Tree::get_all_strings(vector<string> &res, string cur_str)
{
    if (is_leaf)
        res.emplace_back(cur_str);
    for (auto &it : child)
        if (it.second)
            it.second->get_all_strings(res, cur_str + (char)(it.first + 'a'));
}

void Letter_Tree::auto_complete_0(const string &str, vector<string> &res)
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

void Letter_Tree::auto_complete_1(const string &str, vector<string> &res)
{
    Letter_Tree *cur(this);
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

bool Letter_Tree::word_exist_with_1_change(string str)
{
    for (auto &it : str)
    {
        char cpy(it);
        for (char ch('a'); ch <= 'z'; ++ch)
        {
            if (ch == cpy) // Must do a change
                continue;
            it = ch;
            if (word_exist_iterative(str))
                return true;
        }
        it = cpy;
    }
    return false;
}
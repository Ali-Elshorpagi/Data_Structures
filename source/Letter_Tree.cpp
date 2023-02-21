#include "..\\header\Letter_Tree.h"

Letter_Tree::Letter_Tree()
{
    // set an array to 0s. Here pointers to null
    memset(child, 0, sizeof(child));
}

Letter_Tree::~Letter_Tree()
{
    for (int i(0); i < MAX_CHAR; ++i)
    {
        delete child[i];
        child[i] = nullptr;
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
    int len((int)str.size());
    for (int i(0); i < len; ++i)
    {
        int idx(str[i] - 'a');
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
    int len((int)str.size());
    for (int i(0); i < len; ++i)
    {
        int idx(str[i] - 'a');
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

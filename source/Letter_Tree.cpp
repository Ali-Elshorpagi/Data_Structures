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

void Letter_Tree::insert(string str, int idx)
{
    if (idx == (int)str.size())
        is_leaf = 1;
    else
    {
        int cur(str[idx] - 'a');
        if (child[cur] == 0)
            child[cur] = new Letter_Tree();
        child[cur]->insert(str, idx + 1);
    }
}

bool Letter_Tree::word_exist(string str, int idx)
{
    if (idx == (int)str.size())
        return is_leaf;

    int cur(str[idx] - 'a');
    if (!child[cur])
        return false;

    return child[cur]->word_exist(str, idx + 1);
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
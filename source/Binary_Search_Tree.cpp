#include "..\\header\Binary_Search_Tree.h"

template <class type>
Binary_Search_Tree<type>::Binary_Search_Tree(type data) : data(data) {}

template <class type>
Binary_Search_Tree<type>::~Binary_Search_Tree()
{
    clear();
}

template <class type>
void Binary_Search_Tree<type>::clear()
{
    // Don't try to call clear for children and also delete. This deletes twice!
    if (left)
        delete left, left = nullptr;
    if (right)
        delete right, left = right;
}

template <class type>
void Binary_Search_Tree<type>::print_in_order()
{
    if (left)
        left->print_in_order();
    cout << data << ' ';
    if (right)
        right->print_in_order();
}

template <class type>
void Binary_Search_Tree<type>::insert(type val)
{
    if (val < data)
    {
        if (!left)
            left = new Binary_Search_Tree(val);
        else
            left->insert(val);
    }
    else if (val > data)
    {
        if (!right)
            right = new Binary_Search_Tree(val);
        else
            right->insert(val);
    }
}

template <class type>
bool Binary_Search_Tree<type>::search(type val)
{
    if (val == data)
        return true;
    if (val < data)
        return left && left->search(val);
    return right && right->search(val);
}

template <class type>
bool Binary_Search_Tree<type>::search_iterative(type val)
{
    Binary_Search_Tree<type> *root(this);
    while (root)
    {
        if (val == root->data)
            return true;
        if (root->data < val)
            root = root->right;
        else if (root->data > val)
            root = root->left;
    }
    return false;
}
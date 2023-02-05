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
void Binary_Search_Tree<type>::print_inorder()
{
    if (left)
        left->print_inorder();
    cout << data << ' ';
    if (right)
        right->print_inorder();
}

template <class type>
void Binary_Search_Tree<type>::insert(type target)
{
    if (target < data)
    {
        if (!left)
            left = new Binary_Search_Tree(target);
        else
            left->insert(target);
    }
    else if (target > data)
    {
        if (!right)
            right = new Binary_Search_Tree(target);
        else
            right->insert(target);
    }
}

template <class type>
bool Binary_Search_Tree<type>::search(type target)
{
    if (target == data)
        return true;
    if (target < data)
        return left && left->search(target);
    return right && right->search(target);
}
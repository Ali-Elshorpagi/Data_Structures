#include "../header/Binary_Search_Tree_v2.h"

template <class type>
Binary_Search_Tree_v2<type>::Binary_Search_Tree_v2() {}

template <class type>
Binary_Search_Tree_v2<type>::~Binary_Search_Tree_v2()
{
    clear(root);
}

template <class type>
void Binary_Search_Tree_v2<type>::clear(BST_Node<type> *node)
{
    if (node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <class type>
BST_Node<type> *Binary_Search_Tree_v2<type>::delete_node(type target, BST_Node<type> *node)
{
    if (!node)
        return nullptr;
    if (target < node->data)
        node->left = delete_node(target, node->left);
    else if (target > node->data)
        node->right = delete_node(target, node->right);
    else
    {
        BST_Node<type> *tmp(node);
        if (!node->left && !node->right) // case 1: no child
            node = nullptr;
        else if (!node->right) // case 2: has left only
            node = node->left; // connect with child
        else if (!node->left)  // case 2: has right only
            node = node->right;
        else // 2 children: Use successor
        {
            BST_Node<type> *mn(min_node(node->right));
            node->data = mn->data; // copy & go delete
            node->right = delete_node(node->data, node->right);
            tmp = nullptr; // Don't delete me. Successor will be deleted
        }
        if (tmp)
            delete tmp;
    }
    return node;
}

template <class type>
BST_Node<type> *Binary_Search_Tree_v2<type>::min_node(BST_Node<type> *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

template <class type>
BST_Node<type> *Binary_Search_Tree_v2<type>::max_node(BST_Node<type> *node)
{
    while (node && node->right)
        node = node->right;
    return node;
}

template <class type>
void Binary_Search_Tree_v2<type>::insert_node(type val, BST_Node<type> *node)
{
    if (val < node->data)
    {
        if (!node->left)
            node->left = new BST_Node<type>(val);
        else
            insert_node(val, node->left);
    }
    else if (val > node->data)
    {
        if (!node->right)
            node->right = new BST_Node<type>(val);
        else
            insert_node(val, node->right);
    }
}

template <class type>
bool Binary_Search_Tree_v2<type>::search_node(type val, BST_Node<type> *node)
{
    if (!node)
        return false;
    if (val == node->data)
        return true;
    if (val < node->data)
        return search_node(val, node->left);
    return search_node(val, node->right);
}

template <class type>
void Binary_Search_Tree_v2<type>::print_in_order_node(BST_Node<type> *node)
{
    if (!node)
        return;
    print_in_order_node(node->left);
    cout << node->data << ' ';
    print_in_order_node(node->right);
}

template <class type>
bool Binary_Search_Tree_v2<type>::is_bst(BST_Node<type> *node)
{
    bool left_bst(!node->left || (node->data > node->left->data) && is_bst(node->left));
    if (!left_bst)
        return false;
    bool right_bst(!node->right || (node->data < node->right->data) && is_bst(node->right));
    return right_bst;
}

template <class type>
void Binary_Search_Tree_v2<type>::insert_value(type val)
{
    if (!root)
        root = new BST_Node<type>(val);
    else
        insert_node(val, root);
    is_bst(root);
}

template <class type>
bool Binary_Search_Tree_v2<type>::search(type val)
{
    return search_node(val, root);
}

template <class type>
void Binary_Search_Tree_v2<type>::print_in_order()
{
    print_in_order_node(root);
}

template <class type>
type Binary_Search_Tree_v2<type>::min_value()
{
    return min_node(root)->data;
}

template <class type>
type Binary_Search_Tree_v2<type>::max_value()
{
    return max_node(root)->data;
}

template <class type>
void Binary_Search_Tree_v2<type>::delete_value(type val)
{
    if (root)
        root = delete_node(val, root), is_bst(root);
}

template <class type>
void Binary_Search_Tree_v2<type>::level_order_traversal()
{
    if (!root)
        return;
    cout << "********************" << edl;
    queue<BST_Node<type> *> nodes_queue;
    nodes_queue.push(root);
    int level(0);
    while (!nodes_queue.empty())
    {
        int sz(nodes_queue.size());
        cout << "Level " << level << ": ";
        while (sz--)
        {
            BST_Node<type> *cur(nodes_queue.front());
            nodes_queue.pop();
            cout << cur->data << ' ';
            if (cur->left)
                nodes_queue.push(cur->left);
            if (cur->right)
                nodes_queue.push(cur->right);
        }
        ++level;
        cout << edl;
    }
}
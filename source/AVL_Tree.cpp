#include "..\\header\AVL_Tree.h"

template <class type>
AVL_Tree<type>::AVL_Tree() {}

template <class type>
AVL_Tree<type>::~AVL_Tree()
{
    clear(root);
}

template <class type>
void AVL_Tree<type>::clear(AVL_Node<type> *node)
{
    if (node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <class type>
bool AVL_Tree<type>::search_node(type val, AVL_Node<type> *node)
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
AVL_Node<type> *AVL_Tree<type>::right_rotation(AVL_Node<type> *Q)
{
    // cout << "right_rotation " << Q->data << edl;
    AVL_Node<type> *P(Q->left);
    Q->left = P->right;
    P->right = Q;
    Q->update_height();
    P->update_height();
    return P;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::left_rotation(AVL_Node<type> *P)
{
    // cout << "left_rotation " << P->data << edl;
    AVL_Node<type> *Q(P->right);
    P->right = Q->left;
    Q->left = P;
    P->update_height();
    Q->update_height();
    return Q;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::balance(AVL_Node<type> *node)
{
    if (node->balance_factor() == 2) // Left
    {
        if (node->left->balance_factor() == -1)     // Left Right?
            node->left = left_rotation(node->left); // To Left Left
        node = right_rotation(node);                // Balance Left Left
    }
    else if (node->balance_factor() == -2)
    {
        if (node->right->balance_factor() == 1)
            node->right = right_rotation(node->right);

        node = left_rotation(node);
    }
    return node;
}

template <class type>
AVL_Node<type> *AVL_Tree<type>::insert_node(type val, AVL_Node<type> *node)
{
    if (val < node->data)
    {
        if (!node->left)
            node->left = new AVL_Node<type>(val);
        else
            node->left = insert_node(val, node->left);
    }
    else if (val > node->data)
    {
        if (!node->right)
            node->right = new AVL_Node<type>(val);
        else
            node->right = insert_node(val, node->right);
    }
    node->update_height();
    return balance(node);
}

template <class type>
bool AVL_Tree<type>::is_bst(AVL_Node<type> *node)
{
    bool left_bst(!node->left || node->data > node->left->data && is_bst(node->left));

    if (!left_bst)
        return false;

    bool right_bst(!node->right || node->data < node->right->data && is_bst(node->right));
    return right_bst;
}

template <class type>
void AVL_Tree<type>::verify()
{
    assert(abs(root->balance_factor()) <= 1);
    assert(is_bst(root));
}

template <class type>
void AVL_Tree<type>::print_in_order_node(AVL_Node<type> *node)
{
    if (!node)
        return;
    print_in_order_node(node->left);
    cout << node->data << ' ';
    print_in_order_node(node->right);
}

template <class type>
void AVL_Tree<type>::insert_value(type val)
{
    if (!root)
        root = new AVL_Node<type>(val);
    else
        root = insert_node(val, root);
    verify();
}

template <class type>
bool AVL_Tree<type>::search(type val)
{
    return search_node(val, root);
}

template <class type>
void AVL_Tree<type>::print_in_order()
{
    print_in_order_node(root);
}
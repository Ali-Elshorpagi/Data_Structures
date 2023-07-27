#ifndef AVL_TREE_V2_CPP
#define AVL_TREE_V2_CPP

#include "../header/AVL_Tree_v2.h"

template <class type>
AVL_Tree_v2<type>::AVL_Tree_v2(type data) : data(data) {}

template <class type>
AVL_Tree_v2<type>::~AVL_Tree_v2()
{
    clear();
}

template <class type>
void AVL_Tree_v2<type>::clear()
{
    if (left)
        delete left, left = nullptr;
    if (right)
        delete right, left = right;
}

template <class type>
int AVL_Tree_v2<type>::ch_height(AVL_Tree_v2<type> *node)
{
    if (!node)
        return -1;
    return node->height;
}

template <class type>
int AVL_Tree_v2<type>::update_height()
{
    return height = 1 + std::max(ch_height(left), ch_height(right));
}

template <class type>
int AVL_Tree_v2<type>::balance_factor()
{
    return ch_height(left) - ch_height(right);
}

template <class type>
AVL_Tree_v2<type> *AVL_Tree_v2<type>::right_rotation(AVL_Tree_v2<type> *Q)
{
    // std::cout << "right_rotation " << Q->data << edl;
    AVL_Tree_v2<type> *P(Q->left);
    Q->left = P->right;
    P->right = Q;
    Q->update_height();
    P->update_height();
    return P;
}

template <class type>
AVL_Tree_v2<type> *AVL_Tree_v2<type>::left_rotation(AVL_Tree_v2<type> *P)
{
    // std::cout << "left_rotation " << P->data << edl;
    AVL_Tree_v2<type> *Q(P->right);
    P->right = Q->left;
    Q->left = P;
    P->update_height();
    Q->update_height();
    return Q;
}

template <class type>
AVL_Tree_v2<type> *AVL_Tree_v2<type>::balance(AVL_Tree_v2<type> *node)
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
AVL_Tree_v2<type> *AVL_Tree_v2<type>::min_node()
{
    AVL_Tree_v2<type> *cur(this);
    while (cur && cur->left)
        cur = cur->left;
    return cur;
}

template <class type>
AVL_Tree_v2<type> *AVL_Tree_v2<type>::max_node()
{
    AVL_Tree_v2<type> *cur(this);
    while (cur && cur->right)
        cur = cur->right;
    return cur;
}

template <class type>
void AVL_Tree_v2<type>::special_delete(AVL_Tree_v2<type> *child)
{
    data = child->data;
    left = child->left;
    right = child->right;
    delete child;
}

template <class type>
AVL_Tree_v2<type> *AVL_Tree_v2<type>::delete_node(type val, AVL_Tree_v2<type> *node)
{
    if (!node)
        return nullptr;
    if (val < node->data)
        node->left = delete_node(val, node->left);
    else if (val > node->data)
        node->right = delete_node(val, node->right);
    else
    {
        if (!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }
        else if (!node->right)                // case 2: has left only
            node->special_delete(node->left); // connect with child
        else if (!node->left)                 // case 2: has right only
            node->special_delete(node->right);
        else
        {
            AVL_Tree_v2<type> *mn(node->right->min_node());
            node->data = mn->data;
            node->right = delete_node(node->data, node->right);
        }
    }
    if (node)
    {
        node->update_height();
        node = balance(node);
    }
    return node;
}

template <class type>
void AVL_Tree_v2<type>::re_root(AVL_Tree_v2<type> *node)
{
    if (node == this)
        return;

    std::swap(this->data, node->data);
    std::swap(this->height, node->height);

    if (this == node->left)
    {
        std::swap(node->right, this->right);
        node->left = this->left;
        this->left = node;
    }
    else if (this == node->right)
    {
        std::swap(node->left, this->left);
        node->right = this->right;
        this->right = node;
    }
}

template <class type>
void AVL_Tree_v2<type>::level_order_traversal()
{
    std::queue<AVL_Tree_v2<type> *> nodes_queue;
    nodes_queue.push(this);
    int level(0);
    while (!nodes_queue.empty())
    {
        int sze(nodes_queue.size());
        std::cout << "Level " << level << ": ";
        while (sze--)
        {
            AVL_Tree_v2<type> *cur(nodes_queue.front());
            nodes_queue.pop();
            std::cout << cur->data << " ";
            if (cur->left)
                nodes_queue.push(cur->left);
            if (cur->right)
                nodes_queue.push(cur->right);
        }
        ++level;
        std::cout << edl;
    }
}

template <class type>
void AVL_Tree_v2<type>::insert(type val)
{
    if (val < data)
    {
        if (!left)
            left = new AVL_Tree_v2<type>(val);
        else
            left->insert(val);
    }
    else if (val > data)
    {
        if (!right)
            right = new AVL_Tree_v2<type>(val);
        else
            right->insert(val);
    }
    update_height();
    re_root(balance(this));
}

template <class type>
void AVL_Tree_v2<type>::delete_value(type val)
{
    if (val == data && !left && !right)
        return; // can't remove root in this structure
    re_root(delete_node(val, this));
}

template <class type>
bool AVL_Tree_v2<type>::is_bst()
{
    bool left_bst(!left || data > left->data && left->is_bst());

    if (!left_bst)
        return false;

    bool right_bst(!right || data < right->data && right->is_bst());
    return right_bst;
}

template <class type>
void AVL_Tree_v2<type>::verify()
{
    assert(abs(balance_factor()) < 2);
    assert(is_bst());
}

template <class type>
type AVL_Tree_v2<type>::min_value()
{
    return min_node()->data;
}

template <class type>
type AVL_Tree_v2<type>::max_value()
{
    return max_node()->data;
}

template <class type>
bool AVL_Tree_v2<type>::search(type val)
{
    AVL_Tree_v2<type> *cur(this);
    while (cur)
    {
        if (cur->data == val)
            return true;
        else if (val < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return false;
}
#endif
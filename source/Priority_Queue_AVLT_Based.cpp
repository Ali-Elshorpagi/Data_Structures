#include "..\\header\Priority_Queue_AVLT_Based.h"

template <class type>
Priority_Queue_AVLT_Based<type>::Priority_Queue_AVLT_Based() {}

template <class type>
Priority_Queue_AVLT_Based<type>::~Priority_Queue_AVLT_Based()
{
    clear(root);
}

template <class type>
void Priority_Queue_AVLT_Based<type>::clear(PQ_Node<type> *node)
{
    if (node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <class type>
bool Priority_Queue_AVLT_Based<type>::search(type target, PQ_Node<type> *node)
{
    if (!node)
        return false;
    if (target == node->priority)
        return true;
    if (target < node->priority)
        return search(target, node->left);
    return search(target, node->right);
}

template <class type>
PQ_Node<type> *Priority_Queue_AVLT_Based<type>::right_rotation(PQ_Node<type> *Q)
{
    PQ_Node<type> *P(Q->left);
    Q->left = P->right;
    P->right = Q;
    Q->update_height();
    P->update_height();
    return P;
}

template <class type>
PQ_Node<type> *Priority_Queue_AVLT_Based<type>::left_rotation(PQ_Node<type> *P)
{
    PQ_Node<type> *Q(P->right);
    P->right = Q->left;
    Q->left = P;
    P->update_height();
    Q->update_height();
    return Q;
}

template <class type>
PQ_Node<type> *Priority_Queue_AVLT_Based<type>::balance(PQ_Node<type> *node)
{
    if (node->balance_factor() == 2)
    {
        if (node->left->balance_factor() == -1)
            node->left = left_rotation(node->left);
        node = right_rotation(node);
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
PQ_Node<type> *Priority_Queue_AVLT_Based<type>::insert_node(type task_id, int priority, PQ_Node<type> *node)
{
    if (priority < node->priority)
    {
        if (!node->left)
            node->left = new PQ_Node<type>(task_id, priority);
        else
            node->left = insert_node(task_id, priority, node->left);
    }
    else if (priority > node->priority)
    {
        if (!node->right)
            node->right = new PQ_Node<type>(task_id, priority);
        else
            node->right = insert_node(task_id, priority, node->right);
    }
    else
        node->task_ids.push_back(task_id);
    node->update_height();
    return balance(node);
}

template <class type>
PQ_Node<type> *Priority_Queue_AVLT_Based<type>::min_node(PQ_Node<type> *cur)
{
    while (cur && cur->left)
        cur = cur->left;
    return cur;
}

template <class type>
PQ_Node<type> *Priority_Queue_AVLT_Based<type>::max_node(PQ_Node<type> *cur)
{
    while (cur && cur->right)
        cur = cur->right;
    return cur;
}

template <class type>
PQ_Node<type> *Priority_Queue_AVLT_Based<type>::delete_node(int priority, PQ_Node<type> *node)
{
    if (!node)
        return nullptr;
    if (priority < node->priority)
        node->left = delete_node(priority, node->left);
    else if (priority > node->priority)
        node->right = delete_node(priority, node->right);
    else
    {
        PQ_Node<type> *tmp(node);
        if (!node->left && !node->right) // case 1: no child
            node = nullptr;
        else if (!node->right) // case 2: has left only
            node = node->left; // connect with child
        else if (!node->left)  // case 2: has right only
            node = node->right;
        else // 2 children: Use successor
        {
            PQ_Node<type> *mn(min_node(node->right));
            node->priority = mn->priority; // copy & go delete
            node->right = delete_node(node->priority, node->right);
            tmp = nullptr; // Don't delete me. Successor will be deleted
        }
        if (tmp)
            delete tmp;
    }
    if (node)
    {
        node->update_height();
        node = balance(node);
    }
    return node;
}

template <class type>
void Priority_Queue_AVLT_Based<type>::enqueue(type task_id, int task_priority)
{
    if (!root)
        root = new PQ_Node<type>(task_id, task_priority);
    else
        root = insert_node(task_id, task_priority, root);
}

template <class type>
type Priority_Queue_AVLT_Based<type>::dequeue()
{
    assert(!is_empty());
    PQ_Node<type> *mx(max_node(root));
    assert(mx->task_ids.size() > 0);
    type ret(mx->task_ids.back());
    mx->task_ids.pop_back();
    if (mx->task_ids.size() == 0)
        root = delete_node(mx->priority, root);

    return ret;
}

template <class type>
bool Priority_Queue_AVLT_Based<type>::is_empty()
{
    return root == nullptr;
}
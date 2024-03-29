#ifndef SPARSE_ARRAY_CPP
#define SPARSE_ARRAY_CPP

#include "../header/Sparse_Array.h"

template <class type>
Sparse_Array<type>::Sparse_Array(int cols) : cols(cols)
{
    tail = head = new Col_Node<type>(0, -1);
    ++length;
}

template <class type>
Sparse_Array<type>::~Sparse_Array()
{
    while (head)
    {
        Col_Node<type> *current(head->next);
        delete head;
        head = current;
    }
    head = tail = nullptr;
}

template <class type>
void Sparse_Array<type>::link(Col_Node<type> *first, Col_Node<type> *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

template <class type>
Col_Node<type> *Sparse_Array<type>::add_node_between_node_and_next(Col_Node<type> *node_before, type data, int col)
{
    Col_Node<type> *middle(new Col_Node<type>(data, col));
    ++length;
    Col_Node<type> *node_after(node_before->next);
    link(node_before, middle);
    if (!node_after)
        tail = middle;
    else
        link(middle, node_after);
    return middle;
}

template <class type>
Col_Node<type> *Sparse_Array<type>::get_col(int col, bool is_create_if_missing)
{
    Col_Node<type> *prev_col(head);
    while (prev_col->next && prev_col->next->col < col)
        prev_col = prev_col->next;
    bool found(prev_col->next && (prev_col->next->col == col));
    if (found)
        return prev_col->next;
    if (!is_create_if_missing)
        return nullptr;
    return add_node_between_node_and_next(prev_col, 0, col);
}

template <class type>
void Sparse_Array<type>::print_row()
{
    Col_Node<type> *cur(head->next);
    for (int c(0); c < cols; ++c)
    {
        if (cur && cur->col == c)
        {
            std::cout << cur->data << ' ';
            cur = cur->next;
        }
        else
            std::cout << "0 ";
    }
    std::cout << edl;
}

template <class type>
void Sparse_Array<type>::print_row_nonzero()
{
    for (Col_Node<type> *cur(head->next); cur; cur = cur->next)
        std::cout << cur->data << ' ';
    std::cout << edl;
}

template <class type>
void Sparse_Array<type>::set_value(type data, int col)
{
    get_col(col, true)->data = data;
}

template <class type>
type Sparse_Array<type>::get_value(int col)
{
    Col_Node<type> *node(get_col(col, false));
    if (!node)
        return 0;
    return node->data;
}

template <class type>
void Sparse_Array<type>::add(Sparse_Array<type> &other)
{
    assert(cols == other.cols);
    for (Col_Node<type> *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
    {
        Col_Node<type> *this_col(get_col(other_cur->col, true));
        this_col->data += other_cur->data;
    }
}
#endif
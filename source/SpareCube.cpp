#include "..\\header\SpareCube.h"

template <class type>
SpareCube<type>::SpareCube(int row, int col, int depth) : rows(row), cols(col), depths(depth)
{
    tail = head = Depth_Node<type>(0, 0, -1);
    ++length;
}

template <class type>
SpareCube<type>::~SpareCube()
{
    for (Depth_Node<type> *cur(head->next); cur; cur = cur->next)
        cur->matrix->list.~SpareArray();
}

template <class type>
Depth_Node<type> *SpareCube<type>::get_depth(ll depth, bool flag)
{
    Depth_Node<type> *prev_row(head);
    while (prev_row->next && prev_row->next->row < depth)
        prev_row = prev_row->next;
    bool found(prev_row->next && (prev_row->next->row == depth));
    if (found)
        return prev_row->next;
    if (!flag)
        return nullptr;
    return add_node_between_node_and_next(prev_row, depth);
}

template <class type>
void SpareCube<type>::link(Depth_Node<type> *first, Depth_Node<type> *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

template <class type>
Depth_Node<type> *SpareCube<type>::add_node_between_node_and_next(Depth_Node<type> *node_before, ll depth)
{
    Depth_Node<type> *middle(new Depth_Node<type>(depth, rows));
    ++length;
    Depth_Node<type> *node_after(node_before->next);
    link(node_before, middle);
    if (!node_after)
        tail = middle;
    else
        link(middle, node_after);
    return middle;
}

template <class type>
void SpareCube<type>::set_value(type data, int row, int col, int depth)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    assert(0 <= depth && depth < depths);
    Depth_Node<type> *item(get_depth(depth, true));
    item->matrix.set_value(data, row);
}

template <class type>
type SpareCube<type>::get_value(int row, int col, int depth)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    assert(0 <= depth && depth < depths);
    Depth_Node<type> *item(get_depth(depth, false));
    if (!item)
        return 0;
    return item->matrix.get_value(row, col);
}

template <class type>
void SpareCube<type>::print_cube() {}

template <class type>
void SpareCube<type>::print_cube_nonzero() {}

template <class type>
void SpareCube<type>::add(SpareCube<type> &other) {}
#include "..\\header\Spare_Cube.h"

template <class type>
Spare_Cube<type>::Spare_Cube(int row, int col, int depth) : rows(row), cols(col), depths(depth)
{
    tail = head = new Depth_Node<type>(0, 0, -1);
    ++length;
}

template <class type>
Spare_Cube<type>::~Spare_Cube()
{
    for (Depth_Node<type> *cur(head->next); cur; cur = cur->next)
        cur->matrix.~SparseMatrix();
}

template <class type>
Depth_Node<type> *Spare_Cube<type>::get_depth(int depth, bool flag)
{
    Depth_Node<type> *prev_row(head);
    while (prev_row->next && prev_row->next->depth < depth)
        prev_row = prev_row->next;
    bool found(prev_row->next && (prev_row->next->depth == depth));
    if (found)
        return prev_row->next;
    if (!flag)
        return nullptr;
    return add_node_between_node_and_next(prev_row, depth);
}

template <class type>
void Spare_Cube<type>::link(Depth_Node<type> *first, Depth_Node<type> *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

template <class type>
Depth_Node<type> *Spare_Cube<type>::add_node_between_node_and_next(Depth_Node<type> *node_before, int depth)
{
    Depth_Node<type> *middle(new Depth_Node<type>(depth, rows, cols));
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
void Spare_Cube<type>::set_value(type data, int row, int col, int depth)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    assert(0 <= depth && depth < depths);
    Depth_Node<type> *item(get_depth(depth, true));
    item->matrix.set_value(data, row, col);
}

template <class type>
type Spare_Cube<type>::get_value(int row, int col, int depth)
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
void Spare_Cube<type>::add(Spare_Cube<type> &other)
{
    assert(depths == other.depths && rows == other.rows && cols == other.cols);
    for (Depth_Node<type> *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
    {
        Depth_Node<type> *this_depth(get_depth(other_cur->depth, true));
        this_depth->matrix.add(other_cur->matrix);
    }
}

template <class type>
void Spare_Cube<type>::print_cube()
{
    cout << edl << "Print Cube: " << rows << " x " << cols << " x " << depths << edl;

    Depth_Node<type> *cur(head->next);
    for (int i(0); i < depths; ++i)
    {
        if (cur && cur->depth == i)
        {
            cur->matrix.print_matrix();
            cur = cur->next;
        }
        else
        {
            for (int j(0); j < rows; ++j)
                cout << "0 ";
            cout << edl;
        }
    }
}

template <class type>
void Spare_Cube<type>::print_cube_nonzero()
{
    cout << edl << "Print Cube: " << rows << " x " << cols << " x " << depths << edl;
    for (Depth_Node<type> *cur(head->next); cur; cur = cur->next)
        cur->matrix.print_matrix_nonzero();
}

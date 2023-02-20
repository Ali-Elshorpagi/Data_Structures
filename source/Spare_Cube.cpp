#include "..\\header\Spare_Cube.h"

template <class type>
Spare_Cube<type>::Spare_Cube(int row, int col, int height) : rows(row), cols(col), heights(height)
{
    tail = head = new Height_Node<type>(0, 0, -1);
    ++length;
}

template <class type>
Spare_Cube<type>::~Spare_Cube()
{
    for (Height_Node<type> *cur(head->next); cur; cur = cur->next)
        cur->matrix.~SparseMatrix();
}

template <class type>
Height_Node<type> *Spare_Cube<type>::get_height(int height, bool flag)
{
    Height_Node<type> *prev_row(head);
    while (prev_row->next && prev_row->next->height < height)
        prev_row = prev_row->next;
    bool found(prev_row->next && (prev_row->next->height == height));
    if (found)
        return prev_row->next;
    if (!flag)
        return nullptr;
    return add_node_between_node_and_next(prev_row, height);
}

template <class type>
void Spare_Cube<type>::link(Height_Node<type> *first, Height_Node<type> *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

template <class type>
Height_Node<type> *Spare_Cube<type>::add_node_between_node_and_next(Height_Node<type> *node_before, int height)
{
    Height_Node<type> *middle(new Height_Node<type>(height, rows, cols));
    ++length;
    Height_Node<type> *node_after(node_before->next);
    link(node_before, middle);
    if (!node_after)
        tail = middle;
    else
        link(middle, node_after);
    return middle;
}

template <class type>
void Spare_Cube<type>::set_value(type data, int row, int col, int height)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    assert(0 <= height && height < heights);
    Height_Node<type> *item(get_height(height, true));
    item->matrix.set_value(data, row, col);
}

template <class type>
type Spare_Cube<type>::get_value(int row, int col, int height)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    assert(0 <= height && height < heights);
    Height_Node<type> *item(get_height(height, false));
    if (!item)
        return 0;
    return item->matrix.get_value(row, col);
}

template <class type>
void Spare_Cube<type>::add(Spare_Cube<type> &other)
{
    assert(heights == other.heights && rows == other.rows && cols == other.cols);
    for (Height_Node<type> *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
    {
        Height_Node<type> *this_height(get_height(other_cur->height, true));
        this_height->matrix.add(other_cur->matrix);
    }
}

template <class type>
void Spare_Cube<type>::print_cube()
{
    cout << edl << "Print Cube: " << rows << " x " << cols << " x " << heights << edl;

    Height_Node<type> *cur(head->next);
    for (int i(0); i < heights; ++i)
    {
        if (cur && cur->height == i)
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
    cout << edl << "Print Cube: " << rows << " x " << cols << " x " << heights << edl;
    for (Height_Node<type> *cur(head->next); cur; cur = cur->next)
        cur->matrix.print_matrix_nonzero();
}

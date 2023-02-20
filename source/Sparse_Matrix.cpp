#include "..\\header\Sparse_Matrix.h"

template <class type>
Sparse_Matrix<type>::Sparse_Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    tail = head = new Row_Node<type>(-1, cols);
    ++length;
}

template <class type>
Sparse_Matrix<type>::~Sparse_Matrix()
{
    for (Row_Node<type> *cur(head->next); cur; cur = cur->next)
        cur->list.~Spare_Array();
}

template <class type>
Row_Node<type> *Sparse_Matrix<type>::get_row(int row, bool flag)
{
    Row_Node<type> *prev_row(head);
    while (prev_row->next && prev_row->next->row < row)
        prev_row = prev_row->next;
    bool found(prev_row->next && (prev_row->next->row == row));
    if (found)
        return prev_row->next;
    if (!flag)
        return nullptr;
    return add_node_between_node_and_next(prev_row, row);
}

template <class type>
void Sparse_Matrix<type>::link(Row_Node<type> *first, Row_Node<type> *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

template <class type>
Row_Node<type> *Sparse_Matrix<type>::add_node_between_node_and_next(Row_Node<type> *node_before, int row)
{
    Row_Node<type> *middle(new Row_Node<type>(row, cols));
    ++length;
    Row_Node<type> *node_after(node_before->next);
    link(node_before, middle);
    if (!node_after)
        tail = middle;
    else
        link(middle, node_after);
    return middle;
}

template <class type>
void Sparse_Matrix<type>::set_value(type data, int row, int col)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    Row_Node<type> *item(get_row(row, true));
    item->list.set_value(data, col);
}

template <class type>
type Sparse_Matrix<type>::get_value(int row, int col)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    Row_Node<type> *item(get_row(row, false));
    if (!item)
        return 0;
    return item->list.get_col(col);
}

template <class type>
void Sparse_Matrix<type>::add(Sparse_Matrix<type> &other)
{
    assert(rows == other.rows && cols == other.cols);
    for (Row_Node<type> *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
    {
        Row_Node<type> *this_row(get_row(other_cur->row, true));
        this_row->list.add(other_cur->list);
    }
}

template <class type>
void Sparse_Matrix<type>::print_matrix()
{
    cout << edl << "Print Matrix: " << rows << " x " << cols << edl;
    Row_Node<type> *cur(head->next);
    for (int i(0); i < rows; ++i)
    {
        if (cur && cur->row == i)
        {
            cur->list.print_row();
            cur = cur->next;
        }
        else
        {
            for (int j(0); j < cols; ++j)
                cout << "0 ";
            cout << edl;
        }
    }
}

template <class type>
void Sparse_Matrix<type>::print_matrix_nonzero()
{
    cout << edl << "Print Matrix: " << rows << " x " << cols << edl;
    for (Row_Node<type> *cur(head->next); cur; cur = cur->next)
        cur->list.print_row_nonzero();
}

#include "..\\header\SparseMatrix.h"

SparseMatrix::SparseMatrix(int rows, int cols) : rows(rows), cols(cols)
{
    tail = head = new Row_Node(-1, cols);
    ++length;
}

SparseMatrix::~SparseMatrix() {}

void SparseMatrix::link(Row_Node *first, Row_Node *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

Row_Node *SparseMatrix::embed_after(Row_Node *node_before, int row)
{
    Row_Node *middle = new Row_Node(row, cols);
    ++length;
    Row_Node *node_after(node_before->next);
    link(node_before, middle);
    if (!node_after)
        tail = middle;
    else
        link(middle, node_after);
    return middle;
}

Row_Node *SparseMatrix::get_row(int row, bool is_create_if_missing)
{
    Row_Node *prev_row(head);
    while (prev_row->next && prev_row->next->row < row)
        prev_row = prev_row->next;
    bool found = prev_row->next && prev_row->next->row == row;
    if (found)
        return prev_row->next;
    if (!is_create_if_missing)
        return nullptr;
    return embed_after(prev_row, row);
}

void SparseMatrix::set_value(int data, int row, int col)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    Row_Node *node(get_row(row, true));
    node->col_list.set_value(data, col);
}

int SparseMatrix::get_value(int row, int col)
{
    assert(0 <= row && row < rows);
    assert(0 <= col && col < cols);
    Row_Node *node(get_row(row, false));
    if (!node)
        return 0;
    return node->col_list.get_value(col);
}

void SparseMatrix::print_matrix()
{
    cout << edl << "Print Matrix: " << rows << " x " << cols << edl;
    Row_Node *cur(head->next);
    for (int r(0); r < rows; ++r)
    {
        if (cur && cur->row == r)
        {
            cur->col_list.print_row();
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
void SparseMatrix::print_matrix_nonzero()
{
    cout << edl << "Print Matrix: " << rows << " x " << cols << edl;
    for (Row_Node *cur(head->next); cur; cur = cur->next)
        cur->col_list.print_row_nonzero();
}

void SparseMatrix::add(SparseMatrix &other)
{
    assert(rows == other.rows && cols == other.cols);
    for (Row_Node *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
    {
        Row_Node *this_row = get_row(other_cur->row, true);
        this_row->col_list.add(other_cur->col_list);
    }
}
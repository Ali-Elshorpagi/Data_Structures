#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

struct Col_Node
{
    int data{};
    int column{};
    Col_Node *next{};
    Col_Node *prev{};
    Col_Node(int data, int column) : data(data), column(column) {}
};

class LinkedList
{
private:
    Col_Node *head{};
    Col_Node *tail{};
    int length = 0;
    int cols{};
    void link(Col_Node *first, Col_Node *second)
    {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }
    Col_Node *embed_after(Col_Node *node_before, int data, int col)
    {
        Col_Node *middle = new Col_Node(data, col);
        ++length;
        Col_Node *node_after = node_before->next;
        link(node_before, middle);
        if (!node_after)
            tail = middle;
        else
            link(middle, node_after);
        return middle;
    }
    Col_Node *get_col(int col, bool is_create_if_missing)
    {
        Col_Node *prev_col(head);
        while (prev_col->next && prev_col->next->column < col)
            prev_col = prev_col->next;
        bool found = prev_col->next && prev_col->next->column == col;
        if (found)
            return prev_col->next;
        if (!is_create_if_missing)
            return nullptr;
        return embed_after(prev_col, 0, col);
    }

public:
    LinkedList(int cols) : cols(cols)
    {
        tail = head = new Col_Node(0, -1);
        ++length;
    }

    void print_row()
    {
        Col_Node *cur(head->next);

        for (int c(0); c < cols; ++c)
        {
            if (cur && cur->column == c)
            {
                cout << cur->data << ' ';
                cur = cur->next;
            }
            else
                cout << "0 ";
        }
        cout << edl;
    }

    void print_row_nonzero()
    {
        for (Col_Node *cur = head->next; cur; cur = cur->next)
            cout << cur->data << ' ';
        cout << edl;
    }
    void set_value(int data, int col)
    {
        get_col(col, true)->data = data;
    }

    int get_value(int col)
    {
        Col_Node *node(get_col(col, false));
        if (!node)
            return 0;
        return node->data;
    }
    void add(LinkedList &other)
    {
        assert(cols == other.cols);
        for (Col_Node *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
        {
            Col_Node *this_col = get_col(other_cur->column, true);
            this_col->data += other_cur->data;
        }
    }
};

struct Row_Node
{
    int row{};
    LinkedList col_list;
    Row_Node *next{};
    Row_Node *prev{};
    Row_Node(int row, int cols) : row(row), col_list(cols) {}
};

class SparseMatrix
{
private:
    Row_Node *head{};
    Row_Node *tail{};
    int length = 0;
    int rows{};
    int cols{};
    void link(Row_Node *first, Row_Node *second);
    Row_Node *embed_after(Row_Node *node_before, int row);
    Row_Node *get_row(int row, bool is_create_if_missing);

public:
    SparseMatrix(int rows, int cols);
    ~SparseMatrix();
    void set_value(int data, int row, int col);
    int get_value(int row, int col);
    void print_matrix();
    void print_matrix_nonzero();
    void add(SparseMatrix &other);
};
